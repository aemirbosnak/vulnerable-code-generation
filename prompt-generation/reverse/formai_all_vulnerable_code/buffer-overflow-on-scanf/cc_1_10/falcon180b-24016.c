//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535

int ports[MAX_PORTS];
int num_ports = 0;

void *scan_port(void *arg) {
    int port = *(int *) arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return NULL;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == 0) {
        printf("Port %d is open\n", port);
        close(sock);
    } else {
        printf("Port %d is closed\n", port);
        close(sock);
    }

    return NULL;
}

void add_port(int port) {
    if (num_ports >= MAX_PORTS) {
        printf("Maximum number of ports reached\n");
        return;
    }

    ports[num_ports] = port;
    num_ports++;
}

int main() {
    printf("Enter the number of threads: ");
    int num_threads;
    scanf("%d", &num_threads);

    pthread_t threads[MAX_THREADS];

    printf("Enter the ports to scan (comma separated): ");
    char ports_str[100];
    scanf("%s", ports_str);

    char *token = strtok(ports_str, ",");
    while (token!= NULL) {
        add_port(atoi(token));
        token = strtok(NULL, ",");
    }

    int i;
    for (i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, scan_port, (void *) &ports[i * MAX_PORTS / num_threads]);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}