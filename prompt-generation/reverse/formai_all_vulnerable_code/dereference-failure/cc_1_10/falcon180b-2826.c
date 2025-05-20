//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int ports[MAX_PORTS];
int num_ports;

void *scan_thread(void *arg) {
    int sock = *(int *) arg;
    int i;

    for (i = 0; i < num_ports; i++) {
        if (connect(sock, (struct sockaddr *) &(ports[i]), sizeof(ports[i])) == 0) {
            printf("Port %d is open\n", ports[i]);
            close(sock);
            return NULL;
        }
    }

    printf("All ports are closed\n");
    close(sock);
    return NULL;
}

int main(int argc, char *argv[]) {
    int sock, i, opt, max_threads = MAX_THREADS;
    pthread_t threads[MAX_THREADS];
    char hostname[1024];

    if (argc!= 3) {
        printf("Usage: %s <hostname> <port_range>\n", argv[0]);
        exit(1);
    }

    strcpy(hostname, argv[1]);
    num_ports = atoi(argv[2]) - atoi(argv[2] + 2) + 1;

    if (num_ports > MAX_PORTS) {
        printf("Error: Too many ports\n");
        exit(1);
    }

    for (i = atoi(argv[2]); i <= atoi(argv[2]) + num_ports - 1; i++) {
        ports[i - atoi(argv[2])] = i;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error: Unable to create socket\n");
        exit(1);
    }

    while (max_threads > 0) {
        pthread_create(&threads[max_threads - 1], NULL, scan_thread, (void *) sock);
        max_threads--;
    }

    for (i = 0; i < max_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    close(sock);

    return 0;
}