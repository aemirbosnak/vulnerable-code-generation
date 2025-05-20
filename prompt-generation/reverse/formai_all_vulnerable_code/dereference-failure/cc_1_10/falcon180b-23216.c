//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_THREADS 10
#define BUFFER_SIZE 1024

struct hostent *host;
int port;
int sock;
char buffer[BUFFER_SIZE];

void *thread_func(void *arg) {
    int thread_id = (int) arg;
    char hostname[20];
    sprintf(hostname, "host%d", thread_id);
    host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Host %s not found\n", hostname);
        return NULL;
    }
    port = 80;
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Socket creation failed\n");
        return NULL;
    }
    if (connect(sock, (struct sockaddr *) host->h_addr, host->h_length) == -1) {
        printf("Connection failed\n");
        close(sock);
        return NULL;
    }
    send(sock, "GET / HTTP/1.0\r\n\r\n", strlen("GET / HTTP/1.0\r\n\r\n"), 0);
    while (recv(sock, buffer, BUFFER_SIZE, 0) > 0) {
        printf("Thread %d: %s", thread_id, buffer);
    }
    close(sock);
    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    int i;
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *) i);
    }
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}