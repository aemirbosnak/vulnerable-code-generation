//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <pthread.h>

#define MAX_THREADS 10
#define BUFFER_SIZE 1024
#define TRUE 1
#define FALSE 0
#define MAX_HOSTS 100

int thread_count = 0;
pthread_t threads[MAX_THREADS];

struct host_info {
    char *hostname;
    int status;
};

struct host_info hosts[MAX_HOSTS];

void *ping_thread(void *arg) {
    struct host_info *host = arg;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return NULL;
    }

    struct sockaddr_in sa;
    memset(&sa, 0, sizeof(sa));
    sa.sin_family = AF_INET;
    sa.sin_port = htons(7);
    inet_pton(AF_INET, host->hostname, &sa.sin_addr);

    if (connect(sock, (struct sockaddr *)&sa, sizeof(sa)) == -1) {
        if (errno == ECONNRESET) {
            host->status = 1;
        } else {
            host->status = 0;
        }
        close(sock);
        return NULL;
    }

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    if (send(sock, "PING", strlen("PING"), 0) == -1) {
        perror("send");
        close(sock);
        return NULL;
    }

    int bytes_received = 0;
    while (bytes_received < BUFFER_SIZE) {
        if (recv(sock, buffer + bytes_received, BUFFER_SIZE - bytes_received, 0) == -1) {
            perror("recv");
            close(sock);
            return NULL;
        }
        bytes_received += strlen(buffer + bytes_received);
    }

    if (strncmp(buffer, "PONG", strlen("PONG")) == 0) {
        host->status = 1;
    } else {
        host->status = 0;
    }

    close(sock);
    return NULL;
}

int main() {
    FILE *file = fopen("hosts.txt", "r");
    if (file == NULL) {
        printf("Error opening hosts file\n");
        return 1;
    }

    char line[BUFFER_SIZE];
    while (fgets(line, BUFFER_SIZE, file)!= NULL) {
        struct host_info *host = &hosts[thread_count];
        strncpy(host->hostname, line, BUFFER_SIZE);
        host->hostname[strcspn(host->hostname, "\n")] = '\0';
        host->status = 0;
        thread_count++;

        pthread_create(&threads[thread_count - 1], NULL, ping_thread, host);
    }

    fclose(file);

    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}