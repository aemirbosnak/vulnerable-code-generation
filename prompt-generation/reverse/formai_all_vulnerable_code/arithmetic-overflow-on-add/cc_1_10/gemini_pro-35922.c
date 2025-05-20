//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: lively
// QoS Monitor -  A lively network quality sentinel

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

// Define some constants for our monitor
#define BUF_SIZE 1024
#define SERVER_PORT 80
#define INTERVAL 1000000 // 1 second in microseconds

int main() {
    // We're going to keep track of our round-trip times in an array
    int rtt_array[100];
    int rtt_index = 0;

    // Set up our socket communications
    struct sockaddr_in server_addr;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket() failed");
        return EXIT_FAILURE;
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Let's get this QoS party started!
    while (1) {
        // Grab the current time to measure our round-trip time
        struct timeval start_time, end_time;
        gettimeofday(&start_time, NULL);

        // Send a request to our test server
        char buf[BUF_SIZE];
        int bytes_sent = send(sockfd, buf, BUF_SIZE, 0);
        if (bytes_sent == -1) {
            perror("send() failed");
            return EXIT_FAILURE;
        }

        // Wait for the server's response
        int bytes_received = recv(sockfd, buf, BUF_SIZE, 0);
        if (bytes_received == -1) {
            perror("recv() failed");
            return EXIT_FAILURE;
        }

        // Calculate the round-trip time
        gettimeofday(&end_time, NULL);
        long rtt = (end_time.tv_sec - start_time.tv_sec) * 1000000 + (end_time.tv_usec - start_time.tv_usec);

        // Store the RTT in our array
        rtt_array[rtt_index] = rtt;
        rtt_index = (rtt_index + 1) % 100; // Keep the array at a manageable size

        // Print out some stats
        printf("RTT: %ld microseconds\n", rtt);
        printf("Average RTT: %ld microseconds\n", calculate_average_rtt(rtt_array, 100));
    }

    return EXIT_SUCCESS;
}

// A helper function to calculate the average of an array of RTTs
int calculate_average_rtt(int* rtt_array, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += rtt_array[i];
    }
    return sum / size;
}