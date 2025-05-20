//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX 65535
#define TRUE 1
#define FALSE 0
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock, port, max_ports, i, num_ports, opt = 1;
    struct sockaddr_in server;
    char buffer[BUF_SIZE];

    printf("Enter the IP address of the target host: ");
    scanf("%s", argv[1]);

    printf("Enter the number of ports to scan (1-%d): ", MAX);
    scanf("%d", &max_ports);

    printf("Enter the starting port number: ");
    scanf("%d", &port);

    num_ports = max_ports - (port - 1);

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt))) {
        printf("Error setting socket option\n");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_port = htons(port);

    for (i = 0; i < num_ports; i++) {
        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
            printf("Port %d is open\n", port);
        } else {
            printf("Port %d is closed\n", port);
        }
        port++;
    }

    close(sock);

    return 0;
}