//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Range>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = start_port + MAX_PORTS - 1;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(start_port);
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

    char buffer[BUFFER_SIZE];
    snprintf(buffer, BUFFER_SIZE, "Scanning ports %d-%d on %s...\n", start_port, end_port, ip_address);
    printf("%s", buffer);

    for (int port = start_port; port <= end_port; port++) {
        server_addr.sin_port = htons(port);

        if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
            if (errno == ECONNREFUSED) {
                printf("Port %d is closed.\n", port);
            } else if (errno == ETIMEDOUT) {
                printf("Port %d is filtered.\n", port);
            } else {
                printf("Error connecting to port %d: %s\n", port, strerror(errno));
            }
        } else {
            printf("Port %d is open.\n", port);
            close(sock);
        }
    }

    close(sock);
    return 0;
}