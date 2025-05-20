//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define SERVER_IP "127.0.0.1"
#define PORT 8080
#define BUFFER_SIZE 1024
#define TEST_DURATION 5

void print_instructions() {
    printf("Welcome to the Peaceful Internet Speed Test Application.\n");
    printf("This tool will help you measure your download and upload speeds.\n");
    printf("Simply wait while we test your connection. Thank you for your patience.\n");
}

void download_speed_test(int sockfd) {
    char buffer[BUFFER_SIZE];
    size_t total_bytes_received = 0;
    time_t start_time = time(NULL);
    time_t elapsed_time = 0;

    printf("Starting download speed test...\n");
    while (elapsed_time < TEST_DURATION) {
        ssize_t bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break; // Stop on error or connection closure
        }
        total_bytes_received += bytes_received;
        elapsed_time = time(NULL) - start_time;
    }
    
    double speed_mbps = (total_bytes_received * 8.0) / (elapsed_time * 1024 * 1024);
    printf("Download speed: %.2f Mbps\n", speed_mbps);
}

void upload_speed_test(int sockfd) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 'A', BUFFER_SIZE);
    size_t total_bytes_sent = 0;
    time_t start_time = time(NULL);
    time_t elapsed_time = 0;

    printf("Starting upload speed test...\n");
    while (elapsed_time < TEST_DURATION) {
        ssize_t bytes_sent = send(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_sent <= 0) {
            break; // Stop on error or connection closure
        }
        total_bytes_sent += bytes_sent;
        elapsed_time = time(NULL) - start_time;
    }

    double speed_mbps = (total_bytes_sent * 8.0) / (elapsed_time * 1024 * 1024);
    printf("Upload speed: %.2f Mbps\n", speed_mbps);
}

int main() {
    print_instructions();

    int sockfd;
    struct sockaddr_in server_addr;
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error opening socket.\n");
        return EXIT_FAILURE;
    }
    
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Error connecting to server.\n");
        close(sockfd);
        return EXIT_FAILURE;
    }

    download_speed_test(sockfd);
    upload_speed_test(sockfd);

    close(sockfd);
    printf("Thank you for using our application. Have a wonderful day!\n");
    return EXIT_SUCCESS;
}