//FormAI DATASET v1.0 Category: Port Scanner ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

void scan_ports(char *ip_address, int start_port, int end_port) {
    struct sockaddr_in server_addr;
    int sock_fd, cnt;
    char banner[128];

    printf("Scanning ports %d to %d on %s\n", start_port, end_port, ip_address);

    for (int port = start_port; port <= end_port; port++) {
        sock_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (sock_fd < 0) {
            perror("socket");
            exit(1);
        }

        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = inet_addr(ip_address);
        server_addr.sin_port = htons(port);

        if (connect(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == 0) {
            // Port is open
            printf("Port %d is open, service: ", port);
            cnt = recv(sock_fd, banner, sizeof(banner), MSG_PEEK | MSG_DONTWAIT);
            if (cnt > 0) {
                banner[cnt] = '\0';
                printf("%s", banner);
            }
            else {
                printf("unknown");
            }
            printf("\n");
        }

        close(sock_fd);
    }
}

int main() {
    char ip_address[16];
    int start_port, end_port;

    printf("Enter IP address to scan: ");
    scanf("%s", ip_address);
    printf("Enter start port: ");
    scanf("%d", &start_port);
    printf("Enter end port: ");
    scanf("%d", &end_port);

    scan_ports(ip_address, start_port, end_port);

    return 0;
}