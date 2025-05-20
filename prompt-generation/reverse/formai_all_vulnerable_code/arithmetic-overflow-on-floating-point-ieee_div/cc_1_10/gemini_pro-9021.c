//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <math.h>

#define SERVER_IP "8.8.8.8"
#define SERVER_PORT 53
#define BUF_SIZE 1024

double calculate_rtt(struct timeval *send_time, struct timeval *recv_time) {
    double rtt = (recv_time->tv_sec - send_time->tv_sec) * 1000.0;
    rtt += (recv_time->tv_usec - send_time->tv_usec) / 1000.0;
    return rtt;
}

double calculate_throughput(long recv_size, struct timeval *start_time, struct timeval *end_time) {
    double elapsed_time = (end_time->tv_sec - start_time->tv_sec) + (end_time->tv_usec - start_time->tv_usec) / 1000000.0;
    double throughput = (double)recv_size / elapsed_time;
    return throughput;
}

int main() {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    // Send a DNS query to the server
    char query[] = "www.google.com";
    sendto(sock, query, strlen(query) + 1, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Calculate the elapsed time and RTT
    struct timeval send_time, recv_time;
    gettimeofday(&send_time, NULL);

    char buf[BUF_SIZE];
    socklen_t len = sizeof(server_addr);
    recvfrom(sock, buf, BUF_SIZE, 0, (struct sockaddr *)&server_addr, &len);

    gettimeofday(&recv_time, NULL);
    double rtt = calculate_rtt(&send_time, &recv_time);
    printf("Round-Trip Time (RTT): %.2f ms\n", rtt);

    // Calculate the throughput
    long recv_size = strlen(buf) + 1;
    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);
    for (int i = 0; i < 10; i++) {
        sendto(sock, query, strlen(query) + 1, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
        recvfrom(sock, buf, BUF_SIZE, 0, (struct sockaddr *)&server_addr, &len);
    }
    gettimeofday(&end_time, NULL);

    double throughput = calculate_throughput(recv_size * 10, &start_time, &end_time);
    printf("Throughput: %.2f KB/s\n", throughput);

    close(sock);
    return 0;
}