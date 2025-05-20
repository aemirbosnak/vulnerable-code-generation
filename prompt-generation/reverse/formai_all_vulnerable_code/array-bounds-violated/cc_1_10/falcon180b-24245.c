//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_THREADS 10
#define BUFFER_SIZE 1024

int sock;
struct sockaddr_in server_addr;

void *thread_func(void *arg) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while (1) {
        bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        buffer[bytes_received] = '\0';
        printf("%s\n", buffer);
    }

    return NULL;
}

int main() {
    int i, thread_id;
    pthread_t threads[MAX_THREADS];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12345);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, NULL);
    }

    while (1) {
        char buffer[BUFFER_SIZE];
        int bytes_sent;

        fgets(buffer, BUFFER_SIZE, stdin);
        bytes_sent = send(sock, buffer, strlen(buffer), 0);
        if (bytes_sent <= 0) {
            break;
        }
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    close(sock);
    return 0;
}