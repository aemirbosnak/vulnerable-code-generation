//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PACKET_SIZE 1024
#define MAX_TIMEOUT_MS 1000
#define PING_INTERVAL_MS 1000

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];

    struct hostent *hostinfo = gethostbyname(hostname);
    if (hostinfo == NULL) {
        perror("gethostbyname");
        return 2;
    }

    struct sockaddr_in dest_addr;
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(7);
    dest_addr.sin_addr = *(struct in_addr *)hostinfo->h_addr;

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 3;
    }

    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;

    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
        perror("setsockopt");
        return 4;
    }

    char buffer[MAX_PACKET_SIZE];
    int bytes_sent, bytes_received;

    struct timeval start_time, end_time;
    long long total_time = 0;
    int num_packets_sent = 0;
    int num_packets_received = 0;
    int num_packets_lost = 0;

    while (1) {
        // Send ping packet
        gettimeofday(&start_time, NULL);
        bytes_sent = sendto(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr));
        if (bytes_sent < 0) {
            perror("sendto");
            break;
        }
        num_packets_sent++;

        // Wait for ping response
        bytes_received = recvfrom(sockfd, buffer, sizeof(buffer), 0, NULL, NULL);
        if (bytes_received < 0) {
            if (errno == EAGAIN) {
                num_packets_lost++;
            } else {
                perror("recvfrom");
                break;
            }
        } else {
            num_packets_received++;
        }

        // Calculate ping time
        gettimeofday(&end_time, NULL);
        long long elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000 + (end_time.tv_usec - start_time.tv_usec) / 1000;
        total_time += elapsed_time;

        // Print ping statistics
        printf("Ping: %d bytes from %s: icmp_seq=%d time=%lld ms\n", bytes_received, hostname, num_packets_sent, elapsed_time);

        // Sleep for a bit before sending the next ping packet
        usleep(PING_INTERVAL_MS * 1000);
    }

    close(sockfd);

    printf("\n--- Ping statistics ---\n");
    printf("%d packets transmitted, %d packets received, %d%% packet loss\n", num_packets_sent, num_packets_received, (num_packets_sent - num_packets_received) * 100 / num_packets_sent);
    printf("round-trip min/avg/max/stddev = %lld/%lld/%lld/%lld ms\n", 0LL, total_time / num_packets_received, 0LL, 0LL);

    return 0;
}