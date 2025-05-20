//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_HOST_NAME 256
#define MAX_DATA_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    char host[MAX_HOST_NAME];
    char port[6];
    int yes = 1;
    int rv, numbytes;
    char senddata[MAX_DATA_SIZE];
    char recvdata[MAX_DATA_SIZE];

    // Set up hints for getaddrinfo
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;

    // Get address info for server
    if ((rv = getaddrinfo(argv[1], argv[2], &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    // Create socket
    if ((sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol)) == -1) {
        perror("socket");
        exit(1);
    }

    // Set socket option for reuse address
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));

    // Connect to server
    if ((rv = connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen)) == -1) {
        perror("connect");
        exit(1);
    }

    // Send data to server
    strcpy(senddata, "Hello, world!");
    numbytes = send(sockfd, senddata, strlen(senddata), 0);
    if (numbytes == -1) {
        perror("send");
        exit(1);
    }

    // Receive data from server
    numbytes = recv(sockfd, recvdata, MAX_DATA_SIZE, 0);
    if (numbytes == -1) {
        perror("recv");
        exit(1);
    }

    // Print received data
    printf("Received data: %s\n", recvdata);

    // Close socket
    close(sockfd);

    return 0;
}