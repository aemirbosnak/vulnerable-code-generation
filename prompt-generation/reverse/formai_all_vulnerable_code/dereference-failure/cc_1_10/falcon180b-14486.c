//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_PORT_NUM 65535
#define MAX_THREADS 100
#define BUF_SIZE 1024

typedef struct {
    int sockfd;
    struct sockaddr_in server_addr;
} thread_data;

void *port_scanner(void *arg) {
    thread_data *data = (thread_data *) arg;
    int result;
    char send_buf[BUF_SIZE];
    char recv_buf[BUF_SIZE];
    int port = 1;

    while (port <= MAX_PORT_NUM) {
        data->server_addr.sin_port = htons(port);
        result = connect(data->sockfd, (struct sockaddr *) &data->server_addr, sizeof(data->server_addr));

        if (result == 0) {
            sprintf(send_buf, "Port %d is open.\n", port);
            send(data->sockfd, send_buf, strlen(send_buf), 0);
        } else {
            sprintf(send_buf, "Port %d is closed.\n", port);
            send(data->sockfd, send_buf, strlen(send_buf), 0);
        }

        port++;
    }

    close(data->sockfd);
    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    int sockfd, result, opt = 1;
    struct sockaddr_in server_addr;
    char *server_ip;
    int server_port;
    int num_threads;
    pthread_t threads[MAX_THREADS];

    if (argc!= 4) {
        printf("Usage: %s <server_ip> <server_port> <num_threads>\n", argv[0]);
        return 1;
    }

    server_ip = argv[1];
    server_port = atoi(argv[2]);
    num_threads = atoi(argv[3]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket.\n");
        return 1;
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr));

    for (int i = 0; i < num_threads; i++) {
        thread_data *data = (thread_data *) malloc(sizeof(thread_data));
        data->sockfd = sockfd;
        data->server_addr = server_addr;

        pthread_create(&threads[i], NULL, port_scanner, (void *) data);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    close(sockfd);

    return 0;
}