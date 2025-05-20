//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535

int ports[MAX_PORTS];
int num_ports = 0;
int num_threads = 0;

void *scan_port(void *arg) {
    int port = *(int *) arg;
    
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    int connect_result = connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    if (connect_result == 0) {
        printf("Port %d is open\n", port);
    } else {
        printf("Port %d is closed\n", port);
    }
    
    close(sock);
    return NULL;
}

void add_port(int port) {
    ports[num_ports++] = port;
}

int main() {
    int i;
    printf("Enter the number of ports to scan: ");
    scanf("%d", &num_ports);

    for (i = 1; i <= num_ports; i++) {
        add_port(i);
    }

    pthread_t threads[MAX_THREADS];

    num_threads = 0;

    while (num_threads < num_ports) {
        for (i = 0; i < MAX_THREADS; i++) {
            if (threads[i] == 0) {
                pthread_create(&threads[i], NULL, scan_port, (void *)&ports[num_threads]);
                num_threads++;
                break;
            }
        }
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}