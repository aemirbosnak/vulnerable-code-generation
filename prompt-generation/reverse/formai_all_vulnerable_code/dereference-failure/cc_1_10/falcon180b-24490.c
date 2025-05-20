//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAXLINE 4096

int main(int argc, char *argv[]) {
    int sockfd;
    char *host;
    char *port;
    struct sockaddr_in server_addr;
    char buffer[MAXLINE];

    if (argc!= 4) {
        printf("Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    host = argv[1];
    port = argv[2];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error opening socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port));

    if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
        printf("Invalid hostname\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (fgets(buffer, MAXLINE, stdin)!= NULL) {
        send(sockfd, buffer, strlen(buffer), 0);
    }

    close(sockfd);

    return 0;
}