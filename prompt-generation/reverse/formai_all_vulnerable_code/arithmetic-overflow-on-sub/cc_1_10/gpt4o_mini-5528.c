//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER "speed.hetzner.de"  // Speed test server
#define PORT 80                     // HTTP port
#define BUFFER_SIZE 4096            // Buffer size for data transmission

// Function to get the current time in milliseconds
long get_current_time_ms() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (ts.tv_sec * 1000) + (ts.tv_nsec / 1000000);
}

// Function to create a socket and connect to the speed test server
int connect_to_server(const char *server, int port) {
    int sock;
    struct sockaddr_in server_addr;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, server, &server_addr.sin_addr) <= 0) {
        perror("Invalid address or address not supported");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        return -1;
    }

    return sock;
}

// Function to perform download speed test
double perform_download_speed_test(int sock) {
    char buffer[BUFFER_SIZE];
    long start_time, end_time;
    size_t bytes_received = 0;

    // Send a GET request to the server
    char *request = "GET /100MB.bin HTTP/1.1\r\nHost: " SERVER "\r\nConnection: close\r\n\r\n";
    send(sock, request, strlen(request), 0);

    // Record the start time
    start_time = get_current_time_ms();

    // Receive data
    while (recv(sock, buffer, BUFFER_SIZE, 0) > 0) {
        bytes_received += sizeof(buffer);
    }

    // Record the end time
    end_time = get_current_time_ms();
    double duration_sec = (end_time - start_time) / 1000.0;

    // Calculate download speed in Mbps
    double speed_mbps = (bytes_received * 8) / (duration_sec * 1024 * 1024);
    
    return speed_mbps;
}

// Function to perform upload speed test (dummy upload as true upload tests require server support)
double perform_upload_speed_test(const char *server) {
    char buffer[BUFFER_SIZE];
    long start_time, end_time;
    size_t bytes_sent = 0;
    int sock;

    memset(buffer, 'A', sizeof(buffer)); // Prepare dummy data

    if ((sock = connect_to_server(server, PORT)) < 0) {
        return -1;
    }

    // Send a POST request to the server (this is a dummy upload)
    char *request = "POST /upload HTTP/1.1\r\nHost: " SERVER "\r\nContent-Length: 1048576\r\nConnection: close\r\n\r\n";
    send(sock, request, strlen(request), 0);

    // Record the start time
    start_time = get_current_time_ms();

    // Simulate upload
    while (bytes_sent < 1024 * 1024) {
        send(sock, buffer, sizeof(buffer), 0);
        bytes_sent += sizeof(buffer);
    }

    // Record the end time
    end_time = get_current_time_ms();
    double duration_sec = (end_time - start_time) / 1000.0;

    // Calculate upload speed in Mbps
    double speed_mbps = (bytes_sent * 8) / (duration_sec * 1024 * 1024);

    close(sock);
    return speed_mbps;
}

int main() {
    printf("Welcome to the C Internet Speed Test!\n");
    printf("Testing download speed...\n");

    int sock_download = connect_to_server(SERVER, PORT);
    if (sock_download < 0) {
        exit(EXIT_FAILURE);
    }
    
    double download_speed = perform_download_speed_test(sock_download);
    close(sock_download);
    
    printf("Download speed: %.2f Mbps\n", download_speed);

    printf("Testing upload speed...\n");
    double upload_speed = perform_upload_speed_test(SERVER);
    
    if (upload_speed < 0) {
        exit(EXIT_FAILURE);
    }
    
    printf("Upload speed: %.2f Mbps\n", upload_speed);

    printf("Speed test completed. Thank you for using our service!\n");
    return 0;
}