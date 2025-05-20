//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

// Global variables
int sockfd = -1;
int should_stop = 0;

// Signal handler function
void sigint_handler(int sig) {
    printf("Stopping the QoS monitor...\n");
    should_stop = 1;
}

// Function to check the network quality of service
void check_qos() {
    // Create a sample packet
    char packet[] = "Hello, world!";
    size_t packet_len = strlen(packet);

    // Time variables
    struct timeval start, end;
    double duration = 0;

    // Send the packet and record the time
    gettimeofday(&start, NULL);
    send(sockfd, packet, packet_len, 0);

    // Receive the packet and record the time
    char buffer[1024];
    recv(sockfd, buffer, 1024, 0);
    gettimeofday(&end, NULL);

    // Calculate the duration in microseconds
    duration = ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec));

    // Print the results
    printf("Packet sent and received successfully with a duration of %.6f microseconds.\n", duration);
}

int main() {
    // Declare variables
    struct sockaddr_in server_address;

    // Create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error: Failed to create socket.");
        exit(EXIT_FAILURE);
    }

    // Initialize the server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = htons(8080);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("Error: Failed to connect to server.");
        exit(EXIT_FAILURE);
    }

    // Register the signal handler
    signal(SIGINT, sigint_handler);

    // Check the network quality of service every 5 seconds
    while (!should_stop) {
        check_qos();
        sleep(5);
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}