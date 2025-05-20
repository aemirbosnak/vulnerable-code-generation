//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PACKET_SIZE 65535

void monitor_packets(char *ip_address, int port) {
    int raw_socket;
    struct sockaddr_in server_addr;
    char packet_buffer[PACKET_SIZE];
    int recv_size;

    // Create raw socket for packet monitoring
    raw_socket = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (raw_socket < 0) {
        printf("Error creating raw socket\n");
        exit(1);
    }

    // Bind to local IP address
    struct sockaddr_in local_addr;
    memset(&local_addr, 0, sizeof(local_addr));
    local_addr.sin_family = AF_INET;
    local_addr.sin_addr.s_addr = inet_addr(ip_address);
    local_addr.sin_port = htons(port);
    
    int bind_result = bind(raw_socket, (struct sockaddr *)&local_addr, sizeof(local_addr));
    if (bind_result < 0) {
        printf("Error binding to local IP address\n");
        exit(1);
    }

    printf("Packet monitoring started on %s:%d...\n", ip_address, port);

    // Loop to receive incoming packets and print their details
    while (1) {
        memset(&server_addr, 0, sizeof(server_addr));
        recv_size = recvfrom(raw_socket, packet_buffer, PACKET_SIZE, 0, (struct sockaddr *)&server_addr, (socklen_t *)&server_addr);

        if (recv_size > 0) {
            printf("Received packet from %s:%d\n", inet_ntoa(server_addr.sin_addr), ntohs(server_addr.sin_port));
            printf("Packet size : %d\n", recv_size);
            printf("Packet data : \n");

            // Print packet data in hex format
            for (int i=0; i < recv_size; i++) {
                printf("%02x ", packet_buffer[i]);
                if (!((i+1) % 16))
                    printf("\n");
            }
            printf("\n\n");
        }
    }
    close(raw_socket);
}

int main() {
    char ip_address[16];
    int port;

    printf("Enter IP address to monitor : ");
    scanf("%s", ip_address);

    printf("Enter port number to monitor : ");
    scanf("%d", &port);

    monitor_packets(ip_address, port);

    return 0;
}