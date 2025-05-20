//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Range>\n", argv[0]);
        exit(1);
    }

    char *ip_address = argv[1];
    char *port_range = argv[2];
    int start_port, end_port;

    if (sscanf(port_range, "%d-%d", &start_port, &end_port)!= 2) {
        printf("Invalid port range.\n");
        exit(1);
    }

    for (int port = start_port; port <= end_port; port++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            printf("Error creating socket: %s\n", strerror(errno));
            exit(1);
        }

        struct sockaddr_in server_addr;
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

        if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
            printf("Port %d is open.\n", port);
            close(sock);
        } else {
            printf("Port %d is closed.\n", port);
            close(sock);
        }
    }

    return 0;
}