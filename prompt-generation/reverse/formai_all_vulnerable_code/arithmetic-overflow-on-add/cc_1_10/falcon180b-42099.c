//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 100
#define BUFFER_SIZE 1024

struct target {
    char *ip;
    int port;
};

void *scan_port(void *arg) {
    struct target *target = (struct target *) arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(target->port);
    inet_pton(AF_INET, target->ip, &server.sin_addr);

    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) == 0) {
        close(sock);
        printf("Port %d on %s is open.\n", target->port, target->ip);
    } else {
        close(sock);
        printf("Port %d on %s is closed.\n", target->port, target->ip);
    }

    return NULL;
}

int main() {
    char input[BUFFER_SIZE];
    char *ip;
    int port;

    printf("Enter IP address: ");
    scanf("%s", input);
    ip = strdup(input);

    printf("Enter port range (start-end): ");
    scanf("%d-%d", &port, &port);

    pthread_t threads[MAX_THREADS];
    struct target targets[MAX_THREADS];

    int num_threads = 0;

    for (int i = port; i <= port; i++) {
        if (num_threads >= MAX_THREADS) {
            break;
        }

        sprintf(targets[num_threads].ip, "%s", ip);
        targets[num_threads].port = i;

        pthread_create(&threads[num_threads], NULL, scan_port, &targets[num_threads]);
        num_threads++;
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}