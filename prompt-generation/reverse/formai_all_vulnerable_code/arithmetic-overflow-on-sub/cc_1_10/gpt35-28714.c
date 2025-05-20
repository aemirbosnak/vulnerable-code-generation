//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <time.h>

#define PORT "5000" // the port users will be connecting to

#define IP_VERSION 4 // define which version of IP to use

#define MAXDATASIZE 100 // max number of bytes we can get at once 

#define INTERVAL 5 // interval in seconds to check QoS

// function to get sockaddr, IPv4 or IPv6:
void *get_in_addr(struct sockaddr *sa)
{
    if (sa->sa_family == AF_INET) {
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }

    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

int main(int argc, char *argv[])
{
    int sockfd, numbytes;  
    char buf[MAXDATASIZE];
    struct addrinfo hints, *servinfo, *p;
    int rv;
    char s[INET6_ADDRSTRLEN];

    if (argc != 2) {
        fprintf(stderr,"usage: QoSmonitor hostname\n");
        exit(1);
    }

    memset(&hints, 0, sizeof hints);
    hints.ai_family = IP_VERSION;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(argv[1], PORT, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    // loop through all the results and connect to the first we can
    for(p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype,
                p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("connect");
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "failed to connect\n");
        return 2;
    }

    inet_ntop(p->ai_family, get_in_addr((struct sockaddr *)p->ai_addr),
            s, sizeof s);
    printf("connected to %s\n", s);

    freeaddrinfo(servinfo); // all done with this structure

    // check QoS every INTERVAL seconds
    while(1) {
        time_t start = time(NULL);
        if ((numbytes = recv(sockfd, buf, MAXDATASIZE-1, 0)) == -1) {
            perror("recv");
            exit(1);
        }

        buf[numbytes] = '\0';

        if (strcmp(buf, "good") == 0) {
            printf("QoS is good\n");
        } else if (strcmp(buf, "poor") == 0) {
            printf("QoS is poor\n");
        } else {
            printf("received invalid QoS status\n");
        }

        time_t end = time(NULL);
        int elapsed = end - start;

        if (elapsed < INTERVAL) {
            sleep(INTERVAL - elapsed);
        }
    }

    close(sockfd);

    return 0;
}