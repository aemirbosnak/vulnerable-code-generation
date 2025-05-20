//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define MAX_LINE 1024
#define PORT 5000
#define BACKLOG 5

int main() {
    int sd, addrlen, new_sd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX_LINE];
    struct hostent *server;

    sd = socket(AF_INET, SOCK_STREAM, 0);
    if (sd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "No such host\n");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    addrlen = sizeof(serv_addr);

    if (connect(sd, (struct sockaddr *)&serv_addr, addrlen) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        bzero(buffer, MAX_LINE);
        fgets(buffer, MAX_LINE, stdin);
        send(sd, buffer, strlen(buffer), 0);

        bzero(buffer, MAX_LINE);
        recv(sd, buffer, MAX_LINE, 0);
        printf("%s", buffer);
    }

    close(sd);
    return 0;
}