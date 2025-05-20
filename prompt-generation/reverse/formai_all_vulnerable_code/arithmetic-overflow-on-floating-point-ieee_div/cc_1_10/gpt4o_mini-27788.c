//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <fcntl.h>

#define SERVER_IP "1.1.1.1"
#define SERVER_PORT 80
#define BUFFER_SIZE 1024

void delay(int seconds) {
    sleep(seconds);
}

double get_current_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec / 1000000.0;
}

void print_intro() {
    printf("****************************************\n");
    printf("*          Internet Speed Test        *\n");
    printf("*       by Creative Developer         *\n");
    printf("****************************************\n");
    delay(1);
}

void fetch_data(size_t num_bytes) {
    char buffer[BUFFER_SIZE];
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Simple HTTP GET; we won't actually use the response, just to fill the data.
    char *request = "GET / HTTP/1.1\r\nHost: 1.1.1.1\r\nConnection: close\r\n\r\n";
    send(sockfd, request, strlen(request), 0);

    size_t total_received = 0;
    ssize_t bytes_received;

    while (total_received < num_bytes) {
        bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            break;
        }
        total_received += bytes_received;
    }

    close(sockfd);
}

void speed_test(size_t num_bytes) {
    double start_time = get_current_time();

    printf("Fetching %zu bytes from %s...\n", num_bytes, SERVER_IP);
    fetch_data(num_bytes);

    double end_time = get_current_time();
    double duration = end_time - start_time;

    double speed_mbps = (num_bytes * 8) / (duration * 1000000);
    printf("Download speed: %.2f Mbps\n", speed_mbps);
}

int main() {
    print_intro();

    size_t test_size = 10 * 1024 * 1024; // 10 MB
    printf("You can change the number of bytes to fetch.\n");
    printf("Starting test with %zu bytes...\n", test_size);
    delay(1);

    speed_test(test_size);
    
    printf("Test complete! Thank you for using the Speed Test App.\n");
    return 0;
}