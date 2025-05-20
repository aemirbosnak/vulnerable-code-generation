//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

#define SERVER_IP "speed.hetzner.de" // A reliable speed test server
#define PORT 80
#define BUFFER_SIZE 8192

void introspectiveLog(const char *message) {
    time_t now;
    time(&now);
    printf("[%s] %s\n", ctime(&now), message);
}

void downloadSpeedTest(int socket_fd) {
    char buffer[BUFFER_SIZE];
    size_t total_bytes = 0;
    time_t start_time, end_time;

    // Send a GET request
    const char *request = "GET /100MB.bin HTTP/1.1\r\nHost: speed.hetzner.de\r\nConnection: close\r\n\r\n";
    send(socket_fd, request, strlen(request), 0);
    
    start_time = time(NULL);
    
    // Read response
    while (recv(socket_fd, buffer, sizeof(buffer), 0) > 0) {
        total_bytes += strlen(buffer);
    }
    
    end_time = time(NULL);
    double seconds = difftime(end_time, start_time);
    double speed_mbps = (total_bytes * 8) / (1000000.0 * seconds);
    
    introspectiveLog("Downloaded file size in bytes:");
    printf("%zu bytes\n", total_bytes);
    introspectiveLog("Time taken for download:");
    printf("%.2f seconds\n", seconds);
    introspectiveLog("Download speed:");
    printf("%.2f Mbps\n", speed_mbps);
}

void uploadSpeedTest(int socket_fd) {
    char buffer[BUFFER_SIZE];
    size_t total_bytes = 0;
    time_t start_time, end_time;

    memset(buffer, 'A', sizeof(buffer)); // Generate a buffer filled with 'A'

    start_time = time(NULL);
    
    // Simulate upload by sending data
    for (size_t i = 0; i < 1024; i++) {
        total_bytes += send(socket_fd, buffer, sizeof(buffer), 0);
    }

    end_time = time(NULL);
    double seconds = difftime(end_time, start_time);
    double speed_mbps = (total_bytes * 8) / (1000000.0 * seconds);
    
    introspectiveLog("Uploaded data size in bytes:");
    printf("%zu bytes\n", total_bytes);
    introspectiveLog("Time taken for upload:");
    printf("%.2f seconds\n", seconds);
    introspectiveLog("Upload speed:");
    printf("%.2f Mbps\n", speed_mbps);
}

int main() {
    introspectiveLog("Starting Internet Speed Test Application...");

    // Create a socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    if (inet_pton(AF_INET, SERVER_IP, &server.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        close(socket_fd);
        return EXIT_FAILURE;
    }

    if (connect(socket_fd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connection failed");
        close(socket_fd);
        return EXIT_FAILURE;
    }

    introspectiveLog("Connection established... Starting download speed test.");
    downloadSpeedTest(socket_fd);

    introspectiveLog("Re-establishing connection for upload speed test...");
    close(socket_fd); // Close the old connection
    socket_fd = socket(AF_INET, SOCK_STREAM, 0); // Create a new socket
    if (connect(socket_fd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connection failed");
        close(socket_fd);
        return EXIT_FAILURE;
    }

    uploadSpeedTest(socket_fd);

    introspectiveLog("Speed test completed!");
    
    close(socket_fd);
    return EXIT_SUCCESS;
}