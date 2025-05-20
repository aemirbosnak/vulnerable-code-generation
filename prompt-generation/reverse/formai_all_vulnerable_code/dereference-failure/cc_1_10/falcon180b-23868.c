//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main() {
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    char s[NI_MAXSERV];
    int rv;
    int numbytes;

    /* Initialize hints */
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    /* Get the address information */
    if ((rv = getaddrinfo("example.com", "http", &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    /* Create a socket */
    sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    /* Connect to the server */
    if (connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen) == -1) {
        perror("connect");
        exit(1);
    }

    /* Send a request */
    snprintf(s, sizeof(s), "GET / HTTP/1.0\r\nHost: example.com\r\n\r\n");
    numbytes = send(sockfd, s, strlen(s), 0);
    if (numbytes == -1) {
        perror("send");
        exit(1);
    }

    /* Receive a response */
    char buffer[4096];
    numbytes = recv(sockfd, buffer, sizeof(buffer), 0);
    if (numbytes == -1) {
        perror("recv");
        exit(1);
    }

    /* Print the response */
    printf("Received %d bytes\n", numbytes);
    printf("%s", buffer);

    /* Close the socket */
    close(sockfd);

    return 0;
}