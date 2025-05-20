//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535
#define THREAD_STACK_SIZE 1024 * 1024

typedef struct {
    int id;
    int port;
} thread_data_t;

void *scan_port(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: %s\n", strerror(errno));
        return NULL;
    }
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(data->port);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) == 0) {
        printf("Port %d is open\n", data->port);
    } else {
        printf("Port %d is closed\n", data->port);
    }
    close(sock);
    return NULL;
}

int main() {
    printf("Enter the IP address: ");
    char ip[16];
    scanf("%s", ip);
    printf("Enter the range of ports to scan (e.g. 1-65535): ");
    int start_port, end_port;
    scanf("%d-%d", &start_port, &end_port);
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;
    for (int i = start_port; i <= end_port; i++) {
        if (thread_count >= MAX_THREADS) {
            printf("Maximum number of threads reached\n");
            break;
        }
        thread_data_t data;
        data.id = thread_count;
        data.port = i;
        if (pthread_create(&threads[thread_count], NULL, scan_port, &data)!= 0) {
            printf("Error: %s\n", strerror(errno));
            return 1;
        }
        thread_count++;
    }
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}