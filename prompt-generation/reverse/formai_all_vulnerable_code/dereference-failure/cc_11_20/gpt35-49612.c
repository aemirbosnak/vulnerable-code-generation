//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/time.h>

#define MAX_BUFF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <ip address> <port>\n", argv[0]);
        return 1;
    }
    
    // Initialize socket
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1) {
        perror("failed to create socket");
        return 1;
    }

    // Set the IP and port to connect to
    struct sockaddr_in server_addr;
    memset(&server_addr, '0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        printf("Invalid IP address\n");
        return 1;
    }

    // Connect to the server
    if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect failed");
        return 1;
    }
    
    // Set socket non blocking
    int flags = fcntl(sock_fd, F_GETFL, 0);
    fcntl(sock_fd, F_SETFL, flags | O_NONBLOCK);

    char recv_buff[MAX_BUFF_SIZE];
    int recv_size;
    int total_recv_bytes = 0;
    
    struct timeval current_time;
    struct timeval last_time;
    gettimeofday(&last_time, NULL);

    int time_diff;
    int total_time_diff = 0;
    int total_packets = 0;
    int total_packet_size = 0;

    while (1) {
        // Check if there's any data available to read
        fd_set read_set;
        FD_ZERO(&read_set);
        FD_SET(sock_fd, &read_set);
        int rc = select(sock_fd + 1, &read_set, NULL, NULL, NULL);
        if (rc == -1) {
            perror("select failed");
            return 1;
        }
        if (rc > 0 && FD_ISSET(sock_fd, &read_set)) {
            recv_size = recv(sock_fd, recv_buff, MAX_BUFF_SIZE, 0);
            if (recv_size == -1 && errno != EAGAIN && errno != EWOULDBLOCK) {
                perror("recv failed");
                return 1;
            } else if (recv_size > 0) {
                total_recv_bytes += recv_size;
                gettimeofday(&current_time, NULL);
                time_diff = (current_time.tv_sec - last_time.tv_sec) * 1000 + (current_time.tv_usec - last_time.tv_usec) / 1000;
                total_time_diff += time_diff;
                total_packets++;
                total_packet_size += recv_size;
                last_time = current_time;
            }
        }

        // Display QoS information every second
        if (total_time_diff > 1000) {
            float avg_packet_size = (float)total_packet_size / total_packets;
            float avg_packets_per_sec = (float)total_packets / (total_time_diff / 1000.0f);
            float avg_bytes_per_sec = (float)total_recv_bytes / (total_time_diff / 1000.0f);
            printf("Average Packet Size: %.2f bytes\n", avg_packet_size);
            printf("Average Packets per Second: %.2f\n", avg_packets_per_sec);
            printf("Average Bytes per Second: %.2f\n", avg_bytes_per_sec);
            total_packets = 0;
            total_packet_size = 0;
            total_recv_bytes = 0;
            total_time_diff = 0;
        }
    }

    close(sock_fd);
    return 0;
}