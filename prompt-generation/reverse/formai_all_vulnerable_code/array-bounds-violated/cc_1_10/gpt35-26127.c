//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./httpclient <server_address>\n");
        exit(EXIT_FAILURE);
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        perror("Could not create socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_family = AF_INET;
    server.sin_port = htons(80);

    if (connect(sock, (struct sockaddr*) &server, sizeof(server)) == -1) {
        perror("Could not connect to server");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE] = {0};
    char request[BUFFER_SIZE] = {0};

    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);

    if (send(sock, request, strlen(request), 0) == -1) {
        perror("Could not send request");
        exit(EXIT_FAILURE);
    }

    ssize_t received = 0;
    while ((received = recv(sock, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[received] = '\0';
        printf("%s", buffer);
    }

    printf("\n");

    if (received == -1) {
        perror("Could not receive response");
        exit(EXIT_FAILURE);
    }

    close(sock);

    return EXIT_SUCCESS;
}