//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>

#define POP3_PORT 110
#define MAX_LINE 512

void error_exit(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_command(int sockfd, const char *cmd) {
    if (send(sockfd, cmd, strlen(cmd), 0) < 0) {
        error_exit("Failed to send command");
    }
}

void receive_response(int sockfd) {
    char buffer[MAX_LINE];
    int bytes_received;

    memset(buffer, 0, sizeof(buffer)); // Clear the buffer
    bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        error_exit("Failed to receive response");
    }
    buffer[bytes_received] = '\0'; // Null-terminate the string
    printf("Response: %s", buffer);
}

void authenticate_user(int sockfd, const char *username, const char *password) {
    char command[MAX_LINE];

    // Send USER command
    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send_command(sockfd, command);
    receive_response(sockfd);

    // Send PASS command
    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send_command(sockfd, command);
    receive_response(sockfd);
}

void list_messages(int sockfd) {
    char command[MAX_LINE];

    // Send LIST command
    snprintf(command, sizeof(command), "LIST\r\n");
    send_command(sockfd, command);
    receive_response(sockfd);
}

void retrieve_message(int sockfd, int message_number) {
    char command[MAX_LINE];

    // Send RETR command
    snprintf(command, sizeof(command), "RETR %d\r\n", message_number);
    send_command(sockfd, command);
    receive_response(sockfd);
}

void delete_message(int sockfd, int message_number) {
    char command[MAX_LINE];

    // Send DELE command
    snprintf(command, sizeof(command), "DELE %d\r\n", message_number);
    send_command(sockfd, command);
    receive_response(sockfd);
}

void quit_pop3(int sockfd) {
    send_command(sockfd, "QUIT\r\n");
    receive_response(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server_ip> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *server_ip = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error_exit("Socket creation failed");
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        error_exit("Invalid address/Address not supported");
    }

    // Connect to POP3 server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error_exit("Connection to server failed");
    }

    // Receive welcome message
    receive_response(sockfd);

    // Authenticate user
    authenticate_user(sockfd, username, password);

    // List messages
    printf("\nListing messages:\n");
    list_messages(sockfd);

    // Retrieve the first message as an example
    printf("\nRetrieving message 1:\n");
    retrieve_message(sockfd, 1);

    // Delete the first message as an example
    printf("\nDeleting message 1:\n");
    delete_message(sockfd, 1);

    // Quit the POP3 session
    quit_pop3(sockfd);

    // Close the socket
    close(sockfd);
    return EXIT_SUCCESS;
}