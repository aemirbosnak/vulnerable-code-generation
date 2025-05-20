//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char buffer[BUFFER_SIZE];
    int port;
    int result;

    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Range>\n", argv[0]);
        return 1;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &server.sin_addr);
    port = atoi(argv[2]);

    for (int i = 0; i < MAX_PORTS; i++) {
        if (i == port)
            continue;

        result = connect(sock, (struct sockaddr *)&server, sizeof(server));
        if (result!= -1) {
            printf("Port %d is open\n", i);
            close(sock);
            return 0;
        }
    }

    printf("No open ports found\n");
    close(sock);
    return 0;
}