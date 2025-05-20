//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define PORT 143

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char buffer[BUF_SIZE];
    int n;

    if (argc < 3) {
        printf("Usage: %s <host> <user> <password>\n", argv[0]);
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket!\n");
        exit(1);
    }

    memset(&server, 0, sizeof(server));

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    inet_pton(AF_INET, argv[1], &server.sin_addr);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error connecting to server!\n");
        exit(1);
    }

    printf("Connected to server.\n");

    sprintf(buffer, "LOGIN %s %s\r\n", argv[2], argv[3]);
    send(sock, buffer, strlen(buffer), 0);

    while (1) {
        n = recv(sock, buffer, BUF_SIZE, 0);

        if (n <= 0) {
            printf("Disconnected from server.\n");
            exit(0);
        }

        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sock);
    return 0;
}