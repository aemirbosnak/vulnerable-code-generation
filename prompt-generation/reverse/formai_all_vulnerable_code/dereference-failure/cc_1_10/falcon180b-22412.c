//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>

#define MAX_BUF_SIZE 1024

int main() {
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    int rv;
    char s[MAX_BUF_SIZE];

    // Set up hints for getaddrinfo()
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;

    // Get address info for target server
    if ((rv = getaddrinfo("localhost", "5000", &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    // Create socket
    sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Connect to server
    if (connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen) == -1) {
        perror("connect");
        exit(1);
    }

    // Send data to server
    rv = send(sockfd, "QoS request", strlen("QoS request"), 0);
    if (rv == -1) {
        perror("send");
        exit(1);
    }

    // Receive response from server
    memset(s, 0, sizeof(s));
    rv = recv(sockfd, s, MAX_BUF_SIZE, 0);
    if (rv == -1) {
        perror("recv");
        exit(1);
    }
    printf("Response: %s\n", s);

    // Close socket
    close(sockfd);

    return 0;
}