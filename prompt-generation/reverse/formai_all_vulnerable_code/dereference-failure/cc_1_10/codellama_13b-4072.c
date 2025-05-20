//Code Llama-13B DATASET v1.0 Category: Building a FTP Client ; Style: systematic
/*
 * Building a FTP Client example program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 21
#define MAX_LINE 1024

int main() {
    int sock, n;
    char buf[MAX_LINE];
    struct sockaddr_in server;
    struct hostent *host;

    if ((host = gethostbyname("www.example.com")) == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr = *((struct in_addr *) host->h_addr);
    bzero(&(server.sin_zero), 8);

    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("connect");
        exit(1);
    }

    printf("Connected to the FTP server\n");

    while (fgets(buf, MAX_LINE, stdin) != NULL) {
        if (send(sock, buf, strlen(buf), 0) < 0) {
            perror("send");
            exit(1);
        }
    }

    close(sock);
    return 0;
}