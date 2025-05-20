//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: Donald Knuth
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

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (connect(sock, (struct sockaddr *) &addr, sizeof(addr)) == 0) {
        printf("Port %d is open\n", port);
        close(sock);
        return NULL;
    } else if (errno == ECONNREFUSED) {
        printf("Port %d is closed\n", port);
    } else {
        printf("Error connecting to port %d: %s\n", port, strerror(errno));
    }

    close(sock);
    return NULL;
}

int main() {
    printf("Enter the number of ports to scan: ");
    scanf("%d", &num_ports);

    printf("Enter the ports to scan (comma-separated): ");
    char input[1000];
    scanf("%s", input);

    char *token = strtok(input, ",");
    int i = 0;

    while (token!= NULL) {
        ports[i++] = atoi(token);
        token = strtok(NULL, ",");
    }

    pthread_t threads[MAX_THREADS];
    int ids[MAX_THREADS];

    for (i = 0; i < num_ports; i++) {
        int ret = pthread_create(&threads[i], NULL, scan_port, &ports[i]);

        if (ret!= 0) {
            printf("Error creating thread: %s\n", strerror(ret));
            exit(1);
        }

        ids[i] = ret;
    }

    for (i = 0; i < num_ports; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}