//Falcon-180B DATASET v1.0 Category: Firewall ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define WHITE_SPACE " \t\r\n"
#define DELIMITER ":"

struct packet {
    char src_ip[16];
    char dst_ip[16];
    char src_port[6];
    char dst_port[6];
    char protocol[8];
};

void process_packet(struct packet *packet) {
    printf("Source IP: %s\n", packet->src_ip);
    printf("Destination IP: %s\n", packet->dst_ip);
    printf("Source Port: %s\n", packet->src_port);
    printf("Destination Port: %s\n", packet->dst_port);
    printf("Protocol: %s\n", packet->protocol);
}

void parse_packet(char *buffer, struct packet *packet) {
    char *token = strtok(buffer, WHITE_SPACE);
    strcpy(packet->src_ip, token);

    token = strtok(NULL, WHITE_SPACE);
    strcpy(packet->dst_ip, token);

    token = strtok(NULL, WHITE_SPACE);
    strcpy(packet->src_port, token);

    token = strtok(NULL, WHITE_SPACE);
    strcpy(packet->dst_port, token);

    token = strtok(NULL, WHITE_SPACE);
    strcpy(packet->protocol, token);
}

int main() {
    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(0);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    while (1) {
        int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Error receiving packet\n");
            exit(1);
        }

        struct packet packet;
        parse_packet(buffer, &packet);
        process_packet(&packet);
    }

    close(sock);
    return 0;
}