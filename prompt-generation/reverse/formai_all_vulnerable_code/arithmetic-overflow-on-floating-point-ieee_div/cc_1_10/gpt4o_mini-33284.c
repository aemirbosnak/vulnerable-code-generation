//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define SERVER_IP "cachefly.cachefly.net"  // Sample Speed Test Server
#define PORT 80
#define REQUEST "GET /500KB.zip HTTP/1.1\r\nHost: cachefly.cachefly.net\r\nConnection: close\r\n\r\n"
#define BUFFER_SIZE 1024
#define FILE_SIZE (500 * 1024) // 500 KB

void calculate_speed(double time_spent, int bytes) {
    double mbps = (bytes / (1024.0 * 1024.0)) / (time_spent / 1000.0);
    printf("Speed: %.2f Mbps\n", mbps);
}

void download_test() {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;
    struct timeval start, end;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection Failed");
        close(sock);
        return;
    }

    send(sock, REQUEST, strlen(REQUEST), 0);

    gettimeofday(&start, NULL);
    int total_bytes_received = 0;
    while ((bytes_received = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        total_bytes_received += bytes_received;
    }
    gettimeofday(&end, NULL);

    close(sock);

    double time_spent = (end.tv_sec - start.tv_sec) * 1000.0; // in milliseconds
    time_spent += (end.tv_usec - start.tv_usec) / 1000.0; // in milliseconds

    printf("Downloaded %d bytes in %.2f ms\n", total_bytes_received, time_spent);
    calculate_speed(time_spent, total_bytes_received);
}

void upload_test() {
    // Simulating the upload test
    // In a real case, you would send a file instead of just sending zeros
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_sent;
    struct timeval start, end;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection Failed");
        close(sock);
        return;
    }

    memset(buffer, 'A', BUFFER_SIZE);
    gettimeofday(&start, NULL);
    for (int i = 0; i < FILE_SIZE / BUFFER_SIZE; i++) {
        bytes_sent = send(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_sent < 0) {
            perror("Sending failed");
            break;
        }
    }
    gettimeofday(&end, NULL);
    close(sock);

    double time_spent = (end.tv_sec - start.tv_sec) * 1000.0; // in milliseconds
    time_spent += (end.tv_usec - start.tv_usec) / 1000.0; // in milliseconds

    printf("Uploaded %d bytes in %.2f ms\n", FILE_SIZE, time_spent);
    calculate_speed(time_spent, FILE_SIZE);
}

int main() {
    printf("Starting Internet Speed Test...\n");
    download_test();
    upload_test();
    printf("Test complete. Thank you for using the speed test.\n");
    return 0;
}