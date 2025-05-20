//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int ports[MAX_PORTS];
int num_ports = 0;

void *scan_port(void *arg) {
    int port = *(int *) arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == 0) {
        close(sock);
        printf("Port %d is open.\n", port);
    } else {
        close(sock);
    }
    return NULL;
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <start_port> <end_port>\n", argv[0]);
        return 1;
    }

    int start_port = atoi(argv[1]);
    int end_port = atoi(argv[2]);

    if (start_port > end_port) {
        printf("Invalid port range.\n");
        return 1;
    }

    for (int i = start_port; i <= end_port; i++) {
        ports[num_ports++] = i;
    }

    pthread_t threads[MAX_THREADS];
    int rc;
    for (int i = 0; i < num_ports; i++) {
        rc = pthread_create(&threads[i], NULL, scan_port, &ports[i]);
        if (rc) {
            printf("Error: unable to create thread, %d\n", rc);
            exit(-1);
        }
    }

    for (int i = 0; i < num_ports; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}