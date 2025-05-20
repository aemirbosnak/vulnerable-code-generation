//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int i, j, fd, max_fd, ret, val, port, num_ports;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr;
    fd_set master_fds, read_fds;

    if (argc!= 3) {
        printf("Usage:./port_scanner <IP Address> <Port Range>\n");
        return 1;
    }

    num_ports = atoi(argv[2]) - atoi(argv[1]) + 1;

    if (num_ports > MAX_PORTS) {
        printf("Port range too large\n");
        return 1;
    }

    FD_ZERO(&master_fds);
    FD_ZERO(&read_fds);

    for (i = atoi(argv[1]); i <= atoi(argv[2]); i++) {
        if ((fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
            printf("Error creating socket\n");
            return 1;
        }

        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(i);
        server_addr.sin_addr.s_addr = inet_addr(argv[1]);

        if (connect(fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
            printf("Port %d is open\n", i);
            close(fd);
        } else {
            printf("Port %d is closed\n", i);
        }
    }

    return 0;
}