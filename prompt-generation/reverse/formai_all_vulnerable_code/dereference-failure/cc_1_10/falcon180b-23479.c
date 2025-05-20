//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFLEN 1024

int main(int argc, char **argv) {
    char *host;
    int port;
    int sock;
    struct hostent *he;
    struct sockaddr_in server;
    char buffer[BUFLEN];
    int len;

    if (argc!= 3) {
        printf("Usage: %s host port\n", argv[0]);
        exit(1);
    }

    host = argv[1];
    port = atoi(argv[2]);

    he = gethostbyname(host);
    if (he == NULL) {
        printf("Error: could not resolve host name\n");
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: could not create socket\n");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr = *((struct in_addr *)he->h_addr);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error: could not connect to server\n");
        exit(1);
    }

    while (1) {
        len = read(sock, buffer, BUFLEN);
        if (len <= 0) {
            printf("Error: could not read from server\n");
            exit(1);
        }
        buffer[len] = '\0';
        printf("%s", buffer);
    }

    close(sock);
    return 0;
}