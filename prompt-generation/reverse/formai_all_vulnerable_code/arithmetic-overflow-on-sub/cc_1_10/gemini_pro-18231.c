//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

int main() {
    // Set up the socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set up the address
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(80);
    addr.sin_addr.s_addr = inet_addr("www.google.com");

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("connect");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Send a request to the server
    const char *request = "GET / HTTP/1.0\r\n\r\n";
    int sent = send(sockfd, request, strlen(request), 0);
    if (sent < 0) {
        perror("send");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Start the timer
    clock_t start = clock();

    // Receive the response from the server
    char buffer[1024];
    int received = recv(sockfd, buffer, sizeof(buffer), 0);

    // Stop the timer
    clock_t end = clock();

    // Calculate the download speed
    double elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    double speed = (double)received / elapsed;

    // Print the result
    printf("Speed: %.2f Kbps\n", speed / 1024);

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}