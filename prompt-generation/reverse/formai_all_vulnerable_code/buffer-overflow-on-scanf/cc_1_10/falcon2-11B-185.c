//Falcon2-11B DATASET v1.0 Category: Building a IMAP Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PORT 143

int main() {
    int socket_fd, status;
    struct sockaddr_in server;
    struct hostent *server_host;

    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    server_host = gethostbyname("example.com");
    if (server_host == NULL) {
        fprintf(stderr, "Error resolving host\n");
        exit(EXIT_FAILURE);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    bcopy((char *)server_host->h_addr, (char *)&server.sin_addr.s_addr, server_host->h_length);

    if (connect(socket_fd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    char msg[256];
    printf("Enter message: ");
    scanf("%s", msg);

    if (send(socket_fd, msg, strlen(msg), 0) < 0) {
        perror("Error sending message");
        exit(EXIT_FAILURE);
    }

    if (recv(socket_fd, msg, 256, 0) < 0) {
        perror("Error receiving message");
        exit(EXIT_FAILURE);
    }

    printf("Received message: %s\n", msg);

    close(socket_fd);

    return 0;
}