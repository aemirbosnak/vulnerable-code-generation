//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <pthread.h>

#define BUFFER_SIZE 1024
#define QOS_PORT "8080"
#define QOS_SERVER "127.0.0.1"
#define QOS_REQUEST "GET / HTTP/1.1\r\nHost: localhost\r\n\r\n"

int sockfd;
struct sockaddr_in serv_addr;
pthread_t thread_id;
int thread_count = 0;

void *thread_func(void *arg) {
    thread_count++;
    printf("Thread %d started\n", thread_count);
    char buffer[BUFFER_SIZE];
    int bytes_received = 0;
    while (bytes_received < BUFFER_SIZE) {
        bytes_received += recv(sockfd, buffer + bytes_received, BUFFER_SIZE - bytes_received, 0);
    }
    buffer[bytes_received] = '\0';
    printf("Response: %s\n", buffer);
    pthread_exit(0);
}

int main() {
    int opt = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(QOS_SERVER);
    serv_addr.sin_port = htons(atoi(QOS_PORT));

    connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    pthread_t threads[10];
    int i;
    for (i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, thread_func, NULL);
    }

    for (i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    close(sockfd);
    return 0;
}