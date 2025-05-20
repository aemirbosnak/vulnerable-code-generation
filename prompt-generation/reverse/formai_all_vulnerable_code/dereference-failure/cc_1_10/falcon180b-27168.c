//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define TRUE 1
#define FALSE 0
#define MAX 10

struct thread_data {
    int sock;
    struct sockaddr_in serv_addr;
    int addrlen;
    char buffer[1024];
};

void *thread_func(void *arg) {
    struct thread_data *data = (struct thread_data *) arg;
    int n;

    while (TRUE) {
        memset(data->buffer, 0, sizeof(data->buffer));
        n = recv(data->sock, data->buffer, sizeof(data->buffer), 0);
        if (n <= 0) {
            break;
        }
        printf("Received message: %s\n", data->buffer);
    }

    close(data->sock);
    free(data);
    pthread_exit(NULL);
}

int main() {
    int opt = TRUE;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;
    int addrlen = sizeof(serv_addr);
    int val = 1;
    pthread_t thread_id[MAX];
    int i;

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(12345);

    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (char *) &opt, sizeof(opt));

    bind(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
    listen(sock, 5);

    for (i = 0; i < MAX; i++) {
        struct thread_data *data = (struct thread_data *) malloc(sizeof(struct thread_data));
        data->sock = accept(sock, (struct sockaddr *) &serv_addr, (socklen_t *) &addrlen);
        data->serv_addr = serv_addr;
        data->addrlen = addrlen;
        pthread_create(&thread_id[i], NULL, thread_func, (void *) data);
    }

    for (i = 0; i < MAX; i++) {
        pthread_join(thread_id[i], NULL);
    }

    close(sock);
    return 0;
}