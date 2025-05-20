//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_PORTS 1000
#define MAX_HOSTS 1000

// Function prototypes
void banner();
void usage();
int scan_port(const char *ip, int port);
void scan_ports(const char *ip, int *ports, int num_ports);

// Main function
int main(int argc, char **argv) {
    if (argc < 2) {
        usage();
        return 1;
    }

    // Parse command line arguments
    char *ip = argv[1];
    int ports[MAX_PORTS];
    int num_ports = 0;
    for (int i = 2; i < argc; i++) {
        int port = atoi(argv[i]);
        if (port > 0 && port < 65536) {
            ports[num_ports++] = port;
        }
    }

    // Print banner
    banner();

    // Scan ports
    scan_ports(ip, ports, num_ports);

    return 0;
}

// Function definitions
void banner() {
    printf("C Port Scanner v1.0\n");
    printf("-------------------\n");
}

void usage() {
    printf("Usage: portscan <ip> [port1 port2 ... portN]\n");
}

int scan_port(const char *ip, int port) {
    int sock;
    struct sockaddr_in addr;
    struct hostent *host;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Set address structure
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    host = gethostbyname(ip);
    if (host == NULL) {
        fprintf(stderr, "ERROR: Could not resolve hostname %s\n", ip);
        return 1;
    }
    memcpy(&addr.sin_addr, host->h_addr, host->h_length);

    // Connect to socket
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        close(sock);
        return 1;
    }

    // Close socket
    close(sock);

    return 0;
}

void scan_ports(const char *ip, int *ports, int num_ports) {
    for (int i = 0; i < num_ports; i++) {
        int port = ports[i];
        printf("Scanning port %d... ", port);
        if (scan_port(ip, port) == 0) {
            printf("OPEN\n");
        } else {
            printf("CLOSED\n");
        }
    }
}