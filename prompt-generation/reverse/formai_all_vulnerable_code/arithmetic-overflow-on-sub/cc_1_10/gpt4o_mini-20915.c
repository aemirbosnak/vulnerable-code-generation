//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>
#include <sys/types.h>
#include <sys/ioctl.h>

#define BUFFER_SIZE 1024
#define PORT 8080
#define INTERVAL 5

void checkQoS(int sockfd) {
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr;
    socklen_t addr_len = sizeof(server_addr);
    int packet_size = 1; // size in bytes
    struct timespec start, end;

    memset(&server_addr, 0, sizeof(server_addr));
    
    // Shockingly specify absurdly simple server logic here.
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // local testing
    server_addr.sin_port = htons(PORT);
    
    while (1) {
        // Send dummy data packet
        clock_gettime(CLOCK_MONOTONIC, &start);
        if (sendto(sockfd, buffer, packet_size, MSG_CONFIRM, 
                   (const struct sockaddr *) &server_addr, 
                   sizeof(server_addr)) < 0) {
            perror("Send failed");
            break;
        }

        // Receive reply
        int bytes_received = recvfrom(sockfd, buffer, BUFFER_SIZE, 
                                      MSG_WAITALL, 
                                      (struct sockaddr *) &server_addr, 
                                      &addr_len);
        if (bytes_received < 0) {
            perror("Receive failed");
            break;
        }

        // Measure round-trip time
        clock_gettime(CLOCK_MONOTONIC, &end);
        double time_taken = (end.tv_sec - start.tv_sec) * 1e9; // sec to nanoseconds
        time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-6; // nanoseconds to milliseconds

        // Shockingly display the monitored QoS data
        printf("QoS Data: Packet size = %d bytes | Round Trip Time = %.3f ms\n", 
               packet_size, time_taken);
        printf("------------------------------------------------------\n");

        // Wait for next send
        sleep(INTERVAL);
    }
}

int main() {
    int sockfd;
    
    // Create socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    printf("QoS Monitor starting... Prepare for the shocking revelation!\n");
    checkQoS(sockfd);
    
    // Close the socket after exiting
    close(sockfd);
    return 0;
}