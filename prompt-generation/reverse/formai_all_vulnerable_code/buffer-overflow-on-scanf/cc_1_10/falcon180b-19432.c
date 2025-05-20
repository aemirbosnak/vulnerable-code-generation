//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535

int ports[MAX_PORTS];
int num_ports = 0;

void *scan_port(void *arg) {
    int port = *(int *) arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return NULL;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    int result = connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
    if (result == 0) {
        printf("Port %d is open\n", port);
        close(sock);
    } else {
        printf("Port %d is closed\n", port);
        close(sock);
    }
    return NULL;
}

int main() {
    printf("Enter the number of ports to scan: ");
    scanf("%d", &num_ports);

    for (int i = 0; i < num_ports; i++) {
        ports[i] = i;
    }

    pthread_t threads[MAX_THREADS];
    int rc;
    for (int i = 0; i < num_ports; i++) {
        rc = pthread_create(&threads[i], NULL, scan_port, &ports[i]);
        if (rc) {
            printf("Error creating thread: %s\n", strerror(rc));
            return 1;
        }
    }

    for (int i = 0; i < num_ports; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}