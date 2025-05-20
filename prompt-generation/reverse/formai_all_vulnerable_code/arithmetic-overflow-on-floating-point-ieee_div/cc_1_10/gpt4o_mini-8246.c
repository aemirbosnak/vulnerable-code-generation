//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define SERVER_PORT 8080
#define BUFF_SIZE 1024
#define TEST_DATA_SIZE 1048576  // 1 MB

void print_speed(float speed) {
    printf("Speed: %.2f Mbps\n", speed);
}

void speed_test() {
    int sockfd;
    struct sockaddr_in server_addr;
    char *test_data;
    int bytes_sent, total_bytes_sent = 0;
    struct timeval start, end;

    // Create the socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Server configuration
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(SERVER_PORT);

    // Establish the connection
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Allocate memory for test data
    test_data = malloc(TEST_DATA_SIZE);
    if (test_data == NULL) {
        perror("Memory allocation failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    memset(test_data, 'A', TEST_DATA_SIZE);  // Fill with dummy data

    // Time the upload test
    gettimeofday(&start, NULL);
    bytes_sent = send(sockfd, test_data, TEST_DATA_SIZE, 0);
    if (bytes_sent < 0) {
        perror("Send failed");
        free(test_data);
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    total_bytes_sent += bytes_sent;
    gettimeofday(&end, NULL);

    // Calculate upload speed
    float upload_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;
    float upload_speed = (total_bytes_sent * 8) / (upload_time * 1e6); // Mbps
    printf("Upload Test:\n");
    print_speed(upload_speed);

    // Time the download test
    char recv_buffer[BUFF_SIZE];
    int bytes_received, total_bytes_received = 0;

    gettimeofday(&start, NULL);
    while (total_bytes_received < TEST_DATA_SIZE) {
        bytes_received = recv(sockfd, recv_buffer, BUFF_SIZE, 0);
        if (bytes_received < 0) {
            perror("Receive failed");
            free(test_data);
            close(sockfd);
            exit(EXIT_FAILURE);
        }
        total_bytes_received += bytes_received;
    }
    gettimeofday(&end, NULL);

    // Calculate download speed
    float download_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;
    float download_speed = (total_bytes_received * 8) / (download_time * 1e6); // Mbps
    printf("Download Test:\n");
    print_speed(download_speed);

    // Clean up
    free(test_data);
    close(sockfd);
}

int main() {
    printf("Starting Internet Speed Test...\n");
    speed_test();
    printf("Speed test completed!\n");
    return 0;
}