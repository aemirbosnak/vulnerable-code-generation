//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <errno.h>
#include <time.h>

#define PACKET_SIZE 1024
#define PORT 8080
#define TIMEOUT 1

void log_qos_data(const char *data) {
    FILE *file = fopen("qos_log.txt", "a");
    if (file != NULL) {
        fprintf(file, "%s\n", data);
        fclose(file);
    } else {
        perror("Could not open log file");
    }
}

void display_qos_info(int response_time, int received_packets) {
    printf("Quality of Service Metrics:\n");
    printf("Response Time: %d ms\n", response_time);
    printf("Received Packets: %d\n", received_packets);
}

int create_socket() {
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

void configure_socket_options(int sockfd) {
    int optval = 1;
    if (setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &optval, sizeof(optval)) < 0) {
        perror("Failed to set socket options");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
}

void setup_server_address(struct sockaddr_in *server_addr) {
    memset(server_addr, 0, sizeof(*server_addr));
    server_addr->sin_family = AF_INET;
    server_addr->sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr->sin_port = htons(PORT);
}

int send_ping(int sockfd, struct sockaddr_in *server_addr) {
    char packet[PACKET_SIZE];
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;

    int packet_size = snprintf(packet, sizeof(packet), "QoS Monitor Ping");
    if (sendto(sockfd, packet, packet_size, 0, (struct sockaddr *)server_addr, sizeof(*server_addr)) < 0) {
        perror("Failed to send packet");
        return -1;
    }

    return 0;
}

int receive_response(int sockfd) {
    char buffer[PACKET_SIZE];
    struct sockaddr_in response_addr;
    socklen_t addr_len = sizeof(response_addr);
   
    fd_set read_fds;
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    FD_ZERO(&read_fds);
    FD_SET(sockfd, &read_fds);
    
    if (select(sockfd + 1, &read_fds, NULL, NULL, &timeout) > 0) {
        int bytes_received = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&response_addr, &addr_len);
        if (bytes_received < 0) {
            perror("Failed to receive packet");
            return -1;
        } else {
            return 0; // Response received
        }
    }

    return -1; // Timeout or error
}

int main() {
    printf("Welcome to QoS Monitor\n");

    int sockfd = create_socket();
    configure_socket_options(sockfd);
    
    struct sockaddr_in server_addr;
    setup_server_address(&server_addr);
    
    int total_packets = 10;
    int received_packets = 0;
    clock_t start_time, end_time;

    for (int i = 0; i < total_packets; i++) {
        start_time = clock();
        if (send_ping(sockfd, &server_addr) == 0) {
            if (receive_response(sockfd) == 0) {
                received_packets++;
            }
        }
        end_time = clock();

        int response_time = (int)(((end_time - start_time) * 1000) / CLOCKS_PER_SEC);
        char log_data[100];
        snprintf(log_data, sizeof(log_data), "Ping #%d: Response Time: %d ms", i + 1, response_time);
        log_qos_data(log_data);

        sleep(1); // Wait before the next ping
    }
    
    display_qos_info((int)(((end_time - start_time) * 1000) / CLOCKS_PER_SEC / total_packets), received_packets);
    
    close(sockfd);
    printf("QoS monitoring completed, results logged in qos_log.txt\n");
    return 0;
}