//Code Llama-13B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define MAX_MSG_SIZE 1024
#define MAX_PACKETS 100

struct packet {
    int seq_num;
    int packet_size;
    char data[MAX_MSG_SIZE];
};

void print_packet(struct packet* p) {
    printf("Packet: Seq: %d, Size: %d, Data: %s\n", p->seq_num, p->packet_size, p->data);
}

int main() {
    int sock_fd;
    struct sockaddr_in server_addr;
    struct hostent* server;
    struct packet packet;

    // Create a UDP socket
    if ((sock_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        return -1;
    }

    // Get the server address
    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "Could not get server address\n");
        return -1;
    }

    // Fill in the server address
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(12345);

    // Bind the socket to the local address
    if (bind(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        return -1;
    }

    // Send the packet
    int packet_size = MAX_MSG_SIZE;
    packet.seq_num = 1;
    packet.packet_size = packet_size;
    memset(packet.data, 'A', packet_size);
    if (sendto(sock_fd, &packet, packet_size, 0, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Send failed");
        return -1;
    }

    // Receive the packet
    int recv_len;
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    if ((recv_len = recvfrom(sock_fd, &packet, packet_size, 0, (struct sockaddr *)&client_addr, &client_addr_len)) < 0) {
        perror("Receive failed");
        return -1;
    }

    // Print the packet
    print_packet(&packet);

    // Close the socket
    close(sock_fd);

    return 0;
}