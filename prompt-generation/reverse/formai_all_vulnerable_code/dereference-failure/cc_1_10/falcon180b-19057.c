//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_PORTS 65535
#define BUF_SIZE 1024

// Function to check if a port is open
int check_port(int sock, int port) {
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        if (errno == ECONNREFUSED) {
            return 0; // Port is closed
        } else {
            return -1; // Error
        }
    } else {
        return 1; // Port is open
    }
}

int main() {
    int sock;
    int i;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket!\n");
        exit(1);
    }

    for (i = 1; i <= MAX_PORTS; i++) {
        // Check if port is open
        if (check_port(sock, i) == 1) {
            printf("Port %d is open\n", i);
        }
    }

    close(sock);
    return 0;
}