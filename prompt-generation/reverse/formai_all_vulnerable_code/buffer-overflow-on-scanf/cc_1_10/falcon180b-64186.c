//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: random
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

#define MAX_THREADS 100
#define MAX_PORTS 65535

int ports[MAX_PORTS];
int num_ports = 0;

void* thread_scan(void* arg) {
    int port = *(int*)arg;
    int sock;
    struct sockaddr_in server;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1) {
        perror("socket");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if(connect(sock, (struct sockaddr*)&server, sizeof(struct sockaddr)) == -1) {
        if(errno == ECONNREFUSED) {
            printf("%d - Closed\n", port);
        } else {
            perror("connect");
        }
        close(sock);
        return NULL;
    }

    close(sock);
    printf("%d - Open\n", port);

    return NULL;
}

int main() {
    int i, j;

    printf("Enter number of threads: ");
    scanf("%d", &i);

    pthread_t threads[i];

    for(j = 0; j < MAX_PORTS; j++) {
        ports[num_ports++] = j;
    }

    for(j = 0; j < i; j++) {
        pthread_create(&threads[j], NULL, thread_scan, &ports[j*MAX_PORTS/i]);
    }

    for(j = 0; j < i; j++) {
        pthread_join(threads[j], NULL);
    }

    return 0;
}