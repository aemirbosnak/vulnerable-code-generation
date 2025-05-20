//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_IP "speed.hetzner.de"  // Change to an appropriate speed test server
#define SERVER_PORT 80
#define BUFFER_SIZE 1024

void check_speed(long total_bytes, double elapsed_time) {
    double speed_mbps = (total_bytes * 8.0) / (1024 * 1024 * elapsed_time);
    printf("Download speed: %.2f Mbps\n", speed_mbps);
}

int download_file(const char* filename, const char* url) {
    int sock;
    struct sockaddr_in server_addr;
    char request[256], buffer[BUFFER_SIZE];
    ssize_t bytes_received;
    long total_bytes = 0;
    time_t start_time, end_time;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Failed to create socket");
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sock);
        return -1;
    }

    snprintf(request, sizeof(request),
             "GET /%s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n",
             filename, SERVER_IP);
    
    send(sock, request, strlen(request), 0);

    start_time = time(NULL);

    while ((bytes_received = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        total_bytes += bytes_received;
    }

    end_time = time(NULL);

    if (bytes_received < 0) {
        perror("Receiving failed");
    }

    close(sock);
    check_speed(total_bytes, difftime(end_time, start_time));
    return 0;
}

void print_intro() {
    printf("Welcome to the C Internet Speed Test!\n");
    printf("This minimalist application tests your download speed.\n\n");
}

int main(int argc, char *argv[]) {
    print_intro();
    const char *filename = "100MB.bin";  // This file should be available on the server

    if (argc > 1) {
        filename = argv[1];
    }

    printf("Testing download speed for file: %s\n", filename);
    download_file(filename, SERVER_IP);

    return 0;
}