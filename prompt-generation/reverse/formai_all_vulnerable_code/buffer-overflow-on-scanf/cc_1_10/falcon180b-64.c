//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_THREADS 10
#define MAX_PORTS 100

int ports[MAX_PORTS];
int num_ports;
pthread_t threads[MAX_THREADS];
pthread_mutex_t mutex;

void *scan_port(void *arg) {
    int port = *(int *) arg;

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error creating socket for port %d\n", port);
        return NULL;
    }

    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) < 0) {
        printf("Port %d is closed\n", port);
        close(sock);
        return NULL;
    }

    close(sock);
    printf("Port %d is open\n", port);
    return NULL;
}

int main() {
    int input_port;
    printf("Enter the number of ports to scan: ");
    scanf("%d", &num_ports);

    printf("Enter the ports to scan (comma-separated): ");
    char input[100];
    scanf("%s", input);
    char *token = strtok(input, ",");
    for (int i = 0; i < num_ports && input_port!= -1; i++) {
        input_port = atoi(token);
        if (input_port <= 0 || input_port > 65535) {
            printf("Invalid port number: %d\n", input_port);
            return 1;
        }
        ports[i] = input_port;
        token = strtok(NULL, ",");
    }

    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < num_ports; i++) {
        pthread_create(&threads[i], NULL, scan_port, &ports[i]);
    }

    for (int i = 0; i < num_ports; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}