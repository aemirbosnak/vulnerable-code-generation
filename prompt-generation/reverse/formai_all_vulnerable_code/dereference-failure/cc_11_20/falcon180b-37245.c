//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Range>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = start_port + MAX_PORTS - 1;

    printf("Scanning ports from %d to %d on IP address %s...\n", start_port, end_port, ip_address);

    int max_fds = end_port - start_port + 1;
    int *ports = malloc(sizeof(int) * max_fds);
    for (int i = 0; i < max_fds; i++) {
        ports[i] = start_port + i;
    }

    int num_children = 0;
    pid_t *children = NULL;

    while (num_children < max_fds) {
        int status;
        pid_t pid = waitpid(-1, &status, WNOHANG);

        if (pid == -1 && errno!= ECHILD) {
            printf("waitpid() failed: %s\n", strerror(errno));
            return 1;
        }

        if (pid > 0) {
            for (int i = 0; i < num_children; i++) {
                if (children[i] == pid) {
                    children[i] = 0;
                    break;
                }
            }
            num_children--;
        }

        if (num_children < max_fds) {
            int port = ports[num_children];
            char command[BUFFER_SIZE];
            sprintf(command, "nc -z %s %d >/dev/null 2>&1", ip_address, port);

            if (system(command) == 0) {
                printf("Port %d is open.\n", port);
            } else {
                printf("Port %d is closed.\n", port);
            }

            ports[num_children] = 0;
            num_children++;
        }
    }

    free(ports);
    return 0;
}