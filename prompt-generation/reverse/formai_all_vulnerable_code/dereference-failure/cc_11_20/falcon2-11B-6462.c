//Falcon2-11B DATASET v1.0 Category: Building a IMAP Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>
#include <ctype.h>

#define PORT 993

int main() {
    int socket_fd, ret;
    struct sockaddr_in server;
    struct hostent *server_info;
    char buffer[1024];
    int size;
    char username[50], password[50], email[1024];

    // Connect to the server
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("Error: Unable to create socket");
        return 1;
    }

    server_info = gethostbyname("imap.example.com");
    if (server_info == NULL) {
        fprintf(stderr, "Error: Host not found\n");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    memcpy((char *) &server.sin_addr.s_addr, (char *) server_info->h_addr, server_info->h_length);

    ret = connect(socket_fd, (struct sockaddr *) &server, sizeof(server));
    if (ret < 0) {
        perror("Error: Unable to connect to server");
        return 1;
    }

    // Login
    printf("Enter your email address: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = 0;

    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0;

    snprintf(buffer, sizeof(buffer), "AUTHENTICATE PLAIN\r\n");
    size = send(socket_fd, buffer, strlen(buffer), 0);
    if (size < 0) {
        perror("Error: Unable to send authentication command");
        return 1;
    }

    size = recv(socket_fd, buffer, sizeof(buffer), 0);
    if (size < 0) {
        perror("Error: Unable to receive authentication response");
        return 1;
    }
    else if (strstr(buffer, "Success") == NULL) {
        fprintf(stderr, "Error: Invalid authentication response\n");
        return 1;
    }

    snprintf(buffer, sizeof(buffer), "LOGIN %s %s\r\n", email, password);
    size = send(socket_fd, buffer, strlen(buffer), 0);
    if (size < 0) {
        perror("Error: Unable to send login command");
        return 1;
    }

    size = recv(socket_fd, buffer, sizeof(buffer), 0);
    if (size < 0) {
        perror("Error: Unable to receive login response");
        return 1;
    }
    else if (strstr(buffer, "Success") == NULL) {
        fprintf(stderr, "Error: Invalid login response\n");
        return 1;
    }

    snprintf(buffer, sizeof(buffer), "LIST \"\" \"\"\r\n");
    size = send(socket_fd, buffer, strlen(buffer), 0);
    if (size < 0) {
        perror("Error: Unable to send list command");
        return 1;
    }

    size = recv(socket_fd, buffer, sizeof(buffer), 0);
    if (size < 0) {
        perror("Error: Unable to receive list response");
        return 1;
    }

    printf("Mailbox listing: %s\n", buffer);

    // Close the connection
    ret = close(socket_fd);
    if (ret < 0) {
        perror("Error: Unable to close socket");
        return 1;
    }

    return 0;
}