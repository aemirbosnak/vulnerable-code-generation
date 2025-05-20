//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX 100
#define PORT "80"
#define TIMEOUT 5

char hostname[MAX]; // Hostname to be resolved
int sockfd; // Socket file descriptor
struct addrinfo hints, *servinfo, *p; // Address info structures
int rv; // Return value
int numhosts; // Number of hosts found
int i; // Loop counter

void print_usage() {
    printf("Usage:./program hostname\n");
    exit(1);
}

void print_error(char* msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        print_usage();
    }

    strcpy(hostname, argv[1]);

    // Initialize hints structure
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC; // Allow both IPv4 and IPv6
    hints.ai_socktype = SOCK_STREAM; // TCP socket
    hints.ai_protocol = IPPROTO_TCP; // TCP protocol
    hints.ai_flags = AI_CANONNAME; // Canonical hostname

    // Get address info
    if ((rv = getaddrinfo(hostname, PORT, &hints, &servinfo))!= 0) {
        print_error("getaddrinfo");
    }

    // Loop through all the results and print them
    numhosts = 0;
    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if (p->ai_family == AF_INET) {
            // IPv4 address
            printf("IPv4 address: %s\n", inet_ntoa(((struct sockaddr_in *)p->ai_addr)->sin_addr));
        } else if (p->ai_family == AF_INET6) {
            // IPv6 address
            printf("IPv6 address: %s\n", inet_ntop(AF_INET6, &((struct sockaddr_in6 *)p->ai_addr)->sin6_addr, inet_pton(AF_INET6, "::1", NULL)? NULL : alloca(INET6_ADDRSTRLEN), INET6_ADDRSTRLEN));
        }
        numhosts++;
    }

    // Cleanup
    freeaddrinfo(servinfo);

    return 0;
}