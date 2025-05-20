//FormAI DATASET v1.0 Category: Port Scanner ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Array to store open ports
int open_ports[100], num_open_ports = 0;

// Function to scan ports
void scan_ports(char *ip_addr, int start_port, int end_port)
{
    int i, sock;
    struct sockaddr_in target;

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    // Set target IP address and port
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(ip_addr);

    // Scan through specified range of ports
    for (i = start_port; i <= end_port; i++) {
        target.sin_port = htons(i);

        // Try connecting to port
        if (connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0) {
            // Port is open
            open_ports[num_open_ports++] = i;
        }
        else {
            // Port is closed
            close(sock);
            sock = socket(AF_INET, SOCK_STREAM, 0);
        }
    }

    // Close socket
    close(sock);
}

int main(int argc, char **argv)
{
    int i;
    char ip_addr[16];
    int start_port, end_port;

    // Get IP address and port range from user
    printf("Enter IP address: ");
    scanf("%s", ip_addr);
    printf("Enter starting port number: ");
    scanf("%d", &start_port);
    printf("Enter ending port number: ");
    scanf("%d", &end_port);

    // Scan ports
    scan_ports(ip_addr, start_port, end_port);

    // Print open ports
    printf("Open ports:\n");
    for (i = 0; i < num_open_ports; i++) {
        printf("%d\n", open_ports[i]);
    }

    return 0;
}