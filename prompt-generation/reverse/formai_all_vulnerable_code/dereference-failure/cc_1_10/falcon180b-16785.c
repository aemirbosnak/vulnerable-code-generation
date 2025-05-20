//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_THREADS 10
#define DATA_SIZE 1024
#define SERVER_PORT 8080

struct hostent *server;
int sock;

void *send_data(void *param);
void *recv_data(void *param);

int main(int argc, char *argv[]) {
    int i, thread_id[MAX_THREADS], num_threads, max_threads = 0;
    pthread_t threads[MAX_THREADS];
    char *ip_address = "127.0.0.1";
    double total_time = 0;

    if (argc > 1) {
        ip_address = argv[1];
    }

    if ((server = gethostbyname(ip_address)) == NULL) {
        fprintf(stderr, "Invalid server address\n");
        exit(1);
    }

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        fprintf(stderr, "Error creating socket\n");
        exit(1);
    }

    if (connect(sock, (struct sockaddr *)server, sizeof(struct sockaddr)) == -1) {
        fprintf(stderr, "Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server at %s\n", inet_ntoa(*((struct in_addr *)server->h_addr)));

    while (max_threads < MAX_THREADS) {
        if (pthread_create(&threads[max_threads], NULL, send_data, NULL)!= 0) {
            fprintf(stderr, "Error creating thread\n");
            exit(1);
        }
        max_threads++;
    }

    for (i = 0; i < max_threads; i++) {
        if (pthread_join(threads[i], NULL)!= 0) {
            fprintf(stderr, "Error joining thread\n");
            exit(1);
        }
    }

    close(sock);
    return 0;
}

void *send_data(void *param) {
    char buffer[DATA_SIZE];
    int bytes_sent;

    while (1) {
        memset(buffer, 'A', DATA_SIZE);
        bytes_sent = send(sock, buffer, DATA_SIZE, 0);

        if (bytes_sent <= 0) {
            break;
        }
    }

    return NULL;
}

void *recv_data(void *param) {
    char buffer[DATA_SIZE];
    int bytes_received;

    while (1) {
        bytes_received = recv(sock, buffer, DATA_SIZE, 0);

        if (bytes_received <= 0) {
            break;
        }
    }

    return NULL;
}