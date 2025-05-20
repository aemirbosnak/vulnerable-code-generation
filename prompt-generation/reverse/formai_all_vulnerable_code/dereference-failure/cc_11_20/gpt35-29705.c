//FormAI DATASET v1.0 Category: Network Ping Test ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <time.h>

#define HOSTNAME "localhost" // change to the desired hostname
#define PORT "8080" // change to the desired port number
#define PACKET_SIZE 1024
#define TIMEOUT_USEC 1000000 // 1 second timeout

int main(void)
{
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    int rv;
    char s[INET6_ADDRSTRLEN];
    char buf[PACKET_SIZE+1];
    struct timeval tv;
    fd_set readfds;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;

    if ((rv = getaddrinfo(HOSTNAME, PORT, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    // loop through all the results and bind to the first we can
    for (p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype,
                p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "failed to bind socket\n");
        return 2;
    }

    // set timeout for receiving packets
    tv.tv_sec = 0;
    tv.tv_usec = TIMEOUT_USEC;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0) {
        perror("setsockopt");
        return 3;
    }

    // prepare messages
    int i;
    char message[PACKET_SIZE+1];
    for (i = 0; i < PACKET_SIZE; i++) {
        message[i] = 'A';
    }
    message[PACKET_SIZE] = '\0';

    while (true) {
        // send messages
        if (sendto(sockfd, message, strlen(message), 0,
            p->ai_addr, p->ai_addrlen) == -1) {
            perror("sendto");
            continue;
        }

        // wait for responses
        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);
        int n = select(sockfd+1, &readfds, NULL, NULL, &tv);
        if (n == -1) {
            perror("select");
            continue;
        }
        else if (n == 0) {
            printf("Request timed out\n");
        }
        else {
            struct sockaddr_storage their_addr;
            socklen_t addr_len = sizeof their_addr;
            int numbytes = recvfrom(sockfd, buf, PACKET_SIZE-1 , 0,
                (struct sockaddr *)&their_addr, &addr_len);
            if (numbytes == -1) {
                perror("recvfrom");
                continue;
            }
            buf[numbytes] = '\0';
            printf("Received: %s\n", buf);
        }

        // wait for some time before sending next message
        srand(time(0));
        int wait_time = rand() % 4;
        sleep(wait_time);
    }

    freeaddrinfo(servinfo);
    close(sockfd);

    return 0;
}