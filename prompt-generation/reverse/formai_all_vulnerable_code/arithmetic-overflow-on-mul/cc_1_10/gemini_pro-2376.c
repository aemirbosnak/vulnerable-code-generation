//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFSIZE 1024

// Function to get the current time in milliseconds
long long get_time_ms() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (long long)tv.tv_sec * 1000 + (long long)tv.tv_usec / 1000;
}

// Function to download a file from a given URL
long long download_file(const char *url) {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Parse the URL
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    if (inet_pton(AF_INET, url, &server_addr.sin_addr) == -1) {
        perror("inet_pton");
        exit(1);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Send a request to download the file
    char request[BUFSIZE];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", url);
    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive the response from the server
    char response[BUFSIZE];
    long long total_bytes = 0;
    while (1) {
        int bytes_received = recv(sockfd, response, BUFSIZE, 0);
        if (bytes_received == -1) {
            perror("recv");
            exit(1);
        } else if (bytes_received == 0) {
            break;
        }
        total_bytes += bytes_received;
    }

    // Close the socket
    close(sockfd);

    // Return the total number of bytes downloaded
    return total_bytes;
}

int main(int argc, char *argv[]) {
    // Check if the user has provided a URL
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <url>\n", argv[0]);
        exit(1);
    }

    // Get the URL from the command line
    const char *url = argv[1];

    // Download the file
    long long bytes_downloaded = download_file(url);

    // Calculate the download speed
    long long time_ms = get_time_ms();
    double speed_bps = (double)bytes_downloaded * 8 / time_ms;
    double speed_mbps = speed_bps / 1000000.0;

    // Print the download speed
    printf("Download speed: %.2f Mbps\n", speed_mbps);

    return 0;
}