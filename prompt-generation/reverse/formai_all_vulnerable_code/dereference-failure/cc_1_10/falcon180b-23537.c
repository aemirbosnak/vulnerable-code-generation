//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if(argc!= 3) {
        printf("Usage: %s <IP Address> <Port Range>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = start_port + MAX_PORTS - 1;

    printf("Scanning ports from %d to %d on %s...\n", start_port, end_port, ip_address);

    for(int port = start_port; port <= end_port; port++) {
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if(sockfd == -1) {
            perror("socket");
            continue;
        }

        struct sockaddr_in server_addr;
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);

        if(inet_pton(AF_INET, ip_address, &server_addr.sin_addr) <= 0) {
            perror("inet_pton");
            close(sockfd);
            continue;
        }

        if(connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
            printf("Port %d is open.\n", port);
            close(sockfd);
        } else {
            printf("Port %d is closed.\n", port);
            close(sockfd);
        }
    }

    return 0;
}