//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 1024

// This function creates a socket and sends a ping request to the specified address.
int ping(char *address) {
    // Create a socket.
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    // Set the socket options.
    int on = 1;
    if (setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &on, sizeof(on)) < 0) {
        perror("setsockopt");
        return -1;
    }

    // Set the destination address.
    struct sockaddr_in dest;
    memset(&dest, 0, sizeof(dest));
    dest.sin_family = AF_INET;
    dest.sin_addr.s_addr = inet_addr(address);

    // Create the ping request.
    char request[MAX_SIZE];
    memset(request, 0, sizeof(request));
    request[0] = 8; // ICMP Echo Request
    request[1] = 0; // Code
    request[2] = 0; // Checksum
    request[3] = 0; // Identifier
    request[4] = 0; // Sequence number
    request[5] = 0; // Data

    // Send the ping request.
    if (sendto(sockfd, request, sizeof(request), 0, (struct sockaddr *)&dest, sizeof(dest)) < 0) {
        perror("sendto");
        return -1;
    }

    // Receive the ping response.
    char response[MAX_SIZE];
    memset(response, 0, sizeof(response));
    struct sockaddr_in from;
    socklen_t fromlen = sizeof(from);
    if (recvfrom(sockfd, response, sizeof(response), 0, (struct sockaddr *)&from, &fromlen) < 0) {
        perror("recvfrom");
        return -1;
    }

    // Check if the ping response is valid.
    if (response[0] != 0 || response[1] != 0 || response[2] != 0) {
        printf("Invalid ping response.\n");
        return -1;
    }

    // Calculate the round-trip time.
    struct timeval tv1, tv2;
    gettimeofday(&tv1, NULL);
    gettimeofday(&tv2, NULL);
    long rtt = (tv2.tv_sec - tv1.tv_sec) * 1000 + (tv2.tv_usec - tv1.tv_usec) / 1000;

    // Print the ping results.
    printf("Ping to %s: rtt = %ld ms\n", address, rtt);

    // Close the socket.
    close(sockfd);

    return 0;
}

// This function is the main function of the program.
int main(int argc, char **argv) {
    // Check if the user has specified an address.
    if (argc < 2) {
        printf("Usage: %s <address>\n", argv[0]);
        return -1;
    }

    // Ping the specified address.
    if (ping(argv[1]) < 0) {
        return -1;
    }

    return 0;
}