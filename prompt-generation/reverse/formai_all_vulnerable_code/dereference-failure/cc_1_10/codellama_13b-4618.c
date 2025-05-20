//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: systematic
/*
*  Unique C Port Scanner Example Program
*  Author: [Your Name]
*  Date: [Today's Date]
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>

#define MAX_PORTS 1000
#define MAX_HOSTS 100
#define MAX_BUFFER 1024

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <host> <port_range>\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    int port_range = atoi(argv[2]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(host);
    serv_addr.sin_port = htons(port_range);

    int i;
    for (i = 0; i < port_range; i++) {
        if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == 0) {
            printf("Port %d is open\n", i);
        } else {
            printf("Port %d is closed\n", i);
        }
    }

    close(sock);
    return 0;
}