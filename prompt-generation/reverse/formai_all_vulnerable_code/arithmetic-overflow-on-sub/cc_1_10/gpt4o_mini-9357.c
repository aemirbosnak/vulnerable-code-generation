//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/time.h>

#define SERVER_IP "192.168.1.1" // Change this to your own speed test server IP
#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

// Function to perform the speed test
void perform_speed_test() {
    int sock;
    struct sockaddr_in server;
    char buffer[BUFFER_SIZE];
    struct timeval start, end;
    long elapsed_time;
    size_t bytes_sent = 0;
    size_t bytes_received = 0;
    
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Could not create socket");
        return;
    }
    
    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, SERVER_IP, &server.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        close(sock);
        return;
    }

    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("Connection failed");
        close(sock);
        return;
    }

    printf("Connected to the speed test server.\n");

    // Start the timer for upload speed test
    gettimeofday(&start, NULL);
    for (int i = 0; i < 100; i++) {
        int n = snprintf(buffer, sizeof(buffer), "Hello, this is a speed test packet %d", i);
        bytes_sent += send(sock, buffer, n, 0);
    }

    gettimeofday(&end, NULL);
    elapsed_time = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
    printf("Uploaded %zu bytes in %ld microseconds.\n", bytes_sent, elapsed_time);

    // Start the timer for download speed test
    gettimeofday(&start, NULL);
    for (int i = 0; i < 100; i++) {
        bytes_received += recv(sock, buffer, BUFFER_SIZE, 0);
    }

    gettimeofday(&end, NULL);
    elapsed_time = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
    printf("Downloaded %zu bytes in %ld microseconds.\n", bytes_received, elapsed_time);

    // Calculate speeds
    double upload_speed = (double)bytes_sent / elapsed_time * 1000000; // bytes per second
    double download_speed = (double)bytes_received / elapsed_time * 1000000; // bytes per second
    printf("Upload speed: %.2f MB/s\n", upload_speed / (1024 * 1024));
    printf("Download speed: %.2f MB/s\n", download_speed / (1024 * 1024));

    close(sock);
}

int main() {
    printf("Welcome to the Internet Speed Test Application!\n");
    perform_speed_test();
    printf("Speed test completed.\n");
    
    return 0;
}