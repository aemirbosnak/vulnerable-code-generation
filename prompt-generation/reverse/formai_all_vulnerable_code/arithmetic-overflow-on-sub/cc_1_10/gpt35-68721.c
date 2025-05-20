//FormAI DATASET v1.0 Category: Network Ping Test ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/time.h>

int main(int argc, char **argv) {

    struct hostent *host = NULL;
    struct timeval tvstart, tvend;

    if(argc != 2) {
        printf("Usage: %s [host]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Resolve the hostname
    if((host = gethostbyname(argv[1])) == NULL) {
        printf("Error: Failed to resolve hostname: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Setup socket and timeval
    int sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_ICMP);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr = *((struct in_addr *)host->h_addr_list[0]);
    char buffer[256] = {0};
    int sent = 0, received = 0;

    printf("Pinging %s [%s] with %d bytes of data:\n", argv[1], inet_ntoa(addr.sin_addr), sizeof(buffer));

    // Loop 10 times to send/receive packets
    for(int i = 0; i < 10; i++) {

        // Record the starting time for each loop
        gettimeofday(&tvstart, NULL);

        // Send the packet
        if(sendto(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
            printf("Error: Failed to send ping packet for sequence %d\n", i);
            continue;
        }
        sent++;

        // Wait for response, timeout of 1 second
        fd_set fds;
        FD_SET(sockfd, &fds);
        struct timeval tv = {1, 0};
        int rv = select(sockfd+1, &fds, NULL, NULL, &tv);
        if(rv == -1) {
            printf("Error: Failed to wait for ping response for sequence %d\n", i);
            continue;
        } else if(rv == 0) {
            printf("Request timed out for sequence %d\n", i);
            continue;
        }

        // Receive the packet
        struct sockaddr_in from;
        socklen_t fromlen = sizeof(from);
        if(recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&from, &fromlen) == -1) {
            printf("Error: Failed to receive ping response for sequence %d\n", i);
            continue;
        }
        received++;

        // Record the ending time for each loop
        gettimeofday(&tvend, NULL);

        printf("Reply from %s: bytes=%d time=%ldms TTL=%d\n",
            inet_ntoa(from.sin_addr), sizeof(buffer),
            (tvend.tv_usec - tvstart.tv_usec) / 1000 + (tvend.tv_sec - tvstart.tv_sec) * 1000,
            0);

    }

    printf("\nPing statistics for %d.%d.%d.%d:\n", addr.sin_addr.s_addr&0xFF, (addr.sin_addr.s_addr>>8)&0xFF,
                                                   (addr.sin_addr.s_addr>>16)&0xFF, (addr.sin_addr.s_addr>>24)&0xFF);
    printf("    Packets: Sent = %d, Received = %d, Lost = %d (%0.2f%% loss)\n",
        sent, received, sent-received, ((sent-received)/(float)sent)*100);

    close(sockfd);
    return EXIT_SUCCESS;
}