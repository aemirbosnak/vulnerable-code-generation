//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdbool.h>

#define SERVER_PORT 8080
#define BUFSIZE 1048576 // 1MB for the test
#define TEST_DURATION 5 // Duration of the test in seconds
#define SERVER_IP "192.168.1.1" // Change to your server IP

typedef struct {
    struct timeval start_time;
    struct timeval end_time;
    double elapsed_time;
    size_t bytes_received;
} SpeedTestResult;

void print_usage(const char *program_name) {
    printf("Usage: %s <server_ip>\n", program_name);
}

bool create_socket(int *sockfd) {
    if ((*sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return false;
    }
    return true;
}

bool connect_to_server(int sockfd, const char *server_ip) {
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_aton(server_ip, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        return false;
    }
    return true;
}

void perform_speed_test(int sockfd, SpeedTestResult *result) {
    char *buffer = malloc(BUFSIZE);
    if (!buffer) {
        perror("Buffer allocation failed");
        return;
    }

    gettimeofday(&result->start_time, NULL);
    size_t total_bytes_received = 0;
    ssize_t bytes_received;
    fd_set read_fds;
    
    while (1) {
        FD_ZERO(&read_fds);
        FD_SET(sockfd, &read_fds);
        
        struct timeval timeout;
        timeout.tv_sec = TEST_DURATION;
        timeout.tv_usec = 0;
        
        int activity = select(sockfd + 1, &read_fds, NULL, NULL, &timeout);
        
        if (activity < 0) {
            perror("Select error");
            free(buffer);
            return;
        }
        
        if (activity == 0) { // timeout
            break;
        }
        
        if (FD_ISSET(sockfd, &read_fds)) {
            bytes_received = recv(sockfd, buffer, BUFSIZE, 0);
            if (bytes_received <= 0) {
                break; // Connection closed or error
            }
            total_bytes_received += bytes_received;
        }
    }
    
    gettimeofday(&result->end_time, NULL);
    result->bytes_received = total_bytes_received;
    result->elapsed_time = (result->end_time.tv_sec - result->start_time.tv_sec) +
                           (result->end_time.tv_usec - result->start_time.tv_usec) / 1e6;

    free(buffer);
}

void print_result(SpeedTestResult *result) {
    double speed_mbps = (result->bytes_received * 8 / 1e6) / result->elapsed_time;
    printf("Test completed:\n");
    printf("Time elapsed: %.2f seconds\n", result->elapsed_time);
    printf("Bytes received: %zu bytes\n", result->bytes_received);
    printf("Download speed: %.2f Mbps\n", speed_mbps);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *server_ip = argv[1];
    int sockfd;
    SpeedTestResult result = {0};
    
    if (!create_socket(&sockfd)) {
        return EXIT_FAILURE;
    }

    if (!connect_to_server(sockfd, server_ip)) {
        close(sockfd);
        return EXIT_FAILURE;
    }

    perform_speed_test(sockfd, &result);
    print_result(&result);

    close(sockfd);
    return EXIT_SUCCESS;
}