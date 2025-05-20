//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 4096
#define TEST_FILE "testfile"
#define SERVER_ADDRESS "127.0.0.1"

void print_usage() {
    printf("Usage: ./speedtest_app\n");
    printf("This application measures download and upload speeds.\n");
}

float calculate_speed(int bytes, double seconds) {
    return (bytes / seconds) * 8 / 1e6; // Speed in Mbps
}

void perform_download_test() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;
    time_t start, end;
    int total_bytes = 0;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_ADDRESS, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Starting download test...\n");
    time(&start);

    while ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        total_bytes += bytes_received;
    }

    time(&end);
    
    if (bytes_received < 0) {
        perror("Error receiving data");
    }

    close(sockfd);

    double duration = difftime(end, start);
    printf("Downloaded %d bytes in %.2f seconds.\n", total_bytes, duration);
    printf("Download speed: %.2f Mbps\n", calculate_speed(total_bytes, duration));
}

void perform_upload_test() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_sent;
    time_t start, end;
    int total_bytes = BUFFER_SIZE;

    memset(buffer, 'A', BUFFER_SIZE); // Fill the buffer with dummy data

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_ADDRESS, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Starting upload test...\n");
    time(&start);

    bytes_sent = send(sockfd, buffer, total_bytes, 0);
    
    if (bytes_sent < 0) {
        perror("Error sending data");
    }

    time(&end);
    close(sockfd);

    double duration = difftime(end, start);
    printf("Uploaded %d bytes in %.2f seconds.\n", total_bytes, duration);
    printf("Upload speed: %.2f Mbps\n", calculate_speed(total_bytes, duration));
}

int main() {
    print_usage();
    
    perform_download_test();
    perform_upload_test();

    return 0;
}