//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: asynchronous
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
#define BUFFER_SIZE 1024

int sock;
struct sockaddr_in server;

void *scan_thread(void *arg) {
    int port = *(int *) arg;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "GET / HTTP/1.1\r\nHost: localhost\r\n\r\n");

    if (connect(sock, (struct sockaddr *) &server, sizeof(server))!= -1) {
        send(sock, buffer, strlen(buffer), 0);
        bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received > 0) {
            printf("Port %d is open\n", port);
        } else {
            printf("Port %d is closed\n", port);
        }
    } else {
        printf("Port %d is closed\n", port);
    }

    close(sock);
    return NULL;
}

int main() {
    int i, max_fd, client_socket;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in client;
    socklen_t addr_size;
    pthread_t threads[MAX_THREADS];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket\n");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(80);

    if (bind(sock, (struct sockaddr *) &server, sizeof(server)) == -1) {
        printf("Could not bind to port\n");
        exit(1);
    }

    listen(sock, 3);

    puts("Enter the range of ports to scan:");
    scanf("%d %d", &i, &i);

    for (i = 1; i <= i; i++) {
        pthread_create(&threads[i], NULL, scan_thread, (void *) &i);
    }

    for (i = 1; i <= i; i++) {
        pthread_join(threads[i], NULL);
    }

    close(sock);
    return 0;
}