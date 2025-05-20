//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_BUFF 1024
#define PORT 5000

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sockfd, connfd;
    char buff[MAX_BUFF];
    struct sockaddr_in servaddr, clientaddr;
    struct hostent *he;
    struct in_addr **addr_list;

    if ((he = gethostbyname(argv[1])) == NULL) {
        herror("gethostbyname() failed");
        exit(EXIT_FAILURE);
    }

    addr_list = (struct in_addr **)he->h_addr_list;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket()");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr = *addr_list[0];

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect()");
        exit(EXIT_FAILURE);
    }

    printf("Connected to %s on port %d\n", argv[1], PORT);

    if (send(sockfd, "GET / HTTP/1.1\r\n\r\n", strlen("GET / HTTP/1.1\r\n\r\n"), 0) < 0) {
        perror("send()");
        exit(EXIT_FAILURE);
    }

    printf("Request sent!\n");

    int len, optval = 1;
    socklen_t optlen = sizeof(optval);

    if (setsockopt(sockfd, SOL_SOCKET, SO_KEEPALIVE, &optval, optlen) < 0) {
        perror("setsockopt()");
        exit(EXIT_FAILURE);
    }

    if (getsockopt(sockfd, SOL_SOCKET, SO_KEEPALIVE, &optval, &optlen) < 0) {
        perror("getsockopt()");
        exit(EXIT_FAILURE);
    }

    printf("SO_KEEPALIVE is %s\n", (optval ? "ON" : "OFF"));

    len = sizeof(clientaddr);
    if (getsockname(sockfd, (struct sockaddr *)&clientaddr, &len) < 0) {
        perror("getsockname()");
        exit(EXIT_FAILURE);
    }

    printf("Client socket is %s:%d\n", inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));

    len = sizeof(servaddr);
    if (getpeername(sockfd, (struct sockaddr *)&servaddr, &len) < 0) {
        perror("getpeername()");
        exit(EXIT_FAILURE);
    }

    printf("Server socket is %s:%d\n", inet_ntoa(servaddr.sin_addr), ntohs(servaddr.sin_port));

    if ((len = recv(sockfd, buff, MAX_BUFF, 0)) < 0) {
        perror("recv()");
        exit(EXIT_FAILURE);
    }

    buff[len] = '\0';
    printf("Received %d bytes: %s\n", len, buff);

    close(sockfd);

    return 0;
}