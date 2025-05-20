//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

void scan_ports(int sockfd, char *ip_address, int start_port, int end_port) {
    int i, port_number;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr;

    for (i = start_port; i <= end_port; i++) {
        port_number = htons(i);
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = port_number;
        inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

        if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
            printf("Port %d is open on %s\n", i, ip_address);
        } else {
            printf("Port %d is closed on %s\n", i, ip_address);
        }
    }
}

int main(int argc, char *argv[]) {
    int sockfd, port_number;
    struct sockaddr_in server_addr;
    char ip_address[20];

    if (argc!= 3) {
        printf("Usage:./port_scanner <IP Address> <Port Range>\n");
        return -1;
    }

    strcpy(ip_address, argv[1]);
    port_number = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_number);
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Connection failed\n");
        return -1;
    }

    close(sockfd);

    scan_ports(sockfd, ip_address, 1, MAX_PORTS);

    return 0;
}