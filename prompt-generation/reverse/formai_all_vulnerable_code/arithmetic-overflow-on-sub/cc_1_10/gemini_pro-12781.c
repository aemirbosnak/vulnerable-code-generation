//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUF_SIZE 1024

// Function to get the current time in microseconds
long long get_time_us() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (long long)tv.tv_sec * 1000000 + (long long)tv.tv_usec;
}

// Function to send a request to the server
int send_request(int sockfd) {
    char request[] = "GET / HTTP/1.1\r\nHost: example.com\r\nConnection: close\r\n\r\n";
    int len = strlen(request);
    int nbytes = send(sockfd, request, len, 0);
    if (nbytes < 0) {
        perror("send");
        return -1;
    }
    return 0;
}

// Function to receive the response from the server
int receive_response(int sockfd) {
    char buf[BUF_SIZE];
    int nbytes;
    while ((nbytes = recv(sockfd, buf, BUF_SIZE, 0)) > 0) {
        // Do something with the data in buf
    }
    if (nbytes < 0) {
        perror("recv");
        return -1;
    }
    return 0;
}

// Function to calculate the download speed
double calculate_speed(long long start_time, long long end_time, int bytes_received) {
    double elapsed_time = (double)(end_time - start_time) / 1000000.0;
    double speed = (double)bytes_received / elapsed_time;
    return speed;
}

int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    // Connect to the server
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        close(sockfd);
        return -1;
    }

    // Send a request to the server
    if (send_request(sockfd) < 0) {
        close(sockfd);
        return -1;
    }

    // Start the timer
    long long start_time = get_time_us();

    // Receive the response from the server
    if (receive_response(sockfd) < 0) {
        close(sockfd);
        return -1;
    }

    // Stop the timer
    long long end_time = get_time_us();

    // Calculate the download speed
    int bytes_received = recv(sockfd, NULL, 0, MSG_PEEK);
    double speed = calculate_speed(start_time, end_time, bytes_received);

    // Print the download speed
    printf("Download speed: %.2f Mbps\n", speed);

    // Close the socket
    close(sockfd);

    return 0;
}