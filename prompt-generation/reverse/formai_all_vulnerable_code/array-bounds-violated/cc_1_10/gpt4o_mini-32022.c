//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_BUFFER 1024
#define PORT 110

void print_welcome_message() {
    printf("\n-----------------------------------\n");
    printf(" Welcome to the POP3 Client\n");
    printf("-----------------------------------\n");
}

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int receive_response(int sockfd) {
    char buffer[MAX_BUFFER];
    int bytes = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (bytes < 0) {
        error("Error receiving data");
    }
    buffer[bytes] = '\0'; // Null-terminate the buffer
    printf("%s", buffer); // Print the server response
    return bytes;
}

void send_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
    printf("Sent: %s", command);
    receive_response(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <username>\n", argv[0]);
        return 1;
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    char password[50];

    print_welcome_message();

    // Prompt for password
    printf("Enter password for %s: ", username);
    fgets(password, 50, stdin);
    password[strcspn(password, "\n")] = 0; // remove newline

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        error("Invalid address/ Address not supported");
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection failed");
    }

    receive_response(sockfd); // Welcome message from POP3 server

    // User command
    char user_command[MAX_BUFFER];
    snprintf(user_command, sizeof(user_command), "USER %s\r\n", username);
    send_command(sockfd, user_command);

    // Pass command
    char pass_command[MAX_BUFFER];
    snprintf(pass_command, sizeof(pass_command), "PASS %s\r\n", password);
    send_command(sockfd, pass_command);

    // List messages
    send_command(sockfd, "LIST\r\n");

    // Fetching messages
    send_command(sockfd, "RETR 1\r\n");

    // Quit the session
    send_command(sockfd, "QUIT\r\n");

    // Closing socket
    close(sockfd);
    return 0;
}