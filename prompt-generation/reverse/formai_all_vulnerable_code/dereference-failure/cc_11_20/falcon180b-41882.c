//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>

#define PORT_MAX 65535
#define PORT_MIN 1
#define TIMEOUT 2000 // milliseconds
#define BUF_SIZE 1024

int main(int argc, char **argv) {
    if (argc < 4) {
        printf("Usage: %s <IP Address> <Start Port> <End Port>\n", argv[0]);
        exit(1);
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < PORT_MIN || start_port > PORT_MAX ||
        end_port < PORT_MIN || end_port > PORT_MAX) {
        printf("Invalid port range.\n");
        exit(1);
    }

    int *ports = calloc(end_port - start_port + 1, sizeof(int));
    int num_ports = 0;

    for (int i = start_port; i <= end_port; i++) {
        ports[num_ports++] = i;
    }

    int num_children = 0;
    pid_t *children = NULL;

    for (int i = 0; i < num_ports; i++) {
        pid_t pid = fork();

        if (pid == -1) {
            printf("Fork failed.\n");
            exit(1);
        } else if (pid == 0) {
            int port = ports[i];
            char buf[BUF_SIZE];

            snprintf(buf, BUF_SIZE, "Port %d is open.\n", port);
            write(1, buf, strlen(buf));

            exit(0);
        } else {
            children[num_children++] = pid;
        }
    }

    for (int i = 0; i < num_children; i++) {
        int status;
        waitpid(children[i], &status, 0);
    }

    free(children);
    free(ports);

    return 0;
}