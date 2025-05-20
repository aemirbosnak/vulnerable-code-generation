//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define POP3_PORT 110

void send_command(int sockfd, const char *cmd) {
    // Sending command to the server
    write(sockfd, cmd, strlen(cmd));
    write(sockfd, "\r\n", 2);
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_read;

    // Reading response from the server
    while ((bytes_read = read(sockfd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes_read] = '\0'; // null-terminate
        printf("%s", buffer);

        // Exit condition
        if (strstr(buffer, "+OK") != NULL) {
            break;
        }
    }
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char cmd[BUFFER_SIZE];
    char username[50], password[50];

    // Input username and password
    printf("Enter your POP3 username: ");
    scanf("%s", username);
    printf("Enter your POP3 password: ");
    scanf("%s", password);

    // Creating socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setting up server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Localhost, change as needed

    // Connecting to the POP3 server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Receiving server greeting
    receive_response(sockfd);

    // Logging in
    snprintf(cmd, sizeof(cmd), "USER %s", username);
    send_command(sockfd, cmd);
    receive_response(sockfd);

    snprintf(cmd, sizeof(cmd), "PASS %s", password);
    send_command(sockfd, cmd);
    receive_response(sockfd);

    // Listing messages
    send_command(sockfd, "LIST");
    receive_response(sockfd);

    // Retrieving first message (you can modify to get other messages)
    send_command(sockfd, "RETR 1");
    receive_response(sockfd);

    // Logging out
    send_command(sockfd, "QUIT");
    receive_response(sockfd);

    // Closing the socket
    close(sockfd);
    return 0;
}