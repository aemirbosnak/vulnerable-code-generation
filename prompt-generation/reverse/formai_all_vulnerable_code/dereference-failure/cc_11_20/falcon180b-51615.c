//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024
#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[]) {
    int sock, ret;
    struct sockaddr_in server_addr;
    int port, num_ports;
    char response[BUFFER_SIZE];
    int *ports;
    int num_open_ports = 0;

    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Number of Ports>\n", argv[0]);
        exit(1);
    }

    // Convert IP address to integer representation
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    // Convert number of ports to integer representation
    num_ports = atoi(argv[2]);

    ports = (int *) malloc(num_ports * sizeof(int));
    if (ports == NULL) {
        printf("Error: Failed to allocate memory.\n");
        exit(1);
    }

    // Initialize all ports as closed
    for (int i = 0; i < num_ports; i++) {
        ports[i] = FALSE;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: Failed to create socket.\n");
        exit(1);
    }

    for (port = 1; port <= num_ports; port++) {
        if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == 0) {
            close(sock);
            ports[port - 1] = TRUE;
            num_open_ports++;
        } else if (errno == ECONNREFUSED) {
            ports[port - 1] = FALSE;
        } else if (errno!= ECONNRESET) {
            printf("Error: Failed to connect to port %d.\n", port);
            exit(1);
        }
    }

    printf("Scanning complete.\n");
    printf("Total ports scanned: %d\n", num_ports);
    printf("Open ports:\n");

    for (int i = 0; i < num_ports; i++) {
        if (ports[i]) {
            sprintf(response, "Port %d is open.\n", i + 1);
            printf("%s", response);
        }
    }

    free(ports);
    close(sock);
    return 0;
}