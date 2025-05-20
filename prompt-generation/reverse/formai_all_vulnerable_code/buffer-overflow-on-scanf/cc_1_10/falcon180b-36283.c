//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define MAX_THREADS 100

int port_list[MAX_THREADS];
int port_count = 0;

void *scan_port(void *arg) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons((unsigned short) *((int *) arg));
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) == -1) {
        close(sock);
        printf("Port %d is closed\n", *((int *) arg));
        return NULL;
    } else {
        close(sock);
        printf("Port %d is open\n", *((int *) arg));
        return NULL;
    }
}

int main() {
    printf("Enter the number of ports to scan: ");
    scanf("%d", &port_count);

    for (int i = 0; i < port_count; i++) {
        printf("Enter port %d: ", i + 1);
        scanf("%d", &port_list[i]);
    }

    pthread_t threads[MAX_THREADS];
    int rc;

    for (int i = 0; i < port_count; i++) {
        rc = pthread_create(&threads[i], NULL, scan_port, &port_list[i]);
        if (rc) {
            printf("Error creating thread\n");
            exit(1);
        }
    }

    for (int i = 0; i < port_count; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}