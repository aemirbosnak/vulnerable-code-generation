//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFLEN 1024
#define TRUE 1
#define FALSE 0
#define PORT "80"

int main(int argc, char *argv[]) {
    int sockfd, ret;
    struct sockaddr_in server;
    char buffer[BUFLEN];
    struct hostent *host;
    int opt = TRUE;

    if (argc < 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    if ((host = gethostbyname(argv[1])) == NULL) {
        printf("Error: %s\n", hstrerror(h_errno));
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Error: %s\n", strerror(errno));
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(PORT));
    server.sin_addr = *((struct in_addr *)host->h_addr);

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Error: %s\n", strerror(errno));
        exit(1);
    }

    while (opt) {
        printf("Enter a message: ");
        fgets(buffer, BUFLEN, stdin);
        send(sockfd, buffer, strlen(buffer), 0);
        memset(buffer, 0, BUFLEN);
        ret = recv(sockfd, buffer, BUFLEN, 0);
        if (ret <= 0) {
            printf("Error: %s\n", strerror(errno));
            exit(1);
        }
        printf("Received message: %s\n", buffer);
    }

    close(sockfd);
    exit(0);
}