//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 65535
#define MAX_THREADS 100

int ports[MAX_PORTS];
int num_ports;

void *thread_func(void *arg) {
    int port = *(int *) arg;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return NULL;
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

    int result = connect(sock, (struct sockaddr *) &server, sizeof(server));
    if (result == -1) {
        if (errno == ECONNREFUSED) {
            printf("Port %d is closed\n", port);
        } else {
            printf("Error connecting to port %d: %s\n", port, strerror(errno));
        }
        close(sock);
        return NULL;
    }

    close(sock);
    printf("Port %d is open\n", port);
    return NULL;
}

int main() {
    printf("Enter number of ports to scan: ");
    scanf("%d", &num_ports);

    printf("Enter ports to scan (comma-separated): ");
    char input[1024];
    fgets(input, sizeof(input), stdin);
    char *token = strtok(input, ",");
    int i = 0;
    while (token!= NULL) {
        ports[i] = atoi(token);
        i++;
        token = strtok(NULL, ",");
    }

    pthread_t threads[MAX_THREADS];
    int rc;
    for (i = 0; i < num_ports; i++) {
        rc = pthread_create(&threads[i], NULL, thread_func, (void *) &ports[i]);
        if (rc) {
            printf("Error creating thread: %s\n", strerror(rc));
            return 1;
        }
    }

    for (i = 0; i < num_ports; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}