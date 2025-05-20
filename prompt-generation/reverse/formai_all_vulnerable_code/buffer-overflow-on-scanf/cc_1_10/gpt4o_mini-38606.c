//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER "pop.gmail.com"
#define PORT 995
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void send_command(int sockfd, const char *cmd) {
    send(sockfd, cmd, strlen(cmd), 0);
    send(sockfd, "\r\n", 2, 0); // POP3 requires CRLF
}

void read_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (n < 0) error("Error reading from socket");
    buffer[n] = '\0';
    printf("Server Response: %s", buffer);
}

int main() {
    int sockfd;
    struct sockaddr_in serv_addr;
    char command[256];
    char username[128], password[128];

    // Socket creation
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("Error opening socket");

    // Set socket address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr(SERVER);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("Connection failed");

    // Read server greeting
    read_response(sockfd);

    // User authentication
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    // Send USER command
    sprintf(command, "USER %s", username);
    send_command(sockfd, command);
    read_response(sockfd);

    // Send PASS command
    sprintf(command, "PASS %s", password);
    send_command(sockfd, command);
    read_response(sockfd);

    // Enter the command loop
    while (1) {
        printf("Enter POP3 command (LIST, RETR <msg_num>, QUIT): ");
        scanf("%s", command);

        // Process LIST command
        if (strcmp(command, "LIST") == 0) {
            send_command(sockfd, "LIST");
            read_response(sockfd);
        }
        // Process RETR command
        else if (strncmp(command, "RETR", 4) == 0) {
            send_command(sockfd, command);
            read_response(sockfd);
        }
        // Process QUIT command
        else if (strcmp(command, "QUIT") == 0) {
            send_command(sockfd, "QUIT");
            read_response(sockfd);
            break; // Exit the loop
        } else {
            printf("Unknown command. Try LIST, RETR <msg_num>, or QUIT.\n");
        }
    }

    // Clean up and close socket
    close(sockfd);
    return 0;
}