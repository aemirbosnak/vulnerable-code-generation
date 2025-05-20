//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_HOST 1000
#define MAX_PORT 1000
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int i, j, port, sock, max_sd;
    char host[MAX_HOST];
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUF_SIZE];
    fd_set readfds;

    if (argc < 3) {
        printf("Usage:./scanner <host> <port>\n");
        exit(1);
    }

    strcpy(host, argv[1]);
    port = atoi(argv[2]);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket failed");
        exit(1);
    }

    server = gethostbyname(host);
    if (server == NULL) {
        printf("No such host: %s\n", host);
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr = *((struct in_addr *)server->h_addr);

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    FD_ZERO(&readfds);
    FD_SET(sock, &readfds);

    max_sd = sock;

    while (1) {
        FD_SET(0, &readfds);
        select(max_sd + 1, &readfds, NULL, NULL, NULL);

        if (FD_ISSET(sock, &readfds)) {
            bzero(buffer, BUF_SIZE);
            read(sock, buffer, BUF_SIZE);
            printf("Connected to port %d\n", port);
            close(sock);
            exit(0);
        }

        for (i = 0; i <= max_sd; i++) {
            if (FD_ISSET(i, &readfds) && i!= sock) {
                if (i > sock) {
                    printf("Port %d is open\n", ntohs(((struct sockaddr_in *)&readfds)->sin_port));
                }
            }
        }
    }

    return 0;
}