//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define BUFFER_SIZE 8192

void error(const char *msg) {
    perror(msg);
    exit(1);
}

double get_download_speed(const char *url) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    time_t start_time, end_time;
    ssize_t bytes_received = 0;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // HTTP port
    inet_pton(AF_INET, url, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        error("ERROR connecting");
    }

    // Send a simple HTTP GET request
    const char *get_request = "GET /speedtest/random4000x4000.jpg HTTP/1.1\r\n"
                              "Host: speed.hetzner.de\r\n"
                              "Connection: close\r\n\r\n";
    send(sockfd, get_request, strlen(get_request), 0);

    start_time = time(NULL);
    while ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        // Intentionally receive data
    }
    end_time = time(NULL);

    close(sockfd);
    
    // Calculate download speed in Mbps
    double speed_mbps = (bytes_received * 8.0) / (end_time - start_time) / 1024 / 1024;
    return speed_mbps;
}

double get_upload_speed(const char *url, const char *data) {
    int sockfd;
    struct sockaddr_in server_addr;
    time_t start_time, end_time;
    ssize_t bytes_sent = 0;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // HTTP port
    inet_pton(AF_INET, url, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        error("ERROR connecting");
    }

    // Prepare and send POST data
    const char *post_request = "POST /upload HTTP/1.1\r\n"
                               "Host: speedtest.example.com\r\n"
                               "Content-Length: 3000\r\n"
                               "Connection: close\r\n\r\n";

    send(sockfd, post_request, strlen(post_request), 0);

    start_time = time(NULL);
    bytes_sent = send(sockfd, data, 3000, 0);
    end_time = time(NULL);

    close(sockfd);
    
    // Calculate upload speed in Mbps
    double speed_mbps = (bytes_sent * 8.0) / (end_time - start_time) / 1024 / 1024;
    return speed_mbps;
}

int main() {
    const char *test_download_url = "speed.hetzner.de"; // Change with a valid test URL
    const char *test_upload_url = "speedtest.example.com"; // Change with a valid upload server
    char upload_data[3000];
    
    // Prepare dummy upload data
    memset(upload_data, 'A', 3000);
    
    printf("Starting Internet Speed Test...\n");

    double download_speed = get_download_speed(test_download_url);
    printf("Download Speed: %.2f Mbps\n", download_speed);

    double upload_speed = get_upload_speed(test_upload_url, upload_data);
    printf("Upload Speed: %.2f Mbps\n", upload_speed);

    return 0;
}