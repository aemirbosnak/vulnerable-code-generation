//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SERVER_PORT 110
#define BUFFER_SIZE 512

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_command(int sockfd, const char *cmd) {
    send(sockfd, cmd, strlen(cmd), 0);
    char buffer[BUFFER_SIZE];
    recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    buffer[BUFFER_SIZE - 1] = '\0'; // Ensure null termination
    printf("%s", buffer);
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char *server_ip = "your.pop3.server"; // Replace with your POP3 server IP
    char user[50], pass[50];

    // Get user credentials
    printf("Enter your email username: ");
    fgets(user, sizeof(user), stdin);
    user[strcspn(user, "\n")] = 0; // Remove newline

    printf("Enter your email password: ");
    fgets(pass, sizeof(pass), stdin);
    pass[strcspn(pass, "\n")] = 0; // Remove newline

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    // Set up the server address struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        error("Invalid address/ Address not supported");
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection failed");
    }
    
    // Welcome message
    char buffer[BUFFER_SIZE];
    recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    buffer[BUFFER_SIZE - 1] = '\0'; // Null termination
    printf("%s", buffer);

    // Authenticate user
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "USER %s\r\n", user);
    send_command(sockfd, command);

    snprintf(command, sizeof(command), "PASS %s\r\n", pass);
    send_command(sockfd, command);

    // List messages
    send_command(sockfd, "LIST\r\n");

    // Retrieve a message
    printf("Enter the message number you want to retrieve: ");
    int msg_num;
    scanf("%d", &msg_num);
    
    snprintf(command, sizeof(command), "RETR %d\r\n", msg_num);
    send_command(sockfd, command);

    // Cleanup
    send_command(sockfd, "QUIT\r\n");
    close(sockfd);
    return 0;
}