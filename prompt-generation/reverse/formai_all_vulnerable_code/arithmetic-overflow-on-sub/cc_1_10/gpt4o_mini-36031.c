//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

void print_speed(float speed) {
    printf("Speed: %.2f MB/s\n", speed);
}

float measure_download_speed(int sock) {
    char buffer[BUFFER_SIZE];
    size_t total_bytes = 0;
    clock_t start_time = clock();

    // Request large data from the server
    send(sock, "GET DATA", strlen("GET DATA"), 0);

    // Read data until the transfer is complete
    while (1) {
        ssize_t bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) break;
        total_bytes += bytes_received;
    }

    clock_t end_time = clock();
    float duration_in_seconds = (float)(end_time - start_time) / CLOCKS_PER_SEC;
    return (total_bytes / (1024.0 * 1024.0)) / duration_in_seconds; // MB/s
}

float measure_upload_speed(int sock) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 'X', BUFFER_SIZE);
    size_t total_bytes = 0;
    clock_t start_time = clock();

    // Upload data to the server
    for (int i = 0; i < 100; i++) { 
        ssize_t bytes_sent = send(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_sent < 0) {
            fprintf(stderr, "Upload error\n");
            break;
        }
        total_bytes += bytes_sent;
    }

    clock_t end_time = clock();
    float duration_in_seconds = (float)(end_time - start_time) / CLOCKS_PER_SEC;
    return (total_bytes / (1024.0 * 1024.0)) / duration_in_seconds; // MB/s
}

int main() {
    int sock;
    struct sockaddr_in server_addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sock);
        return EXIT_FAILURE;
    }

    printf("Starting speed test...\n");
    
    float download_speed = measure_download_speed(sock);
    print_speed(download_speed);

    float upload_speed = measure_upload_speed(sock);
    print_speed(upload_speed);

    close(sock);
    return EXIT_SUCCESS;
}