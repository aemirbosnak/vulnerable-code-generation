//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX 65535
#define TRUE 1
#define FALSE 0
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock, port, opt = TRUE, ret;
    struct sockaddr_in serv_addr;
    char buffer[BUF_SIZE];
    int addrlen = sizeof(serv_addr);

    if (argc!= 3) {
        printf("Usage: %s <host> <port_range>\n", argv[0]);
        exit(1);
    }

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set options
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
        printf("Error setting options\n");
        exit(1);
    }

    // Set up address structure
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);

    // Connect to host
    if (connect(sock, (struct sockaddr *) &serv_addr, addrlen) == -1) {
        printf("Error connecting to host\n");
        exit(1);
    }

    // Loop through port range
    for (port = 1; port <= atoi(argv[2]); port++) {
        // Send SYN packet
        ret = send(sock, "SYN", strlen("SYN"), 0);
        if (ret == -1) {
            printf("Error sending SYN packet\n");
            exit(1);
        }

        // Receive response
        ret = recv(sock, buffer, BUF_SIZE, 0);
        if (ret == -1) {
            printf("Error receiving response\n");
            exit(1);
        }

        // Check response for open port
        if (strstr(buffer, "SYN-ACK")!= NULL) {
            printf("Port %d is open\n", port);
        } else if (strstr(buffer, "RST-ACK")!= NULL) {
            printf("Port %d is closed\n", port);
        } else {
            printf("Error: Unknown response\n");
        }
    }

    // Close socket
    close(sock);

    return 0;
}