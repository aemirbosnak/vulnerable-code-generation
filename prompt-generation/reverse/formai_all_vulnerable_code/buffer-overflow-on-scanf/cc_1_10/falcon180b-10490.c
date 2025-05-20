//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_PORTS 65535

int ports[MAX_PORTS];
int num_ports = 0;
int max_threads = MAX_THREADS;
pthread_t threads[MAX_THREADS];

void *scan_port(void *arg) {
    int port = *(int *) arg;
    struct sockaddr_in server;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return NULL;
    }
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
    printf("Enter number of ports to scan: ");
    scanf("%d", &num_ports);
    printf("Enter number of threads: ");
    scanf("%d", &max_threads);
    if (num_ports > MAX_PORTS || max_threads > MAX_THREADS) {
        printf("Invalid input\n");
        return 1;
    }
    int i;
    for (i = 1; i <= num_ports; i++) {
        ports[i-1] = i;
    }
    pthread_t thread_id;
    int rc;
    int count = 0;
    while (count < num_ports) {
        rc = pthread_create(&thread_id, NULL, scan_port, (void *) &ports[count]);
        if (rc) {
            printf("Error creating thread\n");
            return 1;
        }
        count++;
    }
    while (count > 0) {
        rc = pthread_join(threads[--count], NULL);
        if (rc) {
            printf("Error joining thread\n");
            return 1;
        }
    }
    return 0;
}