//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER "pop.yourmailserver.com"  // Replace with your POP3 server
#define PORT 110
#define BUFFER_SIZE 512

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void pop3_send_command(int sockfd, const char *cmd) {
    if (send(sockfd, cmd, strlen(cmd), 0) < 0) {
        error("Failed to send command");
    }
}

void pop3_receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        error("Failed to receive response");
    }

    buffer[bytes_received] = '\0'; // null-terminate the received string
    printf("%s", buffer);
}

void pop3_authenticate(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "USER %s\r\n", username);
    pop3_send_command(sockfd, command);
    pop3_receive_response(sockfd);

    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    pop3_send_command(sockfd, command);
    pop3_receive_response(sockfd);
}

void pop3_list_messages(int sockfd) {
    pop3_send_command(sockfd, "LIST\r\n");
    pop3_receive_response(sockfd);
}

void pop3_retrieve_message(int sockfd, int msg_number) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "RETR %d\r\n", msg_number);
    pop3_send_command(sockfd, command);
    pop3_receive_response(sockfd);
}

void pop3_disconnect(int sockfd) {
    pop3_send_command(sockfd, "QUIT\r\n");
    pop3_receive_response(sockfd);
    close(sockfd);
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Unable to create socket");
    }

    // Setup server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    
    // Convert IPv4 address from text to binary form
    if (inet_pton(AF_INET, SERVER, &server_addr.sin_addr) <= 0) {
        error("Invalid address or address not supported");
    }

    // Connect to POP3 server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection failed");
    }

    // Receive server greeting
    pop3_receive_response(sockfd);

    // User authentication
    const char *username = "your_username"; // Replace with your username
    const char *password = "your_password"; // Replace with your password
    pop3_authenticate(sockfd, username, password);

    // List messages
    pop3_list_messages(sockfd);

    // Retrieve a specific message (e.g., first message)
    printf("\nRetrieving the first message:\n");
    pop3_retrieve_message(sockfd, 1);

    // Disconnect from server
    pop3_disconnect(sockfd);

    return 0;
}