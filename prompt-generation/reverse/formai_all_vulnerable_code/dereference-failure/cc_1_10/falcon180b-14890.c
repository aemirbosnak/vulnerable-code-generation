//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define MAX_HOST_NAME 256
#define MAX_DATA_SIZE 1024

// Function prototypes
void scan_network(char *ip_address);
void send_packet(int sock, struct sockaddr *addr);
void receive_packet(int sock, struct sockaddr *addr);

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return 1;
    }

    char ip_address[MAX_HOST_NAME];
    strcpy(ip_address, argv[1]);

    scan_network(ip_address);

    return 0;
}

void scan_network(char *ip_address) {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if(sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(7); // Echo port

    if(inet_pton(AF_INET, ip_address, &server_addr.sin_addr) <= 0) {
        printf("Invalid IP address\n");
        close(sock);
        exit(1);
    }

    send_packet(sock, (struct sockaddr *)&server_addr);
    receive_packet(sock, (struct sockaddr *)&server_addr);

    close(sock);
}

void send_packet(int sock, struct sockaddr *addr) {
    char data[MAX_DATA_SIZE];
    memset(data, 0, MAX_DATA_SIZE);
    strcpy(data, "Scanning network...");

    sendto(sock, data, strlen(data), 0, addr, sizeof(struct sockaddr));
}

void receive_packet(int sock, struct sockaddr *addr) {
    char buffer[MAX_DATA_SIZE];
    memset(buffer, 0, MAX_DATA_SIZE);

    int bytes_received = recvfrom(sock, buffer, MAX_DATA_SIZE, 0, addr, NULL);
    if(bytes_received <= 0) {
        printf("Error receiving packet\n");
        return;
    }

    printf("Received: %s\n", buffer);
}