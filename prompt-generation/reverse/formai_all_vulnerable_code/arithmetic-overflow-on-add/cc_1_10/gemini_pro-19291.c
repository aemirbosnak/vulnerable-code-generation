//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <server_ip>\n", argv[0]);
        return 1;
    }

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) == -1) {
        perror("inet_pton");
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return 1;
    }

    // Get the current time
    struct timeval start_time;
    gettimeofday(&start_time, NULL);

    // Send a request to the server
    char request[] = "GET / HTTP/1.1\r\nHost: "
                     "www.google.com\r\nConnection: "
                     "close\r\n\r\n";
    if (send(sock, request, strlen(request), 0) == -1) {
        perror("send");
        return 1;
    }

    // Receive the response from the server
    char buf[BUF_SIZE];
    int bytes_received = 0;
    while ((bytes_received = recv(sock, buf, BUF_SIZE, 0)) > 0) {
        // Update the total number of bytes received
        bytes_received += bytes_received;
    }

    if (bytes_received == -1) {
        perror("recv");
        return 1;
    }

    // Get the current time
    struct timeval end_time;
    gettimeofday(&end_time, NULL);

    // Calculate the time taken to download the file
    double time_taken = (end_time.tv_sec - start_time.tv_sec) +
                        (end_time.tv_usec - start_time.tv_usec) /
                            1000000.0;

    // Calculate the download speed
    double speed = bytes_received / time_taken;

    // Print the download speed
    printf("Download speed: %.2f KB/s\n", speed);

    // Close the socket
    close(sock);

    return 0;
}