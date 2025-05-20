//FormAI DATASET v1.0 Category: Network Ping Test ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // check for correct number of command line arguments
    if (argc != 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        exit(1);
    }

    // create a UDP socket
    int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sock < 0) {
        perror("socket() failed");
        exit(1);
    }

    // set socket options
    int timeout = 1000;  // set ping timeout to 1 second
    struct timeval tv;
    tv.tv_sec = timeout / 1000;
    tv.tv_usec = (timeout % 1000) * 1000;
    if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0) {
        perror("setsockopt() failed");
        exit(1);
    }

    // specify target IP address
    struct sockaddr_in target_addr;
    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(0);  // random free port
    if (inet_aton(argv[1], &target_addr.sin_addr) == 0) {
        printf("Invalid IP address: %s\n", argv[1]);
        exit(1);
    }

    // create buffer for ping packet
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    // create ping packet
    struct timeval *tvsend = (struct timeval *)buffer;
    gettimeofday(tvsend, NULL);

    // send ping packet to target
    if (sendto(sock, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&target_addr, sizeof(target_addr)) < 0) {
        perror("sendto() failed");
        exit(1);
    }

    // create buffer for response packet
    struct sockaddr_in response_addr;
    socklen_t response_addr_len = sizeof(response_addr);
    memset(buffer, 0, BUFFER_SIZE);

    // wait for response packet
    if (recvfrom(sock, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&response_addr, &response_addr_len) < 0) {
        if (errno == EWOULDBLOCK) {
            printf("Ping timeout\n");
        } else {
            perror("recvfrom() failed");
        }
        close(sock);
        exit(1);
    }

    // calculate round trip time
    struct timeval *tvsent = (struct timeval *)buffer;
    struct timeval tvrecv;
    gettimeofday(&tvrecv, NULL);
    long long rtt = (tvrecv.tv_sec - tvsent->tv_sec) * 1000LL + (tvrecv.tv_usec - tvsent->tv_usec) / 1000LL;
    printf("Ping reply from %s: time=%lldms\n", inet_ntoa(response_addr.sin_addr), rtt);

    // close socket and exit
    close(sock);
    return 0;
}