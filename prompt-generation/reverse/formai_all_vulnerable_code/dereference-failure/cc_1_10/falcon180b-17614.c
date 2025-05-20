//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX 65535
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Range>\n", argv[0]);
        exit(1);
    }

    char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = start_port + MAX - 1;

    printf("Scanning ports from %d to %d on %s...\n", start_port, end_port, ip);

    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip);

    for (int port = start_port; port <= end_port; port++) {
        serv_addr.sin_port = htons(port);

        int result = connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

        if (result == 0) {
            printf("Port %d is open on %s\n", port, ip);
        } else if (errno == ECONNREFUSED) {
            printf("Port %d is closed on %s\n", port, ip);
        } else {
            printf("Error connecting to port %d on %s: %s\n", port, ip, strerror(errno));
        }
    }

    close(sock);

    return 0;
}