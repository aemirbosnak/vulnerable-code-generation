//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define TRUE   1
#define FALSE  0
#define DEBUG  TRUE

#define MAX_PORTS 65535
#define THREAD_COUNT 100

typedef struct {
    int port;
    char *ip;
    int status;
} port_t;

port_t *ports;
pthread_t threads[THREAD_COUNT];

void *scan_thread(void *arg) {
    int i = *(int *) arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(ports[i].port);
    inet_pton(AF_INET, ports[i].ip, &server_addr.sin_addr);

    int ret = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == 0) {
        ports[i].status = TRUE;
    } else {
        ports[i].status = FALSE;
    }

    close(sock);
    pthread_exit(0);
}

int main() {
    int i;
    ports = (port_t *) malloc(MAX_PORTS * sizeof(port_t));

    for (i = 1; i <= MAX_PORTS; i++) {
        ports[i-1].port = i;
        ports[i-1].ip = "127.0.0.1";
        ports[i-1].status = FALSE;
    }

    for (i = 0; i < THREAD_COUNT; i++) {
        pthread_create(&threads[i], NULL, scan_thread, (void *) i);
    }

    for (i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    for (i = 1; i <= MAX_PORTS; i++) {
        if (ports[i-1].status == TRUE) {
            printf("Port %d is open.\n", i);
        } else {
            printf("Port %d is closed.\n", i);
        }
    }

    return 0;
}