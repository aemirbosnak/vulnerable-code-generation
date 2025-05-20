//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <IP Address> <Port Range>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = start_port + MAX_PORTS - 1;

    printf("Scanning ports from %d to %d on %s\n", start_port, end_port, ip_address);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(start_port);
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

    while (start_port <= end_port) {
        int result = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

        if (result == 0) {
            printf("Port %d is open\n", ntohs(server_addr.sin_port));
        } else if (errno == ECONNREFUSED) {
            printf("Port %d is closed\n", ntohs(server_addr.sin_port));
        } else {
            printf("Error scanning port %d: %s\n", ntohs(server_addr.sin_port), strerror(errno));
        }

        start_port++;
        memset(&server_addr.sin_port, 0, sizeof(server_addr.sin_port));
        server_addr.sin_port = htons(start_port);
    }

    close(sock);
    return 0;
}