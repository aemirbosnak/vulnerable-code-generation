//FormAI DATASET v1.0 Category: Network Ping Test ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/time.h>

#define ECHO_REPLY_CODE 0
#define BUFFER_SIZE 1024
#define TTL_VALUE 64
#define MAX_HOPS 30

/**
 * Function to compute the time difference between 2 timestamps in milliseconds.
 *
 * @param start The start timestamp
 * @param end The end timestamp
 * @return The time difference in milliseconds
 */
double timeval_diff(struct timeval *start, struct timeval *end) {
    return ((double)(end->tv_usec - start->tv_usec) / 1000.0 + (double)(end->tv_sec - start->tv_sec) * 1000.0);
}

/**
 * Function to perform a ping test to a given IP address.
 *
 * @param hostname The host name or IP address to ping
 * @return 1 if the ping was successful, 0 otherwise
 */
int ping(char *hostname) {
    struct timeval start_time, end_time;
    struct sockaddr_in sin;
    struct hostent *host;
    char buffer[BUFFER_SIZE];
    int sockfd, ttl = TTL_VALUE, ttl_reached = 0, seq_num = 0;

    // Create a socket for sending the ping message
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("Error creating raw socket");
        return 0;
    }

    // Increase the TTL value of the ping packet
    if (setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl)) != 0) {
        perror("Error setting TTL socket option");
        return 0;
    }

    // Resolve the host name into its IP address
    if ((host = gethostbyname(hostname)) == NULL) {
        perror("Error resolving hostname");
        return 0;
    }

    // Configure the socket address
    memset(&sin, 0, sizeof(struct sockaddr_in));
    sin.sin_family = AF_INET;
    memcpy(&sin.sin_addr.s_addr, host->h_addr, host->h_length);

    // Ping the host for a maximum of MAX_HOPS times
    while (!ttl_reached && seq_num < MAX_HOPS) {
        // Update the sequence number for the current ping packet
        seq_num++;

        // Fill the buffer with random test data
        memset(buffer, '\0', sizeof(buffer));
        sprintf(buffer, "PING %d", seq_num);

        // Get the current timestamp
        gettimeofday(&start_time, NULL);

        // Send the ping packet to the host
        if (sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&sin, sizeof(struct sockaddr_in)) < 0) {
            perror("Error sending ping message");
            return 0;
        }

        // Wait for a reply from the host
        memset(buffer, '\0', sizeof(buffer));
        if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
            perror("Error receiving ping message");
            return 0;
        }

        // Get the current timestamp
        gettimeofday(&end_time, NULL);

        // Compute the time difference between the start and end timestamps
        double rtt = timeval_diff(&start_time, &end_time);

        // Extract the reply code from the ping packet
        unsigned char *icmp = (unsigned char *)buffer;
        int reply_code = *(icmp + 20);

        // Print the ping result
        printf("Ping to %s - Hop #%d - RTT: %.2f ms [", hostname, seq_num, rtt);
        for (int i = 0; i < sizeof(buffer); i++) {
            printf("%02X", *(icmp + i));
            if (i < sizeof(buffer) - 1) {
                printf(":");
            }
        }
        printf("] Reply code: %d\n", reply_code);

        // Check if the reply code indicates an Echo Reply message
        if (reply_code == ECHO_REPLY_CODE) {
            return 1;
        }

        // Check if we have reached the maximum number of hops
        if (ttl == MAX_HOPS) {
            ttl_reached = 1;
        }

        // Increase the TTL value for the next ping packet
        ttl++;
        if (setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl)) != 0) {
            perror("Error setting TTL socket option");
            return 0;
        }

        // Wait for a few milliseconds before sending the next ping packet
        usleep(1000);
    }

    return 0;
}

/**
 * Main function to perform the ping test to a given host.
 */
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./ping <hostname>\n");
        return 1;
    }

    // Perform the ping test to the specified host
    if (ping(argv[1])) {
        printf("Ping test successful\n");
    } else {
        printf("Ping test failed\n");
    }

    return 0;
}