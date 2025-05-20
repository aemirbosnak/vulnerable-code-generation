//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <time.h>

#define SERVER_IP "speed.hetzner.de"
#define SERVER_PORT 3000
#define BUFFER_SIZE 1024

void handle_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

double measure_download_speed(int sockfd) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;
    size_t total_bytes = 0;
    time_t start_time, end_time;

    start_time = time(NULL);
    
    while ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        total_bytes += bytes_received;
    }

    if (bytes_received < 0) {
        handle_error("recv failed");
    }

    end_time = time(NULL);
    double duration = difftime(end_time, start_time);
    return (total_bytes * 8) / (duration); // Speed in bits per second
}

double measure_upload_speed(int sockfd) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 'A', BUFFER_SIZE);
    ssize_t bytes_sent;
    size_t total_bytes = 0;
    time_t start_time, end_time;

    start_time = time(NULL);
    
    while ((total_bytes < 10 * BUFFER_SIZE)) { // Upload 10 times the buffer size
        bytes_sent = send(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_sent < 0) {
            handle_error("send failed");
        }
        total_bytes += bytes_sent;
    }
    
    end_time = time(NULL);
    double duration = difftime(end_time, start_time);
    return (total_bytes * 8) / (duration); // Speed in bits per second
}

void run_speed_test() {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        handle_error("socket creation failed");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        handle_error("invalid address/ address not supported");
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("connection failed");
    }

    printf("Measuring download speed...\n");
    double download_speed = measure_download_speed(sockfd);
    printf("Download Speed: %.2f Mbps\n", download_speed / 1e6);

    printf("Measuring upload speed...\n");
    double upload_speed = measure_upload_speed(sockfd);
    printf("Upload Speed: %.2f Mbps\n", upload_speed / 1e6);
    
    close(sockfd);
}

int main() {
    printf("Starting Internet Speed Test...\n");
    run_speed_test();
    printf("Test complete.\n");
    return 0;
}