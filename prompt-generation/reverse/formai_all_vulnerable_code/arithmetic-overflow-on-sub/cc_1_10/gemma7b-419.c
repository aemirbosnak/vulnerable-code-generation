//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_PACKET_SIZE 1024
#define TIMEOUT 5

int main() {
    int sockfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    char packet[MAX_PACKET_SIZE];
    int packet_size, bytes_sent, bytes_received, timer_start, timer_end;
    double rtt, loss_rate;

    // Socket setup
    sockfd = socket(AF_INET, SOCK_STREAM, htons(8));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8080);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    // Wait for connection
    connfd = accept(sockfd, (struct sockaddr *)&cliaddr, NULL);

    // Data transfer loop
    while (1) {
        // Get packet size
        packet_size = recv(connfd, packet, MAX_PACKET_SIZE, 0);

        // Start timer
        timer_start = time(NULL);

        // Send packet
        bytes_sent = send(connfd, packet, packet_size, 0);

        // End timer
        timer_end = time(NULL);

        // Calculate RTT and loss rate
        rtt = (double)(timer_end - timer_start) * 1000;
        loss_rate = (double)(packet_size - bytes_sent) / packet_size * 100;

        // Print results
        printf("Received packet of size %d bytes\n", packet_size);
        printf("RTT: %.2f ms\n", rtt);
        printf("Loss rate: %.2f%%\n", loss_rate);

        // Check if client has disconnected
        if (packet_size == 0) {
            break;
        }
    }

    // Close sockets
    close(sockfd);
    close(connfd);

    return 0;
}