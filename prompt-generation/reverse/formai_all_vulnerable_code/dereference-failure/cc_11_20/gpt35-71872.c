//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_LENGTH 1024

int main() {
    char username[MAX_LENGTH], password[MAX_LENGTH], email[MAX_LENGTH];
    char buffer[MAX_LENGTH];
    int sock_fd, n;

    struct hostent* server;
    struct sockaddr_in serv_addr;

    printf("Welcome to POP3 client program!\n");

    printf("Please enter your server name: ");
    fgets(buffer, MAX_LENGTH, stdin);
    buffer[strcspn(buffer, "\n")] = 0;

    server = gethostbyname(buffer);
    if (server == NULL) {
        printf("Error, no such host!\n");
        exit(0);
    }

    printf("Please enter your server port: ");
    fgets(buffer, MAX_LENGTH, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    int port = atoi(buffer);

    printf("Please enter your username: ");
    fgets(username, MAX_LENGTH, stdin);
    username[strcspn(username, "\n")] = 0;

    printf("Please enter your password: ");
    fgets(password, MAX_LENGTH, stdin);
    password[strcspn(password, "\n")] = 0;

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        printf("Error opening socket!\n");
        exit(0);
    }

    bzero((char*) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char*) server->h_addr, (char*) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    if (connect(sock_fd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server!\n");
        exit(0);
    }

    bzero(buffer, MAX_LENGTH);
    n = read(sock_fd, buffer, MAX_LENGTH-1);
    if (n < 0) {
        printf("Error reading from socket!\n");
        exit(0);
    }

    printf("Server message: %s\n", buffer);

    // Authenticate user
    snprintf(buffer, MAX_LENGTH, "USER %s\r\n", username);
    n = write(sock_fd, buffer, strlen(buffer));
    printf(">> %s", buffer);
    if (n < 0) {
        printf("Error writing to socket!\n");
        exit(0);
    }

    bzero(buffer, MAX_LENGTH);
    n = read(sock_fd, buffer, MAX_LENGTH-1);
    if (n < 0) {
        printf("Error reading from socket!\n");
        exit(0);
    }
    printf("Server message: %s\n", buffer);

    snprintf(buffer, MAX_LENGTH, "PASS %s\r\n", password);
    n = write(sock_fd, buffer, strlen(buffer));
    printf(">> %s", buffer);
    if (n < 0) {
        printf("Error writing to socket!\n");
        exit(0);
    }

    bzero(buffer, MAX_LENGTH);
    n = read(sock_fd, buffer, MAX_LENGTH-1);
    if (n < 0) {
        printf("Error reading from socket!\n");
        exit(0);
    }
    printf("Server message: %s\n", buffer);

    // List all messages           
    snprintf(buffer, MAX_LENGTH, "LIST\r\n");
    n = write(sock_fd, buffer, strlen(buffer));
    printf(">> %s", buffer);
    if (n < 0) {
        printf("Error writing to socket!\n");
        exit(0);
    }

    printf("Messages:\n");
    while (1) {
        bzero(buffer, MAX_LENGTH);
        n = read(sock_fd, buffer, MAX_LENGTH-1);
        if (n < 0) {
            printf("Error reading from socket!\n");
            exit(0);
        }

        // Check if message is end of list indicator
        if (strstr(buffer, ".\r\n") != NULL) {
            break;
        }

        // Print message
        printf("%s", buffer);
    }

    // Select a message
    printf("Enter message number to view: ");
    fgets(buffer, MAX_LENGTH, stdin);
    buffer[strcspn(buffer, "\n")] = 0;

    snprintf(buffer, MAX_LENGTH, "RETR %s\r\n", buffer);
    n = write(sock_fd, buffer, strlen(buffer));
    printf(">> %s", buffer);
    if (n < 0) {
        printf("Error writing to socket!\n");
        exit(0);
    }

    // Print message contents
    printf("Message content:\n");
    while (1) {
        bzero(buffer, MAX_LENGTH);
        n = read(sock_fd, buffer, MAX_LENGTH-1);
        if (n < 0) {
            printf("Error reading from socket!\n");
            exit(0);
        }

        // Check if message is end of message indicator
        if (strstr(buffer, "\r\n.\r\n") != NULL) {
            break;
        }

        // Print message line
        printf("%s", buffer);
    }

    // Close connection
    snprintf(buffer, MAX_LENGTH, "QUIT\r\n");
    n = write(sock_fd, buffer, strlen(buffer));
    printf(">> %s", buffer);
    if (n < 0) {
        printf("Error writing to socket!\n");
        exit(0);
    }

    close(sock_fd);

    return 0;
}