//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

int main(int argc, char* argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUF_SIZE];
    int n;

    if (argc!= 4) {
        printf("Usage: %s <server> <port> <username>\n", argv[0]);
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    sprintf(buffer, "LOGIN %s\r\n", argv[3]);
    send(sock, buffer, strlen(buffer), 0);

    while (1) {
        n = recv(sock, buffer, BUF_SIZE, 0);
        if (n <= 0) {
            printf("Disconnected from server\n");
            break;
        }
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sock);
    return 0;
}