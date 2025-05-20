//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <fcntl.h>

#define SERVER_IP "your.server.ip"  // Change to the server you want to test against
#define PORT 8080                     // Specify the port to connect to
#define BUFFER_SIZE 8192              // Buffer size for data transfer
#define TEST_DURATION 5               // Duration of the test in seconds

void download_speed_test() {
    int sock;
    struct sockaddr_in server_addr;
    char *buffer = (char *)malloc(BUFFER_SIZE);
    struct timeval start, end;
    long total_bytes = 0;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    gettimeofday(&start, NULL);
    while (1) {
        int bytes = send(sock, buffer, BUFFER_SIZE, 0);
        if (bytes < 0) {
            perror("Send failed");
            break;
        }
        total_bytes += bytes;
        if (total_bytes / (BUFFER_SIZE / 1024) > 1024 * TEST_DURATION) {
            break;
        }
    }
    gettimeofday(&end, NULL);
    
    close(sock);
    free(buffer);
    
    double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    double speed = (total_bytes * 8) / (time_taken * 1000000); // in Mbps
    printf("Download Speed: %.2f Mbps\n", speed);
}

void upload_speed_test() {
    int sock;
    struct sockaddr_in server_addr;
    char *buffer = (char *)malloc(BUFFER_SIZE);
    struct timeval start, end;
    long total_bytes = 0;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    gettimeofday(&start, NULL);
    memset(buffer, 'A', BUFFER_SIZE); // Fill buffer with dummy data
    while (1) {
        int bytes = send(sock, buffer, BUFFER_SIZE, 0);
        if (bytes < 0) {
            perror("Send failed");
            break;
        }
        total_bytes += bytes;
        if (total_bytes / (BUFFER_SIZE / 1024) > 1024 * TEST_DURATION) {
            break;
        }
    }
    gettimeofday(&end, NULL);

    close(sock);
    free(buffer);
    
    double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    double speed = (total_bytes * 8) / (time_taken * 1000000); // in Mbps
    printf("Upload Speed: %.2f Mbps\n", speed);
}

int main() {
    printf("Starting Speed Test...\n");

    download_speed_test();
    upload_speed_test();

    return 0;
}