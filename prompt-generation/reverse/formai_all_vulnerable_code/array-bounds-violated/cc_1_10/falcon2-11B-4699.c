//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_BUF 1024
#define HOST "www.google.com"

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buf[MAX_BUF];

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80);

    if (inet_pton(AF_INET, HOST, &serv_addr.sin_addr) <= 0) {
        perror("ERROR, could not resolve hostname");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting to server");
        exit(1);
    }

    printf("Sending message...\n");
    n = write(sockfd, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", HOST);
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    printf("Receiving response...\n");
    n = read(sockfd, buf, MAX_BUF);
    buf[n] = '\0';
    printf("Response: %s\n", buf);

    close(sockfd);

    return 0;
}