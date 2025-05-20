//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_USERNAME_SIZE 256
#define MAX_PASSWORD_SIZE 256
#define MAX_SERVER_SIZE 256
#define MAX_MAILBOX_SIZE 256

int main(int argc, char * argv[]) {
    // Declare variables for user input
    char username[MAX_USERNAME_SIZE];
    char password[MAX_PASSWORD_SIZE];
    char server[MAX_SERVER_SIZE];
    char mailbox[MAX_MAILBOX_SIZE];

    // Prompt user for username
    printf("Username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0; // Remove newline character

    // Prompt user for password
    printf("Password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0; // Remove newline character

    // Prompt user for server name
    printf("Mail server: ");
    fgets(server, sizeof(server), stdin);
    server[strcspn(server, "\n")] = 0; // Remove newline character

    // Prompt user for mailbox name
    printf("Mailbox: ");
    fgets(mailbox, sizeof(mailbox), stdin);
    mailbox[strcspn(mailbox, "\n")] = 0; // Remove newline character

    // Resolve server address
    struct addrinfo hints = {0};
    hints.ai_family = AF_INET; // IPv4
    hints.ai_socktype = SOCK_STREAM; // TCP
    struct addrinfo * addr_info;
    int error = getaddrinfo(server, "imap", &hints, &addr_info);
    if (error != 0) {
        fprintf(stderr, "Error resolving address: %s\n", gai_strerror(error));
        return 1;
    }

    // Create socket
    int sock = socket(addr_info->ai_family, addr_info->ai_socktype, addr_info->ai_protocol);
    if (sock == -1) {
        perror("Error creating socket");
        return 1;
    }

    // Connect to server
    error = connect(sock, addr_info->ai_addr, addr_info->ai_addrlen);
    if (error == -1) {
        perror("Error connecting to server");
        return 1;
    }

    // Free address info
    freeaddrinfo(addr_info);

    // Receive server greeting
    char buffer[MAX_BUFFER_SIZE];
    error = recv(sock, buffer, MAX_BUFFER_SIZE, 0);
    if (error == -1) {
        perror("Error receiving greeting");
        return 1;
    }
    buffer[error] = 0;
    printf("%s", buffer);

    // Send login command
    char login_command[MAX_BUFFER_SIZE];
    snprintf(login_command, sizeof(login_command), "LOGIN %s %s\r\n", username, password);
    error = send(sock, login_command, strlen(login_command), 0);
    if (error == -1) {
        perror("Error sending login command");
        return 1;
    }

    // Receive login response
    error = recv(sock, buffer, MAX_BUFFER_SIZE, 0);
    if (error == -1) {
        perror("Error receiving login response");
        return 1;
    }
    buffer[error] = 0;
    printf("%s", buffer);

    // Send select command
    char select_command[MAX_BUFFER_SIZE];
    snprintf(select_command, sizeof(select_command), "SELECT %s\r\n", mailbox);
    error = send(sock, select_command, strlen(select_command), 0);
    if (error == -1) {
        perror("Error sending select command");
        return 1;
    }

    // Receive select response
    error = recv(sock, buffer, MAX_BUFFER_SIZE, 0);
    if (error == -1) {
        perror("Error receiving select response");
        return 1;
    }
    buffer[error] = 0;
    printf("%s", buffer);

    // Send logout command
    char logout_command[MAX_BUFFER_SIZE];
    snprintf(logout_command, sizeof(logout_command), "LOGOUT\r\n");
    error = send(sock, logout_command, strlen(logout_command), 0);
    if (error == -1) {
        perror("Error sending logout command");
        return 1;
    }

    // Receive logout response
    error = recv(sock, buffer, MAX_BUFFER_SIZE, 0);
    if (error == -1) {
        perror("Error receiving logout response");
        return 1;
    }
    buffer[error] = 0;
    printf("%s", buffer);

    // Close socket
    close(sock);
    
    return 0;
}