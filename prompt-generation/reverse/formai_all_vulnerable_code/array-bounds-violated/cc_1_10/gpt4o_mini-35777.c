//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

void send_command(int sockfd, const char *command) {
    // Function to send a command to the POP3 server
    send(sockfd, command, strlen(command), 0);
    printf("Sent: %s", command);
}

void receive_response(int sockfd) {
    // Function to receive response from the POP3 server
    char buffer[BUFFER_SIZE] = {0};
    int bytes_received;

    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0'; // Null terminate buffer
        printf("Received: %s", buffer);
        if (strstr(buffer, "+OK") != NULL) {
            break;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *server = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    // Define server address
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(110); // POP3 default port

    // Convert server address to binary
    if (inet_pton(AF_INET, server, &serv_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection to the server failed");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Receive server's greeting
    receive_response(sockfd);

    // Send USER command
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send_command(sockfd, command);
    receive_response(sockfd);

    // Send PASS command
    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send_command(sockfd, command);
    receive_response(sockfd);

    // Send STAT command to get number of messages
    send_command(sockfd, "STAT\r\n");
    receive_response(sockfd);

    // Send LIST command to list message IDs
    send_command(sockfd, "LIST\r\n");
    receive_response(sockfd);

    // Send QUIT command to close the connection
    send_command(sockfd, "QUIT\r\n");
    receive_response(sockfd);

    // Clean up
    close(sockfd);
    return EXIT_SUCCESS;
}