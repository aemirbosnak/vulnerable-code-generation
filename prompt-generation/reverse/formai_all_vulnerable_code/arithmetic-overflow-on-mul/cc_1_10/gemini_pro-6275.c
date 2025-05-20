//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define BUFFERSIZE 1024

// Custom header for QoS monitoring data
typedef struct {
    uint32_t timestamp;
    uint16_t packet_size;
    uint16_t delay;
} QoSData;

// Function to get the current timestamp in milliseconds
uint32_t get_timestamp() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec * 1000 + ts.tv_nsec / 1000000;
}

// Function to send a QoS monitoring packet to the server
int send_qos_packet(int sockfd, QoSData *data) {
    char buffer[BUFFERSIZE];
    memcpy(buffer, data, sizeof(QoSData));
    return send(sockfd, buffer, sizeof(buffer), 0);
}

int main() {
    // Create a socket for sending QoS monitoring packets
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket() failed");
        return EXIT_FAILURE;
    }

    // Get the server's address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12345);
    struct hostent *host = gethostbyname("localhost");
    if (host == NULL) {
        perror("gethostbyname() failed");
        return EXIT_FAILURE;
    }
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    // Send QoS monitoring packets at a regular interval
    while (1) {
        // Get the current timestamp and packet size
        QoSData data;
        data.timestamp = get_timestamp();
        data.packet_size = BUFFERSIZE;

        // Calculate the delay by sending an echo request and measuring the response time
        struct sockaddr_in echo_addr;
        memset(&echo_addr, 0, sizeof(echo_addr));
        echo_addr.sin_family = AF_INET;
        echo_addr.sin_port = htons(8);
        memcpy(&echo_addr.sin_addr, host->h_addr, host->h_length);
        uint32_t start_time = get_timestamp();
        int echo_sockfd = socket(AF_INET, SOCK_DGRAM, 0);
        if (echo_sockfd == -1) {
            perror("socket() failed");
            return EXIT_FAILURE;
        }
        sendto(echo_sockfd, "ping", 4, 0, (struct sockaddr*)&echo_addr, sizeof(echo_addr));
        char echo_buffer[BUFFERSIZE];
        recvfrom(echo_sockfd, echo_buffer, BUFFERSIZE, 0, NULL, NULL);
        close(echo_sockfd);
        data.delay = get_timestamp() - start_time;

        // Send the QoS monitoring packet to the server
        if (send_qos_packet(sockfd, &data) == -1) {
            perror("send() failed");
            return EXIT_FAILURE;
        }

        // Sleep for a bit before sending the next packet
        sleep(1);
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}