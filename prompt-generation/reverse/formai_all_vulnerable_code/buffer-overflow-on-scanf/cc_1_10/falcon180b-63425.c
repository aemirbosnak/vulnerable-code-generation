//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int ports[MAX_PORTS];
int num_ports = 0;

void *scan_port(void *arg) {
    int port = *(int *) arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    int err = connect(sock, (struct sockaddr *) &server, sizeof(server));
    if (err == 0) {
        printf("Port %d is open.\n", port);
        close(sock);
    } else {
        printf("Port %d is closed.\n", port);
    }
    pthread_exit(NULL);
}

int main() {
    printf("Enter the number of ports to scan: ");
    scanf("%d", &num_ports);
    printf("Enter the ports to scan (comma-separated): ");
    char input[BUFFER_SIZE];
    scanf("%s", input);
    char *token = strtok(input, ",");
    while (token!= NULL) {
        ports[num_ports] = atoi(token);
        num_ports++;
        token = strtok(NULL, ",");
    }
    pthread_t threads[MAX_THREADS];
    int i;
    for (i = 0; i < num_ports; i++) {
        pthread_create(&threads[i], NULL, scan_port, &ports[i]);
    }
    for (i = 0; i < num_ports; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}