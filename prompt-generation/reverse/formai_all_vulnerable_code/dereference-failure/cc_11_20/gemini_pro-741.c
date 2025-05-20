//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <unistd.h>

#define MAX_PAYLOAD 1024
#define DEFAULT_PORT 80
#define MAX_TRIES 5
#define PING_INTERVAL 1
#define TIMEOUT 5

struct ping_packet {
    uint16_t id;
    uint16_t seq;
    uint32_t timestamp;
    char payload[MAX_PAYLOAD];
};

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Resolve hostname to IP address
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(DEFAULT_PORT);
    if (inet_aton(argv[1], &addr.sin_addr) == 0) {
        fprintf(stderr, "Invalid hostname: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        fprintf(stderr, "Failed to create socket: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Set timeout
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1) {
        fprintf(stderr, "Failed to set timeout: %s\n", strerror(errno));
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Connect to host
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        fprintf(stderr, "Failed to connect to host: %s\n", strerror(errno));
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Send ping packets
    int success_count = 0;
    for (int i = 0; i < MAX_TRIES; i++) {
        // Generate ping packet
        struct ping_packet packet;
        memset(&packet, 0, sizeof(packet));
        packet.id = i;
        packet.seq = i;
        packet.timestamp = time(NULL);
        memcpy(packet.payload, "PING", 4);

        // Send ping packet
        if (send(sockfd, &packet, sizeof(packet), 0) == -1) {
            fprintf(stderr, "Failed to send ping packet: %s\n", strerror(errno));
            continue;
        }

        // Receive ping response
        struct ping_packet response;
        if (recv(sockfd, &response, sizeof(response), 0) == -1) {
            fprintf(stderr, "Failed to receive ping response: %s\n", strerror(errno));
            continue;
        }

        // Check if response is valid
        if (response.id != i || response.seq != i) {
            fprintf(stderr, "Invalid ping response received: %s\n", strerror(errno));
            continue;
        }

        // Calculate round trip time
        double rtt = (difftime(time(NULL), response.timestamp) * 1000);

        // Print ping response
        printf("Ping: seq=%d, id=%d, time=%0.3f ms\n", response.seq, response.id, rtt);

        // Increment success count
        success_count++;
    }

    // Close socket
    close(sockfd);

    // Print summary
    printf("\nPing statistics for %s:\n", argv[1]);
    printf("Packets sent: %d\n", MAX_TRIES);
    printf("Packets received: %d\n", success_count);
    printf("Packet loss: %d%%\n", (MAX_TRIES - success_count) * 100 / MAX_TRIES);

    return EXIT_SUCCESS;
}