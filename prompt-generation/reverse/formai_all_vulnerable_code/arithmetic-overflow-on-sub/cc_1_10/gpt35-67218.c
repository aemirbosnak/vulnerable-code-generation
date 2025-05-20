//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

#define PORT 80
#define REQUEST "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n"
#define BUF_SIZE 8196
#define NUM_BYTES 10000000
#define NUM_TESTS 10

double run_test(struct sockaddr_in *dest_addr) {
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    clock_t start_time = clock();
    int connect_result = connect(sock_fd, (struct sockaddr*) dest_addr, sizeof(struct sockaddr_in));
    if (connect_result == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }
    send(sock_fd, REQUEST, sizeof(REQUEST) - 1, 0);
    unsigned char buf[BUF_SIZE];
    int num_received = 0;
    while (num_received < NUM_BYTES) {
        int num_received_now = recv(sock_fd, buf, BUF_SIZE, 0);
        if (num_received_now == -1) {
            perror("recv");
            exit(EXIT_FAILURE);
        }
        num_received += num_received_now;
    }
    clock_t end_time = clock();
    double elapsed_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    close(sock_fd);
    return elapsed_time;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s IP-address\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    struct sockaddr_in dest_addr;
    memset(&dest_addr, 0, sizeof(struct sockaddr_in));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_addr.s_addr = inet_addr(argv[1]);
    dest_addr.sin_port = htons(PORT);

    srand(time(NULL));
    double times[NUM_TESTS];
    for (int i = 0; i < NUM_TESTS; i++) {
        times[i] = run_test(&dest_addr);
        // Random wait to simulate network congestion
        usleep((rand() % 500) * 1000);
    }
    double total_time = 0;
    for (int i = 0; i < NUM_TESTS; i++) {
        total_time += times[i];
    }
    double mean_time = total_time / NUM_TESTS;
    double variance = 0;
    for (int i = 0; i < NUM_TESTS; i++) {
        variance += pow(times[i] - mean_time, 2);
    }
    variance /= NUM_TESTS;
    double stddev = sqrt(variance);

    printf("Mean download time: %.2f seconds\n", mean_time);
    printf("Standard deviation of download time: %.2f seconds\n", stddev);

    return 0;
}