//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024
#define USAGE "Usage:./ping <IP address or domain name> <number of packets>"

void print_usage() {
    printf("%s\n", USAGE);
}

void die(char* msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        print_usage();
        exit(1);
    }

    char* target = argv[1];
    int num_packets = atoi(argv[2]);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(7); // Echo port

    if (inet_aton(target, &server_addr.sin_addr) == 0) {
        die("Invalid IP address or domain name");
    }

    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        die("Failed to create socket");
    }

    char buffer[BUFFER_SIZE];
    for (int i = 0; i < num_packets; i++) {
        sprintf(buffer, "Packet %d", i + 1);
        sendto(sock, buffer, strlen(buffer), 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
        usleep(100000); // Wait for 100ms between packets
    }

    close(sock);
    return 0;
}