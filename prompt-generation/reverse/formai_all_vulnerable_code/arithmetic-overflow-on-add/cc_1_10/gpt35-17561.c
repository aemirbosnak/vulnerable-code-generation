//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

#define NANOSECONDS_PER_SEC 1000000000L

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    struct addrinfo *result;
    int error = getaddrinfo(argv[1], NULL, &hints, &result);
    if (error) {
        fprintf(stderr, "Error looking up %s: %s\n", argv[1], gai_strerror(error));
        exit(1);
    }

    struct sockaddr_in *addr = (struct sockaddr_in *)result->ai_addr;
    char ip_addr[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(addr->sin_addr), ip_addr, INET_ADDRSTRLEN);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Error creating socket");
        exit(1);
    }

    struct timespec start_time, end_time, delta_time;
    clock_gettime(CLOCK_REALTIME, &start_time);

    if (connect(sock, (struct sockaddr *)addr, sizeof(struct sockaddr_in)) == -1) {
        perror("Error connecting to server");
        exit(1);
    }

    clock_gettime(CLOCK_REALTIME, &end_time);

    delta_time.tv_sec = end_time.tv_sec - start_time.tv_sec;
    if (end_time.tv_nsec < start_time.tv_nsec) {
        delta_time.tv_sec -= 1;
        delta_time.tv_nsec = NANOSECONDS_PER_SEC + end_time.tv_nsec - start_time.tv_nsec;
    } else {
        delta_time.tv_nsec = end_time.tv_nsec - start_time.tv_nsec;
    }

    double delta_milliseconds = delta_time.tv_sec * 1000.0 + delta_time.tv_nsec / (1000000.0);
    double throughput = 8.0 / delta_milliseconds;

    printf("Connected to %s (%s) in %.3f ms, throughput: %.2f Mbps\n", argv[1], ip_addr, delta_milliseconds, throughput);

    return 0;
}