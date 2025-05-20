//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_THREADS 100
#define BUFFER_SIZE 1024

int port;
char *ip;
char *output_file;
int num_threads;

void *scan_port(void *arg) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &server.sin_addr);
    server.sin_port = htons(port);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        fprintf(stderr, "Connection failed on port %d\n", port);
        close(sock);
        return NULL;
    }

    char buffer[BUFFER_SIZE];
    sprintf(buffer, "Port %d is open.\n", port);
    write(sock, buffer, strlen(buffer));
    close(sock);

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc!= 5) {
        fprintf(stderr, "Usage: %s <ip> <port> <output_file> <num_threads>\n", argv[0]);
        return 1;
    }

    ip = argv[1];
    port = atoi(argv[2]);
    output_file = argv[3];
    num_threads = atoi(argv[4]);

    FILE *fp = fopen(output_file, "w");
    if (fp == NULL) {
        fprintf(stderr, "Error opening output file.\n");
        return 1;
    }

    pthread_t threads[MAX_THREADS];
    int thread_ids[MAX_THREADS];

    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, scan_port, NULL);
        thread_ids[i] = i + 1;
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    fclose(fp);
    return 0;
}