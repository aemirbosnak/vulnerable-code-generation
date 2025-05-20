//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[BUF_SIZE];
    int optval = 1;
    struct timeval timeout;
    struct protoent *proto;
    char *hostname;

    printf("Enter hostname of server: ");
    scanf("%s", hostname);

    if ((proto = getprotobyname("tcp")) == NULL) {
        fprintf(stderr, "getprotobyname() failed\n");
        exit(1);
    }

    timeout.tv_sec = 2;
    timeout.tv_usec = 0;

    sockfd = socket(AF_INET, SOCK_STREAM, proto->p_proto);
    if (sockfd < 0) {
        fprintf(stderr, "Error opening socket\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80);
    if (inet_pton(AF_INET, hostname, &serv_addr.sin_addr) <= 0) {
        fprintf(stderr, "inet_pton() failed\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Error connecting\n");
        exit(1);
    }

    printf("Enter the timeout value in seconds: ");
    scanf("%d", &timeout.tv_sec);

    while (1) {
        setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(struct timeval));
        n = recv(sockfd, buffer, BUF_SIZE, 0);
        if (n < 0) {
            fprintf(stderr, "Error receiving data\n");
            exit(1);
        } else if (n == 0) {
            printf("Connection closed by server\n");
            exit(1);
        } else {
            printf("Received: %s\n", buffer);
            sleep(2);
        }
    }

    return 0;
}