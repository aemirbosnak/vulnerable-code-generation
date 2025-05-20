//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 64
#define MAX_PORTS 65535

pthread_t threads[MAX_THREADS];
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

    if (connect(sock, (struct sockaddr *) &addr, sizeof(addr)) == 0) {
        close(sock);
        printf("Port %d is open.\n", port);
    } else {
        close(sock);
    }

    return NULL;
}

int main() {
    printf("Enter the number of ports to scan: ");
    scanf("%d", &num_ports);

    printf("Enter the ports to scan (comma-separated): ");
    char input[1024];
    scanf("%s", input);
    char *token = strtok(input, ",");
    while (token!= NULL) {
        ports[num_ports] = atoi(token);
        num_ports++;
        token = strtok(NULL, ",");
    }

    int i;
    for (i = 0; i < num_ports; i++) {
        pthread_create(&threads[i], NULL, scan_port, &ports[i]);
    }

    for (i = 0; i < num_ports; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}