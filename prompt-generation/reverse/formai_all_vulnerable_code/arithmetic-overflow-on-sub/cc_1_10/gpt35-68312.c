//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int client_socket, error, optval = 1;
    struct sockaddr_in server_addr;
    struct timeval start_time, end_time;
    double rtt_time;

    // Check for the arguments
    if (argc != 2) {
        printf("Usage: %s <IP Address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create a socket
    client_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (client_socket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    error = setsockopt(client_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &optval, sizeof(optval));
    if (error == -1) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Initialize server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    error = inet_pton(AF_INET, argv[1], &server_addr.sin_addr);
    if (error == -1) {
        perror("Inet_pton failed");
        exit(EXIT_FAILURE);
    }

    // Connect to a server
    error = connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (error == -1) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // Check for network quality of service
    int i;
    for (i = 0; i < 5; i++) {
        char buf[255];
        gettimeofday(&start_time, NULL);
        write(client_socket, "PING", 4);
        read(client_socket, buf, 255);
        gettimeofday(&end_time, NULL);
        rtt_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;
        printf("Round trip time: %f seconds\n", rtt_time);
        if (rtt_time > 0.5) {
            printf("Network quality of service is poor\n");
        } else {
            printf("Network quality of service is good\n");
        }
        sleep(1);
    }

    // Close the socket
    close(client_socket);

    return 0;
}