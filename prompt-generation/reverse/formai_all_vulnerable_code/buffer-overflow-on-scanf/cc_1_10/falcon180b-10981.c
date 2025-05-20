//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535

int ports[MAX_PORTS];
int num_ports;

void *scan_ports(void *param) {
    int sock, port;
    struct sockaddr_in server;
    char buffer[1024];

    int thread_id = (int)param;
    port = ports[thread_id];

    sock = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sock, (struct sockaddr *)&server, sizeof(server));

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
        printf("[*] Port %d is open\n", port);
        close(sock);
    } else {
        printf("[!] Port %d is closed\n", port);
        close(sock);
    }

    return NULL;
}

int main() {
    int i, opt;
    char ip[16];

    printf("Enter IP address: ");
    scanf("%s", ip);

    printf("Enter number of threads: ");
    scanf("%d", &num_ports);

    for (i = 1; i <= MAX_PORTS; i++) {
        ports[i - 1] = i;
    }

    pthread_t threads[MAX_THREADS];

    for (i = 0; i < num_ports; i++) {
        pthread_create(&threads[i], NULL, scan_ports, (void *)i);
    }

    for (i = 0; i < num_ports; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}