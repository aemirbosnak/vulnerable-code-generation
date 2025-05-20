//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <time.h>

#define MAX_PAYLOAD 1024

void print_usage(char *program_name) {
    printf("Usage: %s <hostname>\n", program_name);
    printf("Example: %s www.google.com\n", program_name);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_usage(argv[0]);
        return 1;
    }

    char *hostname = argv[1];

    // Resolve the hostname to an IP address
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Error: Could not resolve hostname %s\n", hostname);
        return 1;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        printf("Error: Could not create socket\n");
        return 1;
    }

    // Set the socket timeout to 1 second
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1) {
        printf("Error: Could not set socket timeout\n");
        return 1;
    }

    // Set the destination address
    struct sockaddr_in dest_addr;
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(33434);
    dest_addr.sin_addr = *((struct in_addr *)host->h_addr);

    // Create a buffer to store the payload
    char payload[MAX_PAYLOAD];
    memset(payload, 'A', MAX_PAYLOAD);

    // Send the ping request
    if (sendto(sockfd, payload, MAX_PAYLOAD, 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) == -1) {
        printf("Error: Could not send ping request\n");
        return 1;
    }

    // Wait for the ping response
    struct sockaddr_in src_addr;
    socklen_t src_addr_len = sizeof(src_addr);
    if (recvfrom(sockfd, payload, MAX_PAYLOAD, 0, (struct sockaddr *)&src_addr, &src_addr_len) == -1) {
        printf("Error: Could not receive ping response\n");
        return 1;
    }

    // Calculate the round-trip time
    struct timeval end_time;
    gettimeofday(&end_time, NULL);
    long round_trip_time = (end_time.tv_sec - timeout.tv_sec) * 1000000 + (end_time.tv_usec - timeout.tv_usec);

    // Print the ping response
    printf("Ping response received from %s: round-trip time = %ld microseconds\n", inet_ntoa(src_addr.sin_addr), round_trip_time);

    // Close the socket
    close(sockfd);

    return 0;
}