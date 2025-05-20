//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_THREADS 100
#define BUFFER_SIZE 1024

struct hostent *gethostbyname(const char *name);
void *thread_connect(void *arg);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <IP Address> <Port Range>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    char *port_range = argv[2];
    int start_port = atoi(port_range);
    int end_port = start_port;

    printf("Scanning %s:%d - %d\n", ip, start_port, end_port);

    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    for (int i = start_port; i <= end_port; i++) {
        if (thread_count >= MAX_THREADS) {
            printf("Maximum thread count reached.\n");
            break;
        }

        pthread_t thread;
        if (pthread_create(&thread, NULL, thread_connect, (void *)i)!= 0) {
            printf("Error creating thread.\n");
            return 1;
        }

        threads[thread_count++] = thread;
    }

    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void *thread_connect(void *arg) {
    int port = (int)arg;

    struct hostent *host = gethostbyname("127.0.0.1");
    if (host == NULL) {
        printf("Error resolving host.\n");
        return NULL;
    }

    char ip[16];
    memcpy(ip, host->h_addr, host->h_length);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket.\n");
        return NULL;
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    memcpy(&server.sin_addr, ip, host->h_length);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Port %d is closed.\n", port);
    } else {
        printf("Port %d is open.\n", port);
    }

    close(sock);
    return NULL;
}