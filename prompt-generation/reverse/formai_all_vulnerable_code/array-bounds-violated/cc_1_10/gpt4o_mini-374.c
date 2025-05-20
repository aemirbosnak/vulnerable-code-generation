//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 110
#define BUFFER_SIZE 1024

void handle_server_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_recv = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_recv < 0) {
        perror("Error receiving data");
        exit(EXIT_FAILURE);
    }
    buffer[bytes_recv] = '\0';
    printf("Server: %s", buffer);
}

void send_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
    printf("Sent: %s", command);
    handle_server_response(sockfd);
}

void list_emails(int sockfd) {
    send_command(sockfd, "LIST\r\n");
}

void retrieve_email(int sockfd, const char *email_number) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "RETR %s\r\n", email_number);
    send_command(sockfd, command);
}

void quit_session(int sockfd) {
    send_command(sockfd, "QUIT\r\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <username>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    const char *hostname = argv[1];
    const char *username = argv[2];
    char password[100];

    printf("Enter password for %s: ", username);
    if (fgets(password, sizeof(password), stdin) == NULL) {
        perror("Error reading password");
        return EXIT_FAILURE;
    }
    password[strcspn(password, "\n")] = 0; // Remove newline character

    struct sockaddr_in serv_addr;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, hostname, &serv_addr.sin_addr) <= 0) {
        perror("Invalid address or address not supported");
        return EXIT_FAILURE;
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        return EXIT_FAILURE;
    }

    handle_server_response(sockfd); // Welcome message

    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send_command(sockfd, command);

    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send_command(sockfd, command);

    list_emails(sockfd); // List emails

    char email_number[10];
    printf("Enter email number to retrieve: ");
    fgets(email_number, sizeof(email_number), stdin);
    email_number[strcspn(email_number, "\n")] = 0; // Remove newline character

    retrieve_email(sockfd, email_number);

    quit_session(sockfd); // Closing the connection

    close(sockfd); // Close the socket
    return EXIT_SUCCESS;
}