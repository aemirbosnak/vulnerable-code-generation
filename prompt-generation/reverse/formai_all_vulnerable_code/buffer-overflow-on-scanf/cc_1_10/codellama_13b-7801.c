//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT_RANGE_START 1024
#define PORT_RANGE_END 65535
#define MAX_PORTS 1024
#define MAX_CONNECTIONS 10

int main() {
    int i, j;
    int sock;
    struct sockaddr_in server;
    struct hostent *host;
    struct servent *service;
    char hostname[256];
    char port_str[6];
    char buf[1024];
    int port_range[MAX_PORTS];

    printf("Enter hostname: ");
    scanf("%s", hostname);

    host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        return 1;
    }

    printf("Enter port range: ");
    scanf("%d-%d", &port_range[0], &port_range[MAX_PORTS - 1]);

    for (i = 0; i < MAX_CONNECTIONS; i++) {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            perror("socket");
            return 1;
        }

        for (j = 0; j < MAX_PORTS; j++) {
            if (port_range[j] == 0) {
                continue;
            }

            printf("Checking port %d...\n", port_range[j]);

            server.sin_family = AF_INET;
            server.sin_port = htons(port_range[j]);
            server.sin_addr = *((struct in_addr *)host->h_addr);
            memset(&server.sin_zero, 0, sizeof(server.sin_zero));

            if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
                printf("Port %d is open\n", port_range[j]);
                break;
            }
        }

        close(sock);
    }

    return 0;
}