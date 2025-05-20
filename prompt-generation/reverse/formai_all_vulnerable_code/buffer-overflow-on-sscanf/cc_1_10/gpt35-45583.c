//FormAI DATASET v1.0 Category: Port Scanner ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <IP Address> <Port Range>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    char *port_range = argv[2];

    int port_start, port_end;
    sscanf(port_range, "%d-%d", &port_start, &port_end);

    struct sockaddr_in server_address;

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("Socket creation error");
        return 1;
    }

    memset(&server_address, '0', sizeof(server_address));

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port_start);
    inet_pton(AF_INET, ip_address, &server_address.sin_addr);

    int connected = connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address));

    if (connected == 0) {
        printf("Port %d is open\n", port_start);
    }

    int i;
    for (i = port_start+1; i <= port_end; i++) {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);

        if (sockfd < 0) {
            perror("Socket creation error");
            return 1;
        }

        memset(&server_address, '0', sizeof(server_address));

        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(i);
        inet_pton(AF_INET, ip_address, &server_address.sin_addr);

        connected = connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address));

        if (connected == 0) {
            printf("Port %d is open\n", i);
        }

        close(sockfd);
    }

    return 0;
}