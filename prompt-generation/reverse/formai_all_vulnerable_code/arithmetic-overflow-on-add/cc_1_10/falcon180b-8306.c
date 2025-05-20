//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>

#define MAX_HOSTNAME 64
#define MAX_PAYLOAD 64
#define MAX_TARGET_IP 16
#define MAX_TARGET_PORT 6
#define MAX_RESPONSE_TIME_MS 1000
#define MIN_RESPONSE_TIME_MS 1

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <hostname> <port> <payload>\n", argv[0]);
        return 1;
    }

    char hostname[MAX_HOSTNAME];
    strcpy(hostname, argv[1]);

    char target_ip[MAX_TARGET_IP];
    strcpy(target_ip, argv[1]);

    int port = atoi(argv[2]);

    char payload[MAX_PAYLOAD];
    strcpy(payload, argv[3]);

    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    struct sockaddr_in target_addr;
    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(port);
    inet_pton(AF_INET, target_ip, &target_addr.sin_addr);

    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);

    if (sendto(sock, payload, strlen(payload), 0, (struct sockaddr *)&target_addr, sizeof(target_addr)) == -1) {
        printf("Error sending packet: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    int response_len = recvfrom(sock, payload, MAX_PAYLOAD, 0, NULL, NULL);
    if (response_len <= 0) {
        printf("No response received\n");
        close(sock);
        return 1;
    }

    gettimeofday(&end_time, NULL);

    long response_time_ms = (end_time.tv_sec - start_time.tv_sec) * 1000 + (end_time.tv_usec - start_time.tv_usec) / 1000;

    printf("Response received in %ld ms\n", response_time_ms);
    printf("Payload: %s\n", payload);

    close(sock);
    return 0;
}