//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <pthread.h>

#define MAX_THREADS 100
#define THREAD_STACK_SIZE 1024
#define MAX_PORTS 65535

int ports[MAX_PORTS];
int num_ports = 0;

void *port_scanner(void *arg) {
    int port = *(int *) arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);
    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) == 0) {
        close(sock);
        ports[num_ports++] = port;
    }
    return NULL;
}

int main() {
    int i, j;
    pthread_t threads[MAX_THREADS];

    printf("Enter number of threads: ");
    scanf("%d", &i);

    if (i > MAX_THREADS) {
        printf("Error: Too many threads\n");
        exit(1);
    }

    srand(time(NULL));
    for (j = 0; j < MAX_PORTS; j++) {
        if (rand() % 2) {
            ports[num_ports++] = j;
        }
    }

    printf("Enter IP address: ");
    char ip[16];
    scanf("%s", ip);

    for (j = 0; j < i; j++) {
        pthread_create(&threads[j], NULL, port_scanner, (void *) &ports[j * MAX_PORTS / i]);
    }

    for (j = 0; j < i; j++) {
        pthread_join(threads[j], NULL);
    }

    printf("Open ports:\n");
    for (j = 0; j < num_ports; j++) {
        printf("%d\n", ports[j]);
    }

    return 0;
}