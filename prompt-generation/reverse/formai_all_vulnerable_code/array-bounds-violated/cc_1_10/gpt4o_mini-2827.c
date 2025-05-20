//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 110
#define BUFFER_SIZE 1024

void pop3_send(int sockfd, const char *cmd) {
    send(sockfd, cmd, strlen(cmd), 0);
}

void pop3_receive(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_read] = '\0';
        printf("%s", buffer);
        if (strstr(buffer, "+OK") || strstr(buffer, "-ERR")) {
            break;  // Response finished
        }
    }
}

void pop3_retrieve_email(int sockfd) {
    char cmd[BUFFER_SIZE];
    snprintf(cmd, sizeof(cmd), "LIST\r\n");
    pop3_send(sockfd, cmd);
    pop3_receive(sockfd);
    
    // Continue with some more commands if needed like RETR, etc.
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
    char cmd[BUFFER_SIZE];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Unable to create socket");
        exit(EXIT_FAILURE);
    }

    // Setup server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Receive server greeting
    pop3_receive(sockfd);
    
    // Authentication
    snprintf(cmd, sizeof(cmd), "USER %s\r\n", username);
    pop3_send(sockfd, cmd);
    pop3_receive(sockfd);

    snprintf(cmd, sizeof(cmd), "PASS %s\r\n", password);
    pop3_send(sockfd, cmd);
    pop3_receive(sockfd);

    // Retrieve emails
    printf("\nRetrieving emails:\n");
    pop3_retrieve_email(sockfd);

    // Logout
    snprintf(cmd, sizeof(cmd), "QUIT\r\n");
    pop3_send(sockfd, cmd);
    pop3_receive(sockfd);
    
    // Cleanup
    close(sockfd);
    return 0;
}