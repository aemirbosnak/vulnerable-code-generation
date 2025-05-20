//FormAI DATASET v1.0 Category: Port Scanner ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char* argv[]) {

    int lower = 0;
    int upper = 65535;

    if(argc < 2 || argc > 3) {
        perror("Invalid number of arguments!");
        return -1;
    }

    char* host = argv[1];

    if(argc == 3) {
        char* ports = argv[2];
        sscanf(ports, "%d,%d", &lower, &upper);
    }

    printf("Scanning %s from port %d to %d\n", host, lower, upper);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in address;
    struct timeval timeout;

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(host);
    timeout.tv_sec = 2;
    timeout.tv_usec = 0;

    for(int i = lower; i <= upper; i++) {
        address.sin_port = htons(i);
        fd_set fds;
        FD_ZERO(&fds);
        FD_SET(sock, &fds);

        int error = 0;
        int size = sizeof(int);

        if(connect(sock, (struct sockaddr *)&address, sizeof(address)) < 0) {
            getsockopt(sock, SOL_SOCKET, SO_ERROR, &error, (socklen_t*)&size);

            if(error != 0) {
                printf("Port %d is closed\n", i);
            }
        }
        else {
            printf("Port %d is open\n", i);
            close(sock);
            sock = socket(AF_INET, SOCK_STREAM, 0);
            setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(struct timeval));
        }
    }

    close(sock);
    return 0;
}