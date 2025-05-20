//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/select.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int i, j, num_ports, max_sd;
    int *ports;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    if (argc!= 3) {
        printf("Usage: %s <IP address> <port range>\n", argv[0]);
        exit(1);
    }

    if (inet_aton(argv[1], &server_addr.sin_addr) == 0) {
        printf("Invalid IP address\n");
        exit(1);
    }

    num_ports = atoi(argv[2]) - atoi(argv[1]) + 1;
    if (num_ports <= 0 || num_ports > MAX_PORTS) {
        printf("Invalid port range\n");
        exit(1);
    }

    max_sd = socket(AF_INET, SOCK_STREAM, 0);
    if (max_sd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    ports = (int *)malloc(num_ports * sizeof(int));
    if (ports == NULL) {
        printf("Error allocating memory\n");
        exit(1);
    }

    for (i = 0; i < num_ports; i++) {
        ports[i] = socket(AF_INET, SOCK_STREAM, 0);
        if (ports[i] == -1) {
            printf("Error creating socket\n");
            exit(1);
        }
    }

    for (i = 0; i < num_ports; i++) {
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(atoi(argv[1]) + i);
        server_addr.sin_addr.s_addr = inet_addr(argv[1]);

        if (connect(ports[i], (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
            printf("%d: Closed\n", atoi(argv[1]) + i);
        } else {
            printf("%d: Open\n", atoi(argv[1]) + i);
            close(ports[i]);
        }
    }

    free(ports);
    close(max_sd);

    return 0;
}