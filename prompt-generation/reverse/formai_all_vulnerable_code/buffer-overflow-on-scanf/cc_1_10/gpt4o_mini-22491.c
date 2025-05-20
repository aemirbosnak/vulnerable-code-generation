//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SERVER "ipv4.downloadspeedtest.com"
#define PORT 8080
#define BUFFER_SIZE 8192

void display_header() {
    printf("************************************\n");
    printf("* Welcome to the Internet Speed Test! *\n");
    printf("************************************\n");
}

void display_result(float download_speed, float upload_speed) {
    printf("************************************\n");
    printf("              Results               \n");
    printf("************************************\n");
    printf("Download Speed: %.2f Mbps\n", download_speed);
    printf("Upload Speed: %.2f Mbps\n", upload_speed);
    printf("************************************\n");
}

void measure_download_speed(const char *server_ip) {
    char buffer[BUFFER_SIZE];
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Unable to create socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Start measuring download speed
    clock_t start_time = clock();
    size_t total_bytes = 0;
    while (1) {
        ssize_t bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        total_bytes += bytes_received;
    }
    clock_t end_time = clock();
    close(sockfd);

    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    float download_speed_mbps = (total_bytes * 8) / (time_taken * 1024 * 1024);
    
    printf("Download Speed Test Completed.\n");
    printf("Time taken: %.2f seconds\n", time_taken);
    display_result(download_speed_mbps, 0.0);
}

void measure_upload_speed(const char *server_ip) {
    char buffer[BUFFER_SIZE];
    int sockfd;
    struct sockaddr_in server_addr;

    // Prepare a large amount of data for upload
    memset(buffer, 'A', BUFFER_SIZE);
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Unable to create socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Start measuring upload speed
    clock_t start_time = clock();
    size_t total_bytes = 0;
    for (int i = 0; i < 100; ++i) { // Uploading data in chunks
        ssize_t bytes_sent = send(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_sent < 0) {
            perror("Upload failed");
            break;
        }
        total_bytes += bytes_sent;
    }
    clock_t end_time = clock();
    close(sockfd);
    
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    float upload_speed_mbps = (total_bytes * 8) / (time_taken * 1024 * 1024);

    printf("Upload Speed Test Completed.\n");
    printf("Time taken: %.2f seconds\n", time_taken);
    display_result(0.0, upload_speed_mbps);
}

int main() {
    display_header();
    
    const char *server_ip = "YOUR_SERVER_IP"; // Change to your server's IP
    char user_choice;

    printf("Would you like to test download speed (D) or upload speed (U) or both (B)? ");
    scanf(" %c", &user_choice);
    
    if (user_choice == 'D' || user_choice == 'B') {
        measure_download_speed(server_ip);
    }
    if (user_choice == 'U' || user_choice == 'B') {
        measure_upload_speed(server_ip);
    }

    printf("Thank you for using the Internet Speed Test!\n");
    return 0;
}