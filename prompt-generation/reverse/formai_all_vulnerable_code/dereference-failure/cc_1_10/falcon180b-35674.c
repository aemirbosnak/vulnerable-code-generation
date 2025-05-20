//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

void scan_ports(int start_port, int end_port) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];
    int addrlen = sizeof(serv_addr);

    for (portno = start_port; portno <= end_port; portno++) {
        memset(&serv_addr, 0, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(portno);
        serv_addr.sin_addr.s_addr = INADDR_ANY;

        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
            printf("Error: Unable to create socket\n");
            exit(1);
        }

        if (connect(sockfd, (struct sockaddr *)&serv_addr, addrlen) == 0) {
            printf("Port %d is open\n", portno);
            close(sockfd);
        } else {
            printf("Port %d is closed\n", portno);
            close(sockfd);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <start_port> <end_port> <host_ip>\n", argv[0]);
        return 1;
    }

    int start_port = atoi(argv[1]);
    int end_port = atoi(argv[2]);
    char *host_ip = argv[3];

    scan_ports(start_port, end_port);

    return 0;
}