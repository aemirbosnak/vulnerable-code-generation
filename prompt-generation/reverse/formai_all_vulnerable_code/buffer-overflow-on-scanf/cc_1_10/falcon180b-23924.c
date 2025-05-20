//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535

int ports[MAX_PORTS];
int num_ports = 0;

void *scan_port(void *arg) {
    int port = *(int *) arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

    int result = connect(sock, (struct sockaddr *)&server, sizeof(server));

    if (result == 0) {
        close(sock);
        printf("Port %d is open\n", port);
    } else {
        close(sock);
    }

    pthread_exit(0);
}

int main() {
    printf("Enter the number of ports to scan: ");
    scanf("%d", &num_ports);

    printf("Enter the ports to scan (comma separated): ");
    char ports_str[100];
    scanf("%s", ports_str);

    char *token = strtok(ports_str, ",");
    while (token!= NULL) {
        ports[num_ports] = atoi(token);
        num_ports++;
        token = strtok(NULL, ",");
    }

    pthread_t threads[MAX_THREADS];
    int i = 0;

    for (i = 0; i < num_ports; i++) {
        pthread_create(&threads[i], NULL, scan_port, &ports[i]);
    }

    for (i = 0; i < num_ports; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}