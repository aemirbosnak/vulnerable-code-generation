//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

void perform_speed_test(const char* server_ip, int duration);
double calculate_speed(size_t bytes, double seconds);

int main() {
    char server_ip[INET_ADDRSTRLEN];
    int duration;

    printf("Welcome to the Peaceful Internet Speed Test Application\n");
    printf("Please enter the IP address of the speed test server (e.g., 192.168.1.1): ");
    fgets(server_ip, sizeof(server_ip), stdin);
    server_ip[strcspn(server_ip, "\n")] = 0; // Remove the newline character

    printf("For how many seconds do you want to conduct the speed test? ");
    scanf("%d", &duration);
    if (duration <= 0) {
        printf("Duration should be a positive integer. Exiting...\n");
        return 1;
    }

    perform_speed_test(server_ip, duration);
    return 0;
}

void perform_speed_test(const char* server_ip, int duration) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    size_t total_bytes_received = 0;
    double time_elapsed = 0;
    time_t start_time, end_time;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        perror("Invalid address / Address not supported");
        close(sock);
        exit(EXIT_FAILURE);
    }

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    printf("Connection established with server %s on port %d. Starting speed test...\n", server_ip, SERVER_PORT);
    start_time = time(NULL);

    while (1) {
        ssize_t bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        total_bytes_received += bytes_received;
        end_time = time(NULL);
        time_elapsed = difftime(end_time, start_time);

        if (time_elapsed >= duration) {
            break;
        }
    }

    close(sock);
    double speed_mbps = calculate_speed(total_bytes_received, time_elapsed);
    printf("Total bytes received: %zu\n", total_bytes_received);
    printf("Time elapsed: %.2f seconds\n", time_elapsed);
    printf("Internet Speed: %.2f Mbps\n", speed_mbps);
}

double calculate_speed(size_t bytes, double seconds) {
    if (seconds <= 0) {
        return 0.0;
    }
    return (bytes * 8.0 / (1024 * 1024)) / seconds; // Convert to Mbps
}