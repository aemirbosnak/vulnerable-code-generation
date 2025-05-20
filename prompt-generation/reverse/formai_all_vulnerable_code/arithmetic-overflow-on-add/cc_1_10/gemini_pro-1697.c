//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define DEFAULT_PORT 80
#define DEFAULT_HOST "www.google.com"
#define DEFAULT_BUFFER_SIZE 1024
#define DEFAULT_TIMEOUT_SECS 5

// Function to get the current time in milliseconds
long long get_current_time_millis() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (long long)(tv.tv_sec * 1000) + (long long)(tv.tv_usec / 1000);
}

// Function to send a request to a server and measure the response time
long long measure_response_time(const char *host, int port, int buffer_size, int timeout_secs) {
    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error creating socket");
        return -1;
    }

    // Set the socket timeout
    struct timeval tv;
    tv.tv_sec = timeout_secs;
    tv.tv_usec = 0;
    if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char *)&tv, sizeof(tv)) < 0) {
        perror("Error setting socket timeout");
        close(sock);
        return -1;
    }

    // Connect to the server
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(host);
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Error connecting to server");
        close(sock);
        return -1;
    }

    // Send a request to the server
    char request[DEFAULT_BUFFER_SIZE];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", host);
    if (send(sock, request, strlen(request), 0) < 0) {
        perror("Error sending request to server");
        close(sock);
        return -1;
    }

    // Measure the response time
    long long start_time = get_current_time_millis();
    char buffer[DEFAULT_BUFFER_SIZE];
    int bytes_received;
    do {
        bytes_received = recv(sock, buffer, DEFAULT_BUFFER_SIZE, 0);
        if (bytes_received < 0) {
            perror("Error receiving response from server");
            close(sock);
            return -1;
        }
    } while (bytes_received > 0);
    long long end_time = get_current_time_millis();

    // Close the socket
    close(sock);

    // Return the response time
    return end_time - start_time;
}

// Function to print the results of the speed test
void print_results(long long response_time, int buffer_size) {
    double speed_kbps = (double)buffer_size * 8 / response_time;
    double speed_mbps = speed_kbps / 1024;
    printf("Response time: %lld ms\n", response_time);
    printf("Speed: %.2f kbps (%.2f mbps)\n", speed_kbps, speed_mbps);
}

// Main function
int main(int argc, char **argv) {
    // Parse the command-line arguments
    char *host = DEFAULT_HOST;
    int port = DEFAULT_PORT;
    int buffer_size = DEFAULT_BUFFER_SIZE;
    int timeout_secs = DEFAULT_TIMEOUT_SECS;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--host") == 0) {
            host = argv[++i];
        } else if (strcmp(argv[i], "-p") == 0 || strcmp(argv[i], "--port") == 0) {
            port = atoi(argv[++i]);
        } else if (strcmp(argv[i], "-b") == 0 || strcmp(argv[i], "--buffer-size") == 0) {
            buffer_size = atoi(argv[++i]);
        } else if (strcmp(argv[i], "-t") == 0 || strcmp(argv[i], "--timeout-secs") == 0) {
            timeout_secs = atoi(argv[++i]);
        } else {
            printf("Invalid argument: %s\n", argv[i]);
            return 1;
        }
    }

    // Measure the response time
    long long response_time = measure_response_time(host, port, buffer_size, timeout_secs);
    if (response_time < 0) {
        return 1;
    }

    // Print the results
    print_results(response_time, buffer_size);

    return 0;
}