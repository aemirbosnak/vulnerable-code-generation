//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_SOCKETS 100
#define BUF_SIZE 1024

typedef struct {
    int socket;
    char *ip_address;
    int port;
    int status;
} socket_data;

void *monitor_socket(void *socket_data_ptr);

int main() {
    int i, num_threads = 0;
    pthread_t threads[MAX_THREADS];
    socket_data sockets[MAX_SOCKETS];

    printf("Enter the number of sockets to monitor (max %d): ", MAX_SOCKETS);
    scanf("%d", &num_threads);

    for (i = 0; i < num_threads; i++) {
        printf("Enter the IP address and port for socket %d (e.g. 192.168.1.1:80): ", i+1);
        scanf("%s %d", sockets[i].ip_address, &sockets[i].port);
        sockets[i].socket = socket(AF_INET, SOCK_STREAM, 0);
        if (sockets[i].socket == -1) {
            printf("Error creating socket\n");
            exit(1);
        }
        sockets[i].status = 0;
    }

    for (i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, monitor_socket, &sockets[i]);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void *monitor_socket(void *socket_data_ptr) {
    socket_data *socket_data_ptr2 = socket_data_ptr;
    char buffer[BUF_SIZE];
    int bytes_received;

    while (1) {
        bytes_received = recv(socket_data_ptr2->socket, buffer, BUF_SIZE, 0);
        if (bytes_received <= 0) {
            socket_data_ptr2->status = 0;
            break;
        }
        socket_data_ptr2->status = 1;
    }

    close(socket_data_ptr2->socket);
}