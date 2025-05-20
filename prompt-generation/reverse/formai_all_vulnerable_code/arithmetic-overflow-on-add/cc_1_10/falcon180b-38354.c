//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_PORT_NUM 65535
#define BUFFER_SIZE 1024

void scan_port(char *ip_address, int port) {
    int sockfd, retval;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Unable to create socket\n");
        return;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    retval = inet_pton(AF_INET, ip_address, &server_addr.sin_addr);
    if (retval <= 0) {
        printf("Error: Invalid IP address\n");
        close(sockfd);
        return;
    }

    retval = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (retval == -1) {
        printf("Port %d: Closed\n", port);
    } else {
        printf("Port %d: Open\n", port);
        close(sockfd);
    }
}

int main() {
    char ip_address[20];
    int start_port, end_port;

    printf("Enter the IP address: ");
    scanf("%s", ip_address);

    printf("Enter the start port number (1-%d): ", MAX_PORT_NUM);
    scanf("%d", &start_port);

    printf("Enter the end port number (1-%d): ", MAX_PORT_NUM);
    scanf("%d", &end_port);

    for (int i = start_port; i <= end_port; i++) {
        scan_port(ip_address, i);
    }

    return 0;
}