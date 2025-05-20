//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 524288 // 512 KB
#define SERVER_PORT 8080
#define SERVER_IP "127.0.0.1"

void get_current_time(char *buffer, size_t buffer_size) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(buffer, buffer_size, "%Y-%m-%d %H:%M:%S", t);
}

void display_welcome_message() {
    printf("\n");
    printf("**********************************************\n");
    printf("*                                            *\n");
    printf("*            Internet Speed Test App        *\n");
    printf("*                                            *\n");
    printf("**********************************************\n");
    printf("\n");
}

void display_results(float download_speed, float upload_speed, float latency) {
    printf("\n");
    printf("**********************************************\n");
    printf("*               Speed Test Results           *\n");
    printf("**********************************************\n");
    printf("Download Speed: %.2f Mbps\n", download_speed);
    printf("Upload Speed: %.2f Mbps\n", upload_speed);
    printf("Latency: %.2f ms\n", latency);
    printf("**********************************************\n");
}

float calculate_speed(int bytes_transferred, float elapsed_time) {
    return (bytes_transferred * 8.0 / (1000 * 1000)) / elapsed_time; // Mbps
}

void test_download_speed() {
    char buffer[BUFFER_SIZE];
    int sockfd;
    struct sockaddr_in server_address;
    float download_time;
    struct timespec start_time, end_time;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_address.sin_addr);
    
    connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address));

    clock_gettime(CLOCK_MONOTONIC, &start_time);
    int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    clock_gettime(CLOCK_MONOTONIC, &end_time);

    if (bytes_received < 0) {
        perror("Error in receiving data");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    download_time = (end_time.tv_sec - start_time.tv_sec) + 
                    (end_time.tv_nsec - start_time.tv_nsec) / 1e9;

    float download_speed = calculate_speed(bytes_received, download_time);
    printf("Download Speed Test complete:\n");
    display_results(download_speed, 0, 0); // Initial values for display
    close(sockfd);
}

void test_upload_speed() {
    char buffer[BUFFER_SIZE];
    memset(buffer, 'A', BUFFER_SIZE);
    int sockfd;
    struct sockaddr_in server_address;
    float upload_time;
    struct timespec start_time, end_time;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_address.sin_addr);

    connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address));

    clock_gettime(CLOCK_MONOTONIC, &start_time);
    int bytes_sent = send(sockfd, buffer, BUFFER_SIZE, 0);
    clock_gettime(CLOCK_MONOTONIC, &end_time);

    if (bytes_sent < 0) {
        perror("Error in sending data");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    upload_time = (end_time.tv_sec - start_time.tv_sec) + 
                  (end_time.tv_nsec - start_time.tv_nsec) / 1e9;

    float upload_speed = calculate_speed(bytes_sent, upload_time);
    printf("Upload Speed Test complete:\n");
    display_results(0, upload_speed, 0); // Initial values for display
    close(sockfd);
}

void test_latency() {
    int sockfd;
    struct sockaddr_in server_address;
    char *ping_message = "PING";
    char pong_response[4];
    struct timespec start_time, end_time;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_address.sin_addr);

    clock_gettime(CLOCK_MONOTONIC, &start_time);
    sendto(sockfd, ping_message, strlen(ping_message), 0,
           (struct sockaddr *)&server_address, sizeof(server_address));
    recvfrom(sockfd, pong_response, sizeof(pong_response), 0, NULL, NULL);
    clock_gettime(CLOCK_MONOTONIC, &end_time);
    
    float latency = (end_time.tv_sec - start_time.tv_sec) * 1000.0 +
                    (end_time.tv_nsec - start_time.tv_nsec) / 1000000.0;

    printf("Latency test complete:\n");
    display_results(0, 0, latency);
    close(sockfd);
}

int main() {
    display_welcome_message();
    test_download_speed();
    test_upload_speed();
    test_latency();
    return 0;
}