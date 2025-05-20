//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define POP3_PORT 110

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_command(int sockfd, const char *cmd, char *response) {
    send(sockfd, cmd, strlen(cmd), 0);
    printf(">> %s", cmd);
    recv(sockfd, response, BUFFER_SIZE - 1, 0);
    printf("<< %s", response);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("Socket creation failed");

    // Fill server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    // Connect to server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
        error("Connection failed");

    // Initial server greeting
    recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    printf("<< %s", buffer);

    // Authenticate
    char cmd[BUFFER_SIZE];
    snprintf(cmd, sizeof(cmd), "USER %s\r\n", username);
    send_command(sockfd, cmd, buffer);

    snprintf(cmd, sizeof(cmd), "PASS %s\r\n", password);
    send_command(sockfd, cmd, buffer);

    // Retrieve message count
    send_command(sockfd, "STAT\r\n", buffer);
    int msg_count;
    sscanf(buffer, "+OK %d", &msg_count);
    printf("Total Messages: %d\n", msg_count);

    // Fetch all messages
    for (int i = 1; i <= msg_count; i++) {
        snprintf(cmd, sizeof(cmd), "RETR %d\r\n", i);
        send_command(sockfd, cmd, buffer);

        // Print the message
        printf("Message %d:\n%s\n", i, buffer);
    }

    // Logout
    send_command(sockfd, "QUIT\r\n", buffer);

    // Clean up
    close(sockfd);
    return 0;
}