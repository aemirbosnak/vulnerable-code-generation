//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int ports[MAX_PORTS];
int num_ports = 0;

void *scan_thread(void *arg) {
    int port = *(int *) arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) == 0) {
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
        ports[i] = i + 1;
    }

    pthread_t threads[MAX_THREADS];
    int rc;
    for (int i = 0; i < num_ports; i++) {
        rc = pthread_create(&threads[i], NULL, scan_thread, &ports[i]);
        if (rc) {
            printf("Failed to create thread: %d\n", rc);
            return 1;
        }
    }

    for (int i = 0; i < num_ports; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}