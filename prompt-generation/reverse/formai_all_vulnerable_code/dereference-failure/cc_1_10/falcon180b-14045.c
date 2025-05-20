//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

#define PORT_MAX 65535
#define BUF_SIZE 1024
#define THREAD_NUM 64
#define THREAD_STACK_SIZE 1024*1024

typedef struct {
    int fd;
    int port;
} port_t;

typedef struct {
    pthread_t thread_id;
    port_t *port;
} thread_param_t;

void *scan_thread(void *param)
{
    thread_param_t *thread_param = (thread_param_t *)param;
    port_t *port = thread_param->port;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port->port);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if(connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
        printf("Port %d is open\n", port->port);
        close(sock);
    } else {
        printf("Port %d is closed\n", port->port);
        close(sock);
    }

    return NULL;
}

int main(int argc, char **argv)
{
    if(argc!= 3) {
        printf("Usage: %s <ip> <port_range>\n", argv[0]);
        exit(1);
    }

    char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = start_port + PORT_MAX;

    if(end_port > PORT_MAX) {
        printf("Invalid port range\n");
        exit(1);
    }

    int max_threads = THREAD_NUM;
    pthread_t threads[max_threads];
    port_t ports[max_threads];

    for(int i = start_port; i <= end_port; i++) {
        ports[i % max_threads].port = i;
        ports[i % max_threads].fd = -1;
    }

    for(int i = 0; i < max_threads; i++) {
        pthread_create(&threads[i], NULL, scan_thread, &ports[i]);
    }

    for(int i = 0; i < max_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}