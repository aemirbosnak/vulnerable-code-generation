//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024

void print_help(void) {
    printf("Usage:./portscanner <hostname> <port>\n");
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        print_help();
        return 1;
    }

    char *hostname = argv[1];
    char *port = argv[2];
    int port_number = atoi(port);

    struct addrinfo hints, *result, *rp;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(hostname, NULL, &hints, &result)!= 0) {
        fprintf(stderr, "Error: could not resolve hostname\n");
        return 1;
    }

    for (rp = result; rp!= NULL; rp = rp->ai_next) {
        struct sockaddr_in *sin = (struct sockaddr_in *) rp->ai_addr;
        int sockfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);

        if (sockfd == -1) {
            perror("Error: could not create socket");
            continue;
        }

        if (connect(sockfd, rp->ai_addr, rp->ai_addrlen) == 0) {
            printf("Port %d is open\n", port_number);
        } else {
            printf("Port %d is closed\n", port_number);
        }

        close(sockfd);
    }

    freeaddrinfo(result);
    return 0;
}