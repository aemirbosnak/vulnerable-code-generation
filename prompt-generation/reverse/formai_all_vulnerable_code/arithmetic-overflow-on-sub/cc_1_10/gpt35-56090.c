//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <server-ip>\n", argv[0]);
        exit(1);
    }

    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        printf("Failed to create socket\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        printf("Invalid IP address\n");
        exit(1);
    }

    if (connect(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("Failed to connect to server\n");
        exit(1);
    }

    char request[MAX_BUFFER_SIZE];
    snprintf(request, MAX_BUFFER_SIZE, "GET /speedtest/random1000x1000.jpg HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", argv[1]);

    printf("Testing internet speed...\n");

    clock_t start_time = clock();

    if (send(sock_fd, request, strlen(request), 0) < 0) {
        printf("Failed to send request\n");
        exit(1);
    }

    char response[MAX_BUFFER_SIZE];
    int total_bytes = 0;
    int bytes_received;
    while ((bytes_received = recv(sock_fd, response, MAX_BUFFER_SIZE-1, 0)) > 0) {
        total_bytes += bytes_received;
    }
    if (bytes_received < 0) {
        printf("Failed to receive response\n");
        exit(1);
    }

    clock_t end_time = clock();

    double time_elapsed = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    double download_speed = ((double) total_bytes) / (1024 * 1024 * time_elapsed);

    printf("Download speed: %lf Mbps\n", download_speed);

    close(sock_fd);

    return 0;
}