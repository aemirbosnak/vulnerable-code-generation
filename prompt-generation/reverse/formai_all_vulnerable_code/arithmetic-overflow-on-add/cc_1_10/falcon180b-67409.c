//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define NUM_REQUESTS 10
#define SERVER "speedtest.net"
#define PORT 80

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char *data;
    int data_len;
    char *response;
    int response_len;
    int total_bytes_received = 0;
    double total_time = 0.0;
    double avg_speed = 0.0;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    for (int i = 0; i < NUM_REQUESTS; i++) {
        data = malloc(BUFFER_SIZE);
        data_len = sprintf(data, "GET /speedtest/1MB.zip HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", SERVER);
        send(sock, data, data_len, 0);

        response = malloc(BUFFER_SIZE);
        response_len = recv(sock, response, BUFFER_SIZE, 0);

        total_bytes_received += response_len;
        total_time += (double)response_len / 1024.0; // in KB

        free(data);
        free(response);
    }

    avg_speed = total_bytes_received / total_time;
    printf("Average download speed: %.2f KB/s\n", avg_speed);

    close(sock);
    return 0;
}