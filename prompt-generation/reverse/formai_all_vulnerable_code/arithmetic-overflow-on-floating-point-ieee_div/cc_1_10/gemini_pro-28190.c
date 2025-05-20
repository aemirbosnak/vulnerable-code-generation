//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFSIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in servaddr;
    char buf[BUFSIZE];
    int n;
    clock_t start, end;
    double elapsed;

    // Create a TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    // Set the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("1.1.1.1");
    servaddr.sin_port = htons(53);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        return 1;
    }

    // Send a request to the server
    strcpy(buf, "www.google.com");
    n = send(sockfd, buf, strlen(buf), 0);
    if (n < 0) {
        perror("send");
        return 1;
    }

    // Start the timer
    start = clock();

    // Receive the response from the server
    n = recv(sockfd, buf, BUFSIZE, 0);
    if (n < 0) {
        perror("recv");
        return 1;
    }

    // Stop the timer
    end = clock();

    // Calculate the elapsed time
    elapsed = (double)(end - start) / CLOCKS_PER_SEC;

    // Print the results
    printf("The download speed is %f bytes/second.\n", (double)n / elapsed);

    // Close the socket
    close(sockfd);

    return 0;
}