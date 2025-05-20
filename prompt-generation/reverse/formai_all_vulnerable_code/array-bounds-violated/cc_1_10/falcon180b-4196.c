//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

#define BUF_SIZE 1024
#define THREAD_NUM 10

struct thread_data {
    int sock;
    struct sockaddr_in addr;
};

void *thread_func(void *arg) {
    struct thread_data *data = (struct thread_data *)arg;
    char buf[BUF_SIZE];
    int len;

    while ((len = recv(data->sock, buf, BUF_SIZE, 0)) > 0) {
        buf[len] = '\0';
        printf("Thread %d received %s\n", data->addr.sin_port, buf);
    }

    close(data->sock);
    free(data);
    return NULL;
}

int main() {
    int server_sock, client_sock, opt = 1;
    struct sockaddr_in server_addr, client_addr;
    pthread_t threads[THREAD_NUM];

    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket");
        exit(1);
    }

    if (setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12345);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(server_sock, 5) < 0) {
        perror("listen");
        exit(1);
    }

    printf("Server started on port 12345\n");

    while (1) {
        socklen_t addr_size = sizeof(client_addr);
        if ((client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &addr_size)) < 0) {
            perror("accept");
            exit(1);
        }

        if (pthread_create(&threads[0], NULL, thread_func, (void *)&(struct thread_data){.sock=client_sock,.addr=client_addr})!= 0) {
            perror("pthread_create");
            exit(1);
        }

        for (int i = 1; i < THREAD_NUM; i++) {
            if (pthread_create(&threads[i], NULL, thread_func, (void *)&(struct thread_data){.sock=client_sock,.addr=client_addr})!= 0) {
                perror("pthread_create");
                exit(1);
            }
        }
    }

    return 0;
}