//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

// Function to check if a port is open
int is_port_open(int sock, int port) {
    struct sockaddr_in dest;
    memset(&dest, 0, sizeof(dest));
    dest.sin_family = AF_INET;
    dest.sin_port = htons(port);
    dest.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr*)&dest, sizeof(dest)) == -1) {
        if (errno == ECONNREFUSED) {
            return 0; // Port is closed
        }
        else {
            return -1; // Error
        }
    }
    else {
        close(sock);
        return 1; // Port is open
    }
}

int main() {
    int sock;
    struct sockaddr_in dest;
    int port;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    printf("Enter IP address: ");
    scanf("%s", inet_ntoa(((struct sockaddr_in*)&dest)->sin_addr));

    printf("Enter starting port: ");
    scanf("%d", &port);

    printf("Enter ending port: ");
    scanf("%d", &port);

    if (port < 1 || port > MAX_PORTS) {
        printf("Invalid port\n");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    for (port = port; port <= MAX_PORTS; port++) {
        sprintf(buffer, "Port %d: ", port);
        if (is_port_open(sock, port)) {
            strcat(buffer, "open");
        }
        else {
            strcat(buffer, "closed");
        }
        printf("%s\n", buffer);
    }

    close(sock);
    return 0;
}