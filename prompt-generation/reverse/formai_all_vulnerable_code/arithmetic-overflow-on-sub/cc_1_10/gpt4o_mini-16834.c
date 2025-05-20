//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_IP "ping.jsontest.com" // Example server to ping
#define SERVER_PORT 80
#define BUFFER_SIZE 1024

void print_welcome_message() {
    printf("Welcome to the Internet Speed Test!\n");
    printf("This program will measure the speed of your internet connection.\n");
    printf("Please wait while we test your connection...\n\n");
}

double measure_download_time() {
    int sock;
    struct sockaddr_in server_addr;
    char send_buffer[BUFFER_SIZE];
    char receive_buffer[BUFFER_SIZE];
    int bytes_sent, bytes_received;
    clock_t start, end;

    snprintf(send_buffer, sizeof(send_buffer),
             "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", SERVER_IP);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    start = clock();
    
    bytes_sent = send(sock, send_buffer, strlen(send_buffer), 0);
    if (bytes_sent < 0) {
        perror("Send failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    bytes_received = recv(sock, receive_buffer, BUFFER_SIZE - 1, 0);
    end = clock();

    if (bytes_received < 0) {
        perror("Receive failed");
    } else {
        receive_buffer[bytes_received] = '\0'; // Null-terminate the received data
    }

    close(sock);
    return ((double)(end - start)) / CLOCKS_PER_SEC; // Time in seconds
}

double calculate_speed(double download_time) {
    // Assuming the size of data received is approximately 1KB for this demo
    // Speed = Size / Time
    double size_in_kb = 1.0; // 1 KB
    return size_in_kb / download_time; // Speed in KB/s
}

void display_results(double speed) {
    printf("Download Speed: %.2f KB/s\n", speed);
}

int main() {
    print_welcome_message();

    double download_time = measure_download_time();
    if (download_time <= 0) {
        printf("Download test failed. Please check your connection.\n");
        return EXIT_FAILURE;
    }

    double speed = calculate_speed(download_time);
    display_results(speed);
    
    printf("Thank you for using the Internet Speed Test!\n");
    return EXIT_SUCCESS;
}