//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int ports[MAX_PORTS];
int num_ports = 0;

void *scan_port(void *arg) {
    int port = *(int *) arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Failed to create socket: %s\n", strerror(errno));
        return NULL;
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) == -1) {
        printf("Port %d is closed\n", port);
    } else {
        printf("Port %d is open\n", port);
    }

    close(sock);
    return NULL;
}

int main() {
    printf("Enter the IP address: ");
    char ip[16];
    scanf("%s", ip);

    printf("Enter the range of ports (e.g. 1-65535): ");
    char range[16];
    scanf("%s", range);

    int start_port, end_port;
    sscanf(range, "%d-%d", &start_port, &end_port);

    if (start_port > end_port) {
        printf("Invalid port range\n");
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
            printf("Failed to create thread: %s\n", strerror(rc));
            return 1;
        }
    }

    for (int i = 0; i < num_ports; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}