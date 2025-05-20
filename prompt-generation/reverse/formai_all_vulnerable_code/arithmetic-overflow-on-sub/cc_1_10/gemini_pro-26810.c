//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/time.h>

#define MAX_SIZE 1024

int main(int argc, char **argv) {
    // Check arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get host and port
    char *host = argv[1];
    int port = atoi(argv[2]);

    // Create socket
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Resolve hostname
    struct hostent *hostent;
    if ((hostent = gethostbyname(host)) == NULL) {
        herror("gethostbyname");
        return EXIT_FAILURE;
    }

    // Set socket address
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    memcpy(&addr.sin_addr, hostent->h_addr, hostent->h_length);
    addr.sin_port = htons(port);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Initialize variables
    char buffer[MAX_SIZE];
    int bytes_sent, bytes_received;
    struct timeval start, end;

    // Send data
    memset(buffer, 'a', MAX_SIZE);
    gettimeofday(&start, NULL);
    bytes_sent = send(sockfd, buffer, MAX_SIZE, 0);
    gettimeofday(&end, NULL);
    if (bytes_sent < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive data
    gettimeofday(&start, NULL);
    bytes_received = recv(sockfd, buffer, MAX_SIZE, 0);
    gettimeofday(&end, NULL);
    if (bytes_received < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Calculate RTT
    double rtt = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;

    // Print results
    printf("Sent %d bytes\n", bytes_sent);
    printf("Received %d bytes\n", bytes_received);
    printf("RTT: %.2f ms\n", rtt);

    // Close socket
    close(sockfd);

    return EXIT_SUCCESS;
}