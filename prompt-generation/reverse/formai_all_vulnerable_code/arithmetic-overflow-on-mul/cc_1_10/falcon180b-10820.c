//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <sys/resource.h>

struct qos_settings {
    int max_bandwidth;
    int min_bandwidth;
    int max_delay;
    int min_delay;
    int max_packet_size;
    int min_packet_size;
};

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s interface\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct qos_settings settings = {
       .max_bandwidth = 1000000,
       .min_bandwidth = 500000,
       .max_delay = 50,
       .min_delay = 10,
       .max_packet_size = 1500,
       .min_packet_size = 64,
    };

    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9);
    inet_pton(AF_INET, argv[1], &addr.sin_addr);

    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    struct rlimit rlim;
    rlim.rlim_cur = settings.max_bandwidth * 1024;
    rlim.rlim_max = settings.max_bandwidth * 1024;
    if (setrlimit(RLIMIT_RTPRIO, &rlim) == -1) {
        perror("setrlimit");
        exit(EXIT_FAILURE);
    }

    while (1) {
        struct timeval tv;
        gettimeofday(&tv, NULL);

        int64_t now = tv.tv_sec * 1000000 + tv.tv_usec;
        int64_t delta = now - settings.min_delay * 1000000;

        if (delta < 0) {
            usleep(settings.min_delay * 1000 - delta);
        }

        int packet_size = rand() % (settings.max_packet_size - settings.min_packet_size + 1) + settings.min_packet_size;
        char packet[packet_size];
        memset(packet, 'A', packet_size);

        if (sendto(sock, packet, packet_size, 0, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
            perror("sendto");
            exit(EXIT_FAILURE);
        }

        usleep(settings.max_delay * 1000);
    }

    return 0;
}