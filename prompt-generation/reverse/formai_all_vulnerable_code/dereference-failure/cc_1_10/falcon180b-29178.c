//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: modular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

void print_usage() {
    printf("Usage:./scanner <IP Address> <Start Port> <End Port>\n");
}

int is_valid_port(int port) {
    if (port < 1 || port > MAX_PORTS) {
        return 0;
    }
    return 1;
}

void scan_ports(char *ip_address, int start_port, int end_port) {
    int sockfd, port;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip_address, &serv_addr.sin_addr);

    for (port = start_port; port <= end_port; port++) {
        if (is_valid_port(port)) {
            connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

            if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == 0) {
                printf("Port %d is open\n", port);
            } else {
                printf("Port %d is closed\n", port);
            }

            close(sockfd);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        print_usage();
        exit(1);
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (!is_valid_port(start_port) ||!is_valid_port(end_port)) {
        print_usage();
        exit(1);
    }

    scan_ports(ip_address, start_port, end_port);

    return 0;
}