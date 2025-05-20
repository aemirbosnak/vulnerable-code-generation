//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    struct hostent *host;
    char buffer[BUFFER_SIZE];
    int n;

    if (argc!= 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    host = gethostbyname(argv[1]);
    if (host == NULL) {
        printf("Error: could not resolve hostname\n");
        exit(1);
    }
    memcpy(&server.sin_addr, host->h_addr, host->h_length);

    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) == -1) {
        perror("connect");
        exit(1);
    }

    printf("Pinging host %s:%s\n", argv[1], argv[2]);

    while (1) {
        n = read(sock, buffer, BUFFER_SIZE);
        if (n <= 0) {
            printf("Connection closed\n");
            break;
        }
        write(1, buffer, n);
    }

    close(sock);

    return 0;
}