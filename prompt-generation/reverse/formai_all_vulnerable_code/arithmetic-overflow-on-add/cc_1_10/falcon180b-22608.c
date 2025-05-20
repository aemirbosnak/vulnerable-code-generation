//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

// Function to check if a port is open or not
int check_port(int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    int result = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

    if (result == 0) {
        close(sock);
        return 1; // Port is open
    } else {
        close(sock);
        return 0; // Port is closed
    }
}

// Function to scan a range of ports
void scan_ports(int start_port, int end_port) {
    for (int i = start_port; i <= end_port; i++) {
        if (check_port(i)) {
            printf("Port %d is open\n", i);
        }
    }
}

int main() {
    int start_port, end_port;

    printf("Enter start port: ");
    scanf("%d", &start_port);
    printf("Enter end port: ");
    scanf("%d", &end_port);

    scan_ports(start_port, end_port);

    return 0;
}