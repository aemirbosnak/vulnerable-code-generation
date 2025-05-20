//FormAI DATASET v1.0 Category: Port Scanner ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MIN_PORT 1
#define MAX_PORT 65535
#define TIMEOUT 5

bool is_port_open(char *target, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }
    
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(target);
    
    fd_set set;
    FD_ZERO(&set);
    FD_SET(sock, &set);
    
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    
    int ret = connect(sock, (struct sockaddr*) &addr, sizeof(addr));
    if (ret == 0) {
        printf("Port %d is open!\n", port);
        close(sock);
        return true;
    } else if (errno == EINPROGRESS) {
        ret = select(sock+1, NULL, &set, NULL, &timeout);
        if (ret > 0 && FD_ISSET(sock, &set)) {
            printf("Port %d is open!\n", port);
            close(sock);
            return true;
        } else {
            close(sock);
            return false;
        }
    }
    close(sock);
    return false;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <target>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    char *target = argv[1];
    printf("Scanning ports on target %s...\n", target);
    for (int port=MIN_PORT; port<=MAX_PORT; port++) {
        is_port_open(target, port);
    }
    printf("Scan complete!\n");
    return 0;
}