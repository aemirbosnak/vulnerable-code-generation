//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 110

void handle_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void send_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
    printf("Sent: %s", command);
}

void read_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        handle_error("recv failed");
    }
    buffer[bytes_received] = '\0'; // null-terminate the string
    printf("Received: %s\n", buffer);
}

void list_messages(int sockfd) {
    send_command(sockfd, "LIST\r\n");
    read_response(sockfd);
}

void retrieve_message(int sockfd, int message_number) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "RETR %d\r\n", message_number);
    send_command(sockfd, command);
    read_response(sockfd);
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char server_ip[20], username[50], password[50];
    
    printf("Enter POP3 server IP: ");
    scanf("%s", server_ip);
    printf("Enter Username: ");
    scanf("%s", username);
    printf("Enter Password: ");
    scanf("%s", password);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        handle_error("Could not create socket");
    }

    // Set up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        handle_error("Invalid address or Address not supported");
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Connection to server failed");
    }

    // Read server greeting
    read_response(sockfd);

    // Authenticate
    char auth_command[BUFFER_SIZE];
    snprintf(auth_command, sizeof(auth_command), "USER %s\r\n", username);
    send_command(sockfd, auth_command);
    read_response(sockfd);
    
    snprintf(auth_command, sizeof(auth_command), "PASS %s\r\n", password);
    send_command(sockfd, auth_command);
    read_response(sockfd);

    // List messages
    list_messages(sockfd);

    // Retrieve messages
    int message_count = 3; // Change to actual message count based on response
    for (int i = 1; i <= message_count; i++) {
        retrieve_message(sockfd, i);
    }

    // Quit
    send_command(sockfd, "QUIT\r\n");
    read_response(sockfd);

    // Close socket
    close(sockfd);
    return 0;
}