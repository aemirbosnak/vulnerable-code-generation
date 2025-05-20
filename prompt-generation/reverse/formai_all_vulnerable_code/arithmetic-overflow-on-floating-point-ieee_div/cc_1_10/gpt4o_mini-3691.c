//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <time.h>

#define SERVER_IP "speed.hetzner.de" // A public speed test server
#define SERVER_PORT 80
#define BUFFER_SIZE 8192
#define TEST_SIZE (1024 * 1024 * 10) // 10 MB test size

void print_banner() {
    printf("*******************************\n");
    printf("*      Internet Speed Test!    *\n");
    printf("*      By the Code Magician!   *\n");
    printf("*******************************\n\n");
}

void calculate_speed(double time_taken, long bytes_transferred) {
    double speed_mbps = (bytes_transferred * 8) / (time_taken * 1024 * 1024);
    printf("Your download speed is: %.2f Mbps\n", speed_mbps);
}

int main() {
    print_banner();

    int sockfd;
    struct sockaddr_in server_addr;
    char *buffer;
    ssize_t bytes_received;
    long total_bytes_received = 0;
    time_t start_time, end_time;

    buffer = (char *)malloc(BUFFER_SIZE);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Socket creation failed!\n");
        free(buffer);
        return EXIT_FAILURE;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Connection failed!\n");
        close(sockfd);
        free(buffer);
        return EXIT_FAILURE;
    }

    // send HTTP GET request
    char *request = "GET /10MB.test HTTP/1.1\r\nHost: speed.hetzner.de\r\nConnection: close\r\n\r\n";
    send(sockfd, request, strlen(request), 0);

    start_time = time(NULL);

    // receive data
    while (total_bytes_received < TEST_SIZE) {
        bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        total_bytes_received += bytes_received;
    }

    end_time = time(NULL);
    double time_taken = difftime(end_time, start_time);

    printf("Total data received: %ld bytes\n", total_bytes_received);
    
    if (time_taken > 0) {
        calculate_speed(time_taken, total_bytes_received);
    } else {
        printf("Error: Time taken is zero, can't calculate speed!\n");
    }

    close(sockfd);
    free(buffer);

    printf("\nThank you for using our speed test!\n");
    printf("Stay connected and surf the internet with light speed!\n");
    
    return EXIT_SUCCESS;
}