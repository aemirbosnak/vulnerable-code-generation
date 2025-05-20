//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <errno.h>

typedef struct {
    int sock;
    struct sockaddr_in addr;
} thread_data;

void *thread_func(void *arg) {
    thread_data *data = arg;
    int result = connect(data->sock, (struct sockaddr *)&data->addr, sizeof(data->addr));
    if (result == -1) {
        if (errno == ECONNREFUSED) {
            printf("Port %d is closed\n", ntohs(data->addr.sin_port));
        } else {
            perror("connect");
        }
    } else {
        printf("Port %d is open\n", ntohs(data->addr.sin_port));
        close(data->sock);
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <ip address> <port range>\n", argv[0]);
        return 1;
    }
    char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[2]) + 100;
    int i;
    for (i = start_port; i <= end_port; i++) {
        pthread_t thread_id;
        thread_data data;
        data.sock = socket(AF_INET, SOCK_STREAM, 0);
        if (data.sock == -1) {
            perror("socket");
            return 1;
        }
        memset(&data.addr, 0, sizeof(data.addr));
        data.addr.sin_family = AF_INET;
        data.addr.sin_port = htons(i);
        inet_pton(AF_INET, ip, &data.addr.sin_addr);
        pthread_create(&thread_id, NULL, thread_func, &data);
        pthread_detach(thread_id);
    }
    return 0;
}