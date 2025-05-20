//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_PORT 110
#define BUFFER_SIZE 1024

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void connect_to_pop3_server(const char *server_ip) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        handle_error("Socket creation failed");
    }

    // Configure server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);

    // Convert IP addresses from text to binary form
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        handle_error("Invalid address/ Address not supported");
    }

    // Connect to POP3 server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Connection failed");
    }

    // Read server's greeting
    read(sockfd, buffer, BUFFER_SIZE);
    printf("Server: %s", buffer);

    // User authentication
    char username[50], password[50];
    
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    
    // Send USER command
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send(sockfd, command, strlen(command), 0);
    read(sockfd, buffer, BUFFER_SIZE);
    printf("Server: %s", buffer);

    // Send PASS command
    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send(sockfd, command, strlen(command), 0);
    read(sockfd, buffer, BUFFER_SIZE);
    printf("Server: %s", buffer);

    // Fetch mail statistics
    send(sockfd, "STAT\r\n", 7, 0);
    read(sockfd, buffer, BUFFER_SIZE);
    printf("Server: %s", buffer);

    // Retrieve a specific email
    int email_num;
    printf("Enter email number to retrieve: ");
    scanf("%d", &email_num);
    snprintf(command, sizeof(command), "RETR %d\r\n", email_num);
    send(sockfd, command, strlen(command), 0);
    read(sockfd, buffer, BUFFER_SIZE);
    printf("Server: %s", buffer);

    // End session
    send(sockfd, "QUIT\r\n", 7, 0);
    read(sockfd, buffer, BUFFER_SIZE);
    printf("Server: %s", buffer);

    // Close the socket
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <POP3 Server IP>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    connect_to_pop3_server(argv[1]);

    return 0;
}