//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define SERVER_HOST "ipv4.download.testdebit.info"
#define SERVER_PORT "80"
#define BUFFER_SIZE 8192
#define TEST_DURATION 10 // Duration of speed test in seconds
#define RETRY_COUNT 3 // Number of retries

// Function prototypes
void perform_speed_test(const char *host, const char *port);
double measure_download_speed(const char *host, const char *port);
void handle_error(const char *msg);

int main() {
    printf("=== Internet Speed Test Application ===\n");
    printf("Testing download speed...\n");
    
    for (int attempt = 0; attempt < RETRY_COUNT; attempt++) {
        double speed = measure_download_speed(SERVER_HOST, SERVER_PORT);
        if (speed >= 0) {
            printf("Attempt %d: Download speed: %.2f Mbps\n", attempt + 1, speed);
            break; // Exit on successful measurement
        } else {
            printf("Attempt %d: Speed test failed. Retrying...\n", attempt + 1);
            sleep(2); // Wait before retrying
        }
    }
    
    printf("Speed test completed.\n");
    return 0;
}

double measure_download_speed(const char *host, const char *port) {
    struct addrinfo hints, *res;
    int sockfd;
    char buffer[BUFFER_SIZE];
    size_t total_bytes = 0;
    time_t start_time, end_time;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(host, port, &hints, &res) != 0) {
        handle_error("Failed to resolve host");
        return -1;
    }

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd < 0) {
        handle_error("Failed to create socket");
        freeaddrinfo(res);
        return -1;
    }

    if (connect(sockfd, res->ai_addr, res->ai_addrlen) < 0) {
        handle_error("Failed to connect");
        close(sockfd);
        freeaddrinfo(res);
        return -1;
    }

    freeaddrinfo(res);

    // Start the test
    snprintf(buffer, sizeof(buffer), "GET /10Mb.dat HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", host);
    send(sockfd, buffer, strlen(buffer), 0);

    start_time = time(NULL);
    
    while (time(NULL) - start_time < TEST_DURATION) {
        ssize_t bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            break; // Connection closed or error
        }
        total_bytes += bytes_received;
    }

    end_time = time(NULL);
    double elapsed_time = difftime(end_time, start_time);
 
    close(sockfd);
    
    if (elapsed_time <= 0) {
        handle_error("Invalid elapsed time");
        return -1;
    }

    // Calculate speed in Mbps
    double speed_mbps = (total_bytes * 8.0) / (elapsed_time * 1024 * 1024);
    return speed_mbps;
}

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}