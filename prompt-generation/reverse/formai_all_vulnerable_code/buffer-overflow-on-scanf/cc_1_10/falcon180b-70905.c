//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/time.h>
#include <pthread.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535

int ports[MAX_PORTS];
int num_ports;

void *thread_func(void *arg) {
    int port = *(int *) arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) == -1) {
        if (errno == ECONNREFUSED) {
            printf("Port %d is closed\n", port);
        } else {
            printf("Error connecting to port %d\n", port);
        }
    } else {
        printf("Port %d is open\n", port);
        close(sock);
    }
    return NULL;
}

int main() {
    printf("Enter the number of ports to scan: ");
    scanf("%d", &num_ports);
    printf("Enter the ports to scan (comma-separated): ");
    char ports_str[100];
    scanf("%s", ports_str);
    char *token = strtok(ports_str, ",");
    int i = 0;
    while (token!= NULL) {
        ports[i] = atoi(token);
        i++;
        token = strtok(NULL, ",");
    }
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;
    for (i = 0; i < num_ports; i++) {
        if (thread_count >= MAX_THREADS) {
            printf("Maximum number of threads reached\n");
            break;
        }
        pthread_create(&threads[thread_count], NULL, thread_func, &ports[i]);
        thread_count++;
    }
    for (i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}