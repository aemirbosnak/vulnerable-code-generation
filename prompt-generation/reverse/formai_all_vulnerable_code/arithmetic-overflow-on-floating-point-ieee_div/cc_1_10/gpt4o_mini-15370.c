//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define SERVER_IP "speed.hetzner.de"
#define SERVER_PORT 80
#define BUFFER_SIZE 8192
#define TEST_DURATION 5

void check_speed(long data_size, double elapsed_time, const char* action) {
    double speed_mbps = (data_size * 8.0) / (elapsed_time * 1024 * 1024);
    printf("Estimated %s speed: %.2f Mbps\n", action, speed_mbps);
}

void download_test() {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    long total_bytes = 0;
    time_t start_time, end_time;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Sending a basic HTTP GET request
    const char *http_request = "GET /100MB.bin HTTP/1.1\r\nHost: speed.hetzner.de\r\nConnection: close\r\n\r\n";
    send(sock, http_request, strlen(http_request), 0);

    start_time = time(NULL);
    while (1) {
        ssize_t bytes_received = recv(sock, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            break;
        }
        total_bytes += bytes_received;
    }
    end_time = time(NULL);

    close(sock);
    check_speed(total_bytes, difftime(end_time, start_time), "download");
}

void upload_test() {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    long total_bytes = 0;
    time_t start_time, end_time;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Prepare to upload data
    char data_to_send[BUFFER_SIZE];
    memset(data_to_send, 'A', BUFFER_SIZE); // Fill data with 'A'
    
    start_time = time(NULL);
    for (int i = 0; i < TEST_DURATION; ++i) {
        ssize_t bytes_sent = send(sock, data_to_send, sizeof(data_to_send), 0);
        if (bytes_sent <= 0) {
            break;
        }
        total_bytes += bytes_sent;
        sleep(1);
    }
    end_time = time(NULL);

    close(sock);
    check_speed(total_bytes, difftime(end_time, start_time), "upload");
}

int main() {
    printf("Welcome to the Internet Speed Test Application!\n");
    printf("Testing download speed...\n");
    download_test();
    printf("Testing upload speed...\n");
    upload_test();
    printf("Speed test completed successfully.\n");
    return 0;
}