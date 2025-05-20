//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define POP3_PORT 110

int main(int argc, char const *argv[]) {
    if (argc != 3) {
        printf("Usage: %s hostname username\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(POP3_PORT);

    struct hostent *server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Error: no such host\n");
        exit(EXIT_FAILURE);
    }

    memcpy(&server_address.sin_addr, server->h_addr, server->h_length);

    int socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socket_fd < 0) {
        printf("Error: failed to open socket\n");
        exit(EXIT_FAILURE);
    }

    if (connect(socket_fd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        printf("Error: failed to connect to server\n");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    if (recv(socket_fd, buffer, BUFFER_SIZE, 0) < 0) {
        printf("Error: failed to receive message from server\n");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    snprintf(buffer, BUFFER_SIZE, "USER %s\r\n", argv[2]);
    if (send(socket_fd, buffer, strlen(buffer), 0) < strlen(buffer)) {
        printf("Error: failed to send message to server\n");
        exit(EXIT_FAILURE);
    }

    memset(buffer, 0, BUFFER_SIZE);

    if (recv(socket_fd, buffer, BUFFER_SIZE, 0) < 0) {
        printf("Error: failed to receive message from server\n");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    snprintf(buffer, BUFFER_SIZE, "PASS ");
    char *password = getpass("Enter password: ");
    strcat(buffer, password);
    strcat(buffer, "\r\n");

    if (send(socket_fd, buffer, strlen(buffer), 0) < strlen(buffer)) {
        printf("Error: failed to send message to server\n");
        exit(EXIT_FAILURE);
    }

    memset(buffer, 0, BUFFER_SIZE);

    if (recv(socket_fd, buffer, BUFFER_SIZE, 0) < 0) {
        printf("Error: failed to receive message from server\n");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    if (send(socket_fd, "LIST\r\n", 6, 0) < 6) {
        printf("Error: failed to send message to server\n");
        exit(EXIT_FAILURE);
    }

    memset(buffer, 0, BUFFER_SIZE);

    if (recv(socket_fd, buffer, BUFFER_SIZE, 0) < 0) {
        printf("Error: failed to receive message from server\n");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    if (send(socket_fd, "QUIT\r\n", 6, 0) < 6) {
        printf("Error: failed to send message to server\n");
        exit(EXIT_FAILURE);
    }

    memset(buffer, 0, BUFFER_SIZE);

    if (recv(socket_fd, buffer, BUFFER_SIZE, 0) < 0) {
        printf("Error: failed to receive message from server\n");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    close(socket_fd);

    return 0;
}