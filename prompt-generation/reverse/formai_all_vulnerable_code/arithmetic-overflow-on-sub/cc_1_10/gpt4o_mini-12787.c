//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <time.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1048576 // 1 MB

void print_speed(double speed) {
    printf("Internet Speed: %.2f MB/s\n", speed);
}

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char *buffer;
    double speed, total_time;
    struct timespec start, end;

    // Allocate memory for the buffer
    buffer = (char *)malloc(BUFFER_SIZE);
    if (buffer == NULL) {
        perror("Unable to allocate buffer");
        exit(EXIT_FAILURE);
    }
    
    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        free(buffer);
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Use localhost for testing

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to the server failed");
        close(sock);
        free(buffer);
        exit(EXIT_FAILURE);
    }

    // Speed test: Upload data
    clock_gettime(CLOCK_MONOTONIC, &start);
    if (send(sock, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Failed to send data");
        close(sock);
        free(buffer);
        exit(EXIT_FAILURE);
    }
    clock_gettime(CLOCK_MONOTONIC, &end);

    // Calculate upload duration
    total_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    speed = BUFFER_SIZE / (1024.0 * 1024.0 * total_time); // Convert bytes to MB

    print_speed(speed);

    // Speed test: Download data
    clock_gettime(CLOCK_MONOTONIC, &start);
    if (recv(sock, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Failed to receive data");
        close(sock);
        free(buffer);
        exit(EXIT_FAILURE);
    }
    clock_gettime(CLOCK_MONOTONIC, &end);

    // Calculate download duration
    total_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    speed = BUFFER_SIZE / (1024.0 * 1024.0 * total_time); // Convert bytes to MB

    print_speed(speed);

    // Cleanup
    close(sock);
    free(buffer);

    return 0;
}