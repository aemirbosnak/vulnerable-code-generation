//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>

// This defines the maximum length of a hostname or IP address
#define HOSTNAME_LEN 256

// This defines the maximum length of a service port number
#define PORT_LEN 6

// This defines the number of packets to send in each test
#define NUM_PACKETS 20

// This defines the size in bytes of each packet
#define PACKET_SIZE 1024

// This defines the maximum size in bytes of the receive buffer
#define MAX_BUFFER_SIZE 2048

// This defines the number of seconds between tests
#define TEST_INTERVAL 60

// This defines the maximum number of consecutive failed tests before an error is reported
#define MAX_CONSECUTIVE_FAILS 3

// This defines the minimum acceptable packet loss percentage
#define MIN_PACKET_LOSS_PERCENTAGE 0.0

// This defines the maximum acceptable packet loss percentage
#define MAX_PACKET_LOSS_PERCENTAGE 5.0

int main(int argc, char *argv[])
{
    int server_fd, client_fd; // Socket descriptors
    struct addrinfo hints, *server_info, *p; // Address info structures
    struct timeval tv; // Timeout value
    char hostname[HOSTNAME_LEN]; // Hostname or IP address
    char port[PORT_LEN]; // Service port number
    char send_buffer[PACKET_SIZE]; // Send buffer
    char recv_buffer[MAX_BUFFER_SIZE]; // Receive buffer
    int ret; // Return value
    int num_consecutive_fails = 0; // Number of consecutive failed tests
    float packet_loss_percentage; // Packet loss percentage
    int i; // Iteration variable
    
    if (argc != 3) {
        printf("USAGE: %s hostname port\n", argv[0]);
        return -1;
    }
    
    // Copy the hostname and port values from the command line arguments
    strncpy(hostname, argv[1], HOSTNAME_LEN);
    strncpy(port, argv[2], PORT_LEN);
    
    // Set up the hints structure for the address info lookup
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    
    // Get the address info for the server
    if ((ret = getaddrinfo(hostname, port, &hints, &server_info)) != 0) {
        printf("ERROR: getaddrinfo: %s\n", gai_strerror(ret));
        return -1;
    }
    
    // Try to connect to the server using one of the address info structures returned by getaddrinfo
    for (p = server_info; p != NULL; p = p->ai_next) {
        if ((client_fd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("ERROR: socket");
            continue;
        }
        if (connect(client_fd, p->ai_addr, p->ai_addrlen) == -1) {
            perror("ERROR: connect");
            close(client_fd);
            continue;
        }
        break;
    }
    
    // If no successful connections were made, report an error and exit
    if (p == NULL) {
        printf("ERROR: Could not connect to %s:%s\n", hostname, port);
        return -1;
    }
    
    // Free the server info structure
    freeaddrinfo(server_info);
    
    // Set the timeout value for the receive operation
    tv.tv_sec = 1;
    tv.tv_usec = 0;
    setsockopt(client_fd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof tv);
    
    // Randomize the send buffer with pseudo-random data
    srand((unsigned int)time(NULL));
    for (i = 0; i < PACKET_SIZE; i++) {
        send_buffer[i] = rand() % 256;
    }
    
    // Loop forever, testing the network quality periodically
    while (1) {
        // Reset the packet loss percentage
        packet_loss_percentage = 0.0;
        
        // Send the test packets
        for (i = 0; i < NUM_PACKETS; i++) {
            if (send(client_fd, send_buffer, PACKET_SIZE, 0) == -1) {
                perror("ERROR: send");
                num_consecutive_fails++;
                break;
            }
        }
        
        // If all packets were sent successfully, receive the echo packets and calculate the packet loss percentage
        if (i == NUM_PACKETS) {
            for (i = 0; i < NUM_PACKETS; i++) {
                if (recv(client_fd, recv_buffer, MAX_BUFFER_SIZE, 0) == -1) {
                    perror("ERROR: recv");
                    num_consecutive_fails++;
                    break;
                }
                if (memcmp(send_buffer, recv_buffer, PACKET_SIZE) != 0) {
                    printf("ERROR: received packet does not match sent packet\n");
                    num_consecutive_fails++;
                    break;
                }
            }
            if (i == NUM_PACKETS) {
                packet_loss_percentage = 100.0 - (((float)NUM_PACKETS / (float)i) * 100.0);
                num_consecutive_fails = 0;
            }
        }
        
        // If there were too many consecutive failed tests, report an error and exit
        if (num_consecutive_fails > MAX_CONSECUTIVE_FAILS) {
            printf("ERROR: Too many consecutive failed tests\n");
            return -1;
        }
        
        // If the packet loss percentage is outside the acceptable range, report an error
        if ((packet_loss_percentage < MIN_PACKET_LOSS_PERCENTAGE) || (packet_loss_percentage > MAX_PACKET_LOSS_PERCENTAGE)) {
            printf("ERROR: High packet loss percentage (%.2f%%)\n", packet_loss_percentage);
        }
        
        // Sleep for the test interval before starting the next test
        sleep(TEST_INTERVAL);
    }
    
    // Close the socket and exit
    close(client_fd);
    return 0;
}