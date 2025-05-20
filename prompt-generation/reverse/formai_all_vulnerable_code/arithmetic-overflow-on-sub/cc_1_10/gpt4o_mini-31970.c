//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024
#define PORT 8080
#define PACKET_COUNT 10

struct packet_info {
    struct timeval send_time;
    struct timeval receive_time;
    double latency;
};

void log_packet_info(struct packet_info *p_info, int count) {
    FILE *log_file = fopen("qos_log.txt", "a");
    if (log_file == NULL) {
        perror("Could not open log file");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(log_file, "Packet %d - Send Time: %ld.%06ld, Receive Time: %ld.%06ld, Latency: %.6f seconds\n",
                i + 1,
                p_info[i].send_time.tv_sec, p_info[i].send_time.tv_usec,
                p_info[i].receive_time.tv_sec, p_info[i].receive_time.tv_usec,
                p_info[i].latency);
    }
    fclose(log_file);
}

void monitor_qos(const char *host) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    struct packet_info p_info[PACKET_COUNT];
    int count = 0;

    // Create a socket
    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    // Convert IP address from text to binary
    if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
        perror("Invalid address / Address not supported");
        exit(EXIT_FAILURE);
    }

    printf("Starting QoS monitoring to %s on port %d...\n", host, PORT);

    for (count = 0; count < PACKET_COUNT; count++) {
        gettimeofday(&p_info[count].send_time, NULL);
        
        // Send a dummy packet
        snprintf(buffer, BUFFER_SIZE, "Ping %d", count + 1);
        sendto(sock, buffer, strlen(buffer), 0, (const struct sockaddr *)&server_addr, sizeof(server_addr));

        // Wait for response
        socklen_t addr_len = sizeof(server_addr);
        recvfrom(sock, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&server_addr, &addr_len);
        
        gettimeofday(&p_info[count].receive_time, NULL);
        
        // Calculate latency
        p_info[count].latency = (p_info[count].receive_time.tv_sec - p_info[count].send_time.tv_sec) +
                                  (p_info[count].receive_time.tv_usec - p_info[count].send_time.tv_usec) / 1000000.0;
        
        printf("Packet %d sent, latency: %.6f seconds\n", count + 1, p_info[count].latency);
        usleep(500000); // Wait for 500 milliseconds before sending next packet
    }

    // Log the packet info
    log_packet_info(p_info, count);

    // Close the socket
    close(sock);
    printf("QoS monitoring completed. Results logged to qos_log.txt\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <host_ip>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    monitor_qos(argv[1]);

    return 0;
}