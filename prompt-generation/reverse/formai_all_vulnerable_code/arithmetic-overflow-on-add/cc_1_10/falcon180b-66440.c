//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 1000
#define MAX_PORTS 65535

int threads_running = 0;
int max_threads = 0;
int ports[MAX_PORTS];
int num_ports = 0;

void *scan_port(void *arg) {
    int port = *(int *) arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
        close(sock);
        printf("Port %d is open\n", port);
    } else {
        close(sock);
    }

    pthread_exit(0);
}

void add_port(int port) {
    if (num_ports >= MAX_PORTS) {
        printf("Maximum number of ports reached\n");
        return;
    }

    ports[num_ports] = port;
    num_ports++;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <ip address> <ports>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    char *ports_str = argv[2];

    max_threads = atoi(argv[3])? atoi(argv[3]) : MAX_THREADS;

    int port_start, port_end;
    sscanf(ports_str, "%d-%d", &port_start, &port_end);

    for (int i = port_start; i <= port_end; i++) {
        add_port(i);
    }

    pthread_t threads[MAX_THREADS];

    for (int i = 0; i < num_ports; i++) {
        pthread_create(&threads[i], NULL, scan_port, (void *)&ports[i]);
    }

    for (int i = 0; i < num_ports; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}