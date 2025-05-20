//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

#define SERVER_IP "8.8.8.8"
#define PORT 53 // DNS port
#define BUFFER_SIZE 64

void print_speed_result(double time_taken) {
    printf("Ping: %.2f milliseconds\n", time_taken * 1000);
    printf("Estimated Download Speed: %.2f Mbps\n", (BUFFER_SIZE * 8.0 / (time_taken * 1000)) / 1e6);
}

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    struct timespec start_time, end_time;

    // Create a UDP socket
    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    // Configure the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        close(sock);
        return EXIT_FAILURE;
    }

    // Prepare buffer to send
    memset(buffer, 'A', BUFFER_SIZE);
    buffer[BUFFER_SIZE - 1] = '\0'; // Null-terminate the string

    while (1) {
        // Record the start time
        clock_gettime(CLOCK_MONOTONIC, &start_time);

        // Send the data to the server
        if (sendto(sock, buffer, BUFFER_SIZE, 0, (const struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
            perror("Send failed");
            close(sock);
            return EXIT_FAILURE;
        }

        // Receive the response from the server
        if (recvfrom(sock, buffer, BUFFER_SIZE, 0, NULL, NULL) < 0) {
            perror("Receive failed");
            close(sock);
            return EXIT_FAILURE;
        }

        // Record the end time
        clock_gettime(CLOCK_MONOTONIC, &end_time);

        // Calculate the time taken in seconds
        double time_taken = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_nsec - start_time.tv_nsec) / 1e9;

        // Print the results
        print_speed_result(time_taken);

        // Wait for a little before repeating
        printf("Press Ctrl+C to stop the test...\n");
        sleep(2);
    }

    // Cleanup
    close(sock);
    return EXIT_SUCCESS;
}