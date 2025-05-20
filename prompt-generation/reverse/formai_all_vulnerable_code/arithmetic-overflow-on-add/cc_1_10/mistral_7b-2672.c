//MISTRAL-7B DATASET v1.0 Category: Internet Speed Test Application ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <sys/socket.h>
#include <time.h>

#define SERVER_IP "192.168.1.1"
#define BUFFER_SIZE 1024
#define PACKET_SIZE 65535
#define NUM_PACKETS 10

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sockfd, i, j, total_sent, total_received, packet_size;
    struct sockaddr_in serv_addr;
    char *buffer, send_buf[PACKET_SIZE], recv_buf[BUFFER_SIZE];
    struct timeval start, end;
    long long int data_sent, data_received, elapsed_time, throughput;

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
        error("Socket creation failed.");

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(5005);
    inet_pton(AF_INET, SERVER_IP, &serv_addr.sin_addr);

    buffer = calloc(1, PACKET_SIZE);
    if (!buffer)
        error("Memory allocation failed.");

    gettimeofday(&start, NULL);

    for (i = 0; i < NUM_PACKETS; i++) {
        packet_size = PACKET_SIZE;
        total_sent += packet_size;

        for (j = 0; j < packet_size; j++)
            send_buf[j] = 'A' + (i * PACKET_SIZE + j) % 26;

        if (sendto(sockfd, send_buf, packet_size, 0,
                   (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
            error("Sendto failed.");

        if (recvfrom(sockfd, recv_buf, BUFFER_SIZE, 0, NULL, NULL) < 0)
            error("Recvfrom failed.");

        total_received += BUFFER_SIZE;
    }

    gettimeofday(&end, NULL);

    close(sockfd);
    free(buffer);

    data_sent = (long long int)total_sent;
    data_received = (long long int)total_received;
    elapsed_time = (end.tv_sec * 1000 + end.tv_usec / 1000) -
                  (start.tv_sec * 1000 + start.tv_usec / 1000);

    throughput = (data_sent / elapsed_time);

    printf("Internet Speed Test Results:\n");
    printf("Data sent: %lld bytes\n", data_sent);
    printf("Data received: %lld bytes\n", data_received);
    printf("Elapsed time: %lld ms\n", elapsed_time);
    printf("Throughput: %lld bytes/s\n", throughput);

    return 0;
}