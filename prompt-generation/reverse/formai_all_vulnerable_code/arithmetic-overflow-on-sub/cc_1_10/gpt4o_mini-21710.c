//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SERVER_PORT 80
#define BUFFER_SIZE 1024

void print_speed(double speed) {
    if (speed < 1024) {
        printf("Download speed: %.2f B/s\n", speed);
    } else if (speed < 1048576) {
        printf("Download speed: %.2f KB/s\n", speed / 1024);
    } else {
        printf("Download speed: %.2f MB/s\n", speed / 1048576);
    }
}

int connect_to_server(const char *server_ip) {
    int sock;
    struct sockaddr_in server_addr;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);

    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        perror("Invalid address or address not supported");
        exit(EXIT_FAILURE);
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        exit(EXIT_FAILURE);
    }

    return sock;
}

void start_download_test(int sock) {
    char buffer[BUFFER_SIZE];
    int bytes_received;
    clock_t start_time, end_time;
    long total_bytes = 0;

    // Start the timer
    start_time = clock();

    // Mock download: receive 1024 bytes 100 times
    for (int i = 0; i < 100; ++i) {
        bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            perror("Failed to receive data");
            break;
        }
        total_bytes += bytes_received;
    }

    // Stop the timer
    end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    if (time_taken > 0) {
        double speed = total_bytes / time_taken;
        print_speed(speed);
    } else {
        printf("Error in measuring time.\n");
    }
}

void display_intro() {
    printf("===================================\n");
    printf("     Welcome to the Speed Test     \n");
    printf("===================================\n");
    printf("Checking your internet speed...\n\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <server_ip>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *server_ip = argv[1];
    
    display_intro();
    
    int sock = connect_to_server(server_ip);
    
    start_download_test(sock);
    
    close(sock);
    
    return 0;
}