//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: genious
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
#define SCAN_PORT 80

typedef struct {
    char ip[16];
    int port;
} target;

void *scan(void *arg) {
    target *t = (target *) arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct hostent *host = gethostbyname(t->ip);
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(t->port);
    memcpy(&server.sin_addr, host->h_addr, host->h_length);
    if(connect(sock, (struct sockaddr *) &server, sizeof(server)) == 0) {
        close(sock);
        printf("%s:%d is open\n", t->ip, t->port);
    } else {
        close(sock);
        printf("%s:%d is closed\n", t->ip, t->port);
    }
    return NULL;
}

int main() {
    int threads_count = 0;
    pthread_t threads[MAX_THREADS];
    char input[BUFFER_SIZE];
    while(fgets(input, BUFFER_SIZE, stdin)) {
        if(strncmp(input, "scan", 4) == 0) {
            char ip[16];
            int port;
            sscanf(input, "scan %s %d", ip, &port);
            target t;
            strcpy(t.ip, ip);
            t.port = port;
            pthread_create(&threads[threads_count], NULL, scan, (void *) &t);
            threads_count++;
        }
    }
    for(int i = 0; i < threads_count; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}