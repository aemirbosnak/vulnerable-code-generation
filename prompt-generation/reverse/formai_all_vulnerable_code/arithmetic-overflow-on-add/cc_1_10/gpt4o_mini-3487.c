//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define SERVER_PORT 8080 // Define a port for the server to listen on
#define BUFFER_SIZE 8192 // Define the buffer size for sending/receiving data

void error(const char *msg) {
    perror(msg);
    exit(1);
}

long long get_current_time_millis() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000LL + tv.tv_usec / 1000);
}

void test_download_speed(const char *server_ip) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    long long start_time, end_time;
    long long total_bytes = 0;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("ERROR opening socket");

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) 
        error("ERROR connecting to server");

    start_time = get_current_time_millis();
    
    // Request a large amount of data
    for (int i = 0; i < 100; i++) {
        send(sockfd, "GET /testdata HTTP/1.1\r\nHost: localhost\r\n\r\n", 45, 0);
        while (1) {
            ssize_t bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
            if (bytes_received <= 0)
                break;
            total_bytes += bytes_received;
        }
    }

    end_time = get_current_time_millis();

    printf("Downloaded %lld bytes in %lld milliseconds\n", total_bytes, end_time - start_time);
    printf("Download Speed: %.2f Mbps\n", (total_bytes * 8.0) / (end_time - start_time) * 1000.0 / 1000000.0);

    close(sockfd);
}

void test_upload_speed(const char *server_ip) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    long long start_time, end_time;
    long long total_bytes = 0;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("ERROR opening socket");

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) 
        error("ERROR connecting to server");

    start_time = get_current_time_millis();
    
    // Upload data repeatedly
    for (int i = 0; i < 100; i++) {
        memset(buffer, 'A', BUFFER_SIZE); // Fill buffer with dummy data
        ssize_t bytes_sent = send(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_sent <= 0) break;
        total_bytes += bytes_sent;
    }

    end_time = get_current_time_millis();

    printf("Uploaded %lld bytes in %lld milliseconds\n", total_bytes, end_time - start_time);
    printf("Upload Speed: %.2f Mbps\n", (total_bytes * 8.0) / (end_time - start_time) * 1000.0 / 1000000.0);

    close(sockfd);
}

int main() {
    const char *server_ip = "127.0.0.1"; // Connect to local server

    printf("Starting internet speed test...\n");

    test_download_speed(server_ip);
    test_upload_speed(server_ip);

    printf("Speed test completed.\n");
    
    return 0;
}