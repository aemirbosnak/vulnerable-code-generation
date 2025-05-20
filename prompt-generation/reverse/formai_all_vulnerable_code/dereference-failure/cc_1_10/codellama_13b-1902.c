//Code Llama-13B DATASET v1.0 Category: Wireless Network Scanner ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_BUFFER 1024

int main(int argc, char *argv[]) {
    char *host = NULL;
    char *port = NULL;
    int sockfd, n;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char buffer[MAX_BUFFER];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    host = argv[1];
    port = argv[2];

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket()");
        exit(1);
    }

    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port));
    server_addr.sin_addr = *((struct in_addr *)server->h_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect()");
        exit(1);
    }

    while (1) {
        memset(buffer, 0, MAX_BUFFER);
        n = read(sockfd, buffer, MAX_BUFFER);
        if (n < 0) {
            perror("read()");
            exit(1);
        }
        if (n == 0) {
            break;
        }
        printf("Received: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}