//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int ports[MAX_PORTS];
int num_ports = 0;

void *thread_func(void *arg) {
    int thread_num = *(int *) arg;
    int port = ports[thread_num];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket on port %d\n", port);
        return NULL;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Port %d is closed\n", port);
        close(sock);
        return NULL;
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
    char input[BUFFER_SIZE];
    scanf("%s", input);

    char *token = strtok(input, ",");
    int i = 0;
    while (token!= NULL) {
        int port = atoi(token);
        if (port >= 0 && port <= 65535) {
            ports[i++] = port;
        } else {
            printf("Invalid port number: %d\n", port);
        }
        token = strtok(NULL, ",");
    }
    num_ports = i;

    pthread_t threads[MAX_THREADS];
    int thread_num = 0;

    for (int i = 0; i < num_ports; i++) {
        pthread_create(&threads[thread_num], NULL, thread_func, &i);
        thread_num++;
        if (thread_num == MAX_THREADS) {
            for (int j = 0; j < MAX_THREADS; j++) {
                pthread_join(threads[j], NULL);
            }
            thread_num = 0;
        }
    }

    return 0;
}