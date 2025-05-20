//Code Llama-13B DATASET v1.0 Category: Network Ping Test ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <errno.h>

#define PING_COUNT 5
#define PING_INTERVAL 1
#define PING_TIMEOUT 2

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    struct hostent *host;
    char hostname[256];
    char *ip_addr;
    int i;
    int ret;
    int seq;
    struct timeval start_time, end_time;
    float time_taken;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname/IP address>\n", argv[0]);
        exit(1);
    }

    strncpy(hostname, argv[1], sizeof(hostname));
    host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Failed to resolve hostname: %s\n", hstrerror(h_errno));
        exit(1);
    }

    ip_addr = inet_ntoa(*(struct in_addr *)*host->h_addr_list);
    if (ip_addr == NULL) {
        fprintf(stderr, "Failed to convert IP address\n");
        exit(1);
    }

    printf("Pinging %s (%s) with %d bytes of data:\n", hostname, ip_addr, sizeof(struct timeval));

    sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sock < 0) {
        perror("Failed to create socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip_addr);
    server_addr.sin_port = 0;

    for (i = 0; i < PING_COUNT; i++) {
        seq = i + 1;

        ret = sendto(sock, &seq, sizeof(seq), 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
        if (ret < 0) {
            perror("Failed to send ping request");
            exit(1);
        }

        printf("Ping %d sent, waiting for response...\n", seq);

        ret = recvfrom(sock, &seq, sizeof(seq), 0, NULL, NULL);
        if (ret < 0) {
            perror("Failed to receive ping response");
            exit(1);
        }

        gettimeofday(&end_time, NULL);
        time_taken = (end_time.tv_sec - start_time.tv_sec) * 1000.0 + (end_time.tv_usec - start_time.tv_usec) / 1000.0;

        printf("Ping %d received in %f ms\n", seq, time_taken);
    }

    close(sock);

    return 0;
}