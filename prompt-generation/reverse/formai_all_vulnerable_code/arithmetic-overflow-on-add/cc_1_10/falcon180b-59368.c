//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX 1024

// Function to check if port is open
int check_port(int sock, int port) {
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        return 0;
    } else {
        return 1;
    }
}

// Recursive function to scan ports
void scan_ports(int start_port, int end_port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket.\n");
        exit(1);
    }

    for (int i = start_port; i <= end_port; i++) {
        if (check_port(sock, i)) {
            printf("Port %d is open.\n", i);
        }
    }

    close(sock);
}

// Main function to get user input and call scan_ports function
int main() {
    int start_port, end_port;

    printf("Enter start port: ");
    scanf("%d", &start_port);

    printf("Enter end port: ");
    scanf("%d", &end_port);

    scan_ports(start_port, end_port);

    return 0;
}