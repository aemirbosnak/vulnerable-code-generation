//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_LINE_SIZE 1024
#define PORT 25
#define SERVER "localhost"

void error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(EXIT_FAILURE);
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char *username = "username";
    char *password = "password";
    char *buffer = malloc(MAX_LINE_SIZE);
    char *message = "Hello, world!\r\n";

    if (buffer == NULL) {
        error("Could not allocate memory for buffer");
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        error("Could not create socket");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        error("Could not connect to server");
    }

    printf("Connected to server\n");
    printf("Authenticating...\n");

    // Send HELO command
    char *helo_cmd = "HELO localhost\r\n";
    send(sockfd, helo_cmd, strlen(helo_cmd), 0);

    // Send EHLO command
    char *ehelo_cmd = "EHLO localhost\r\n";
    send(sockfd, ehelo_cmd, strlen(ehelo_cmd), 0);

    // Send AUTH LOGIN command
    char *auth_cmd = "AUTH LOGIN\r\n";
    send(sockfd, auth_cmd, strlen(auth_cmd), 0);

    // Send username
    char *username_cmd = username;
    send(sockfd, username_cmd, strlen(username_cmd), 0);

    // Send password
    char *password_cmd = password;
    send(sockfd, password_cmd, strlen(password_cmd), 0);

    // Send message
    char *data_cmd = message;
    send(sockfd, data_cmd, strlen(data_cmd), 0);

    printf("Message sent\n");

    close(sockfd);
    free(buffer);
    return 0;
}