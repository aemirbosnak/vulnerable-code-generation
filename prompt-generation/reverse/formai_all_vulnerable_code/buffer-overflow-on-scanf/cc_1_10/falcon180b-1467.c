//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_DATA 1024
#define MAX_PORT_NUM 65535
#define MAX_HOST_NAME 256
#define MAX_THREADS 10

struct hostent *host;
int port;
char hostname[MAX_HOST_NAME];
int socket_fd;
int opt = 1;
int thread_count = 0;
pthread_t thread_id[MAX_THREADS];

void *monitor_thread(void *arg) {
    int i;
    int sockfd;
    struct sockaddr_in serv_addr;
    char send_data[MAX_DATA];
    char recv_data[MAX_DATA];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(0);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to %s:%d\n", hostname, port);
        exit(0);
    }

    for (i = 0; i < 10; i++) {
        send(sockfd, "GET / HTTP/1.1\r\nHost: localhost\r\nConnection: close\r\n\r\n", strlen("GET / HTTP/1.1\r\nHost: localhost\r\nConnection: close\r\n\r\n"), 0);
        memset(recv_data, 0, sizeof(recv_data));
        recv(sockfd, recv_data, sizeof(recv_data), 0);
        printf("%d. Response: %s\n", i+1, recv_data);
        usleep(100000);
    }

    close(sockfd);
    pthread_exit(0);
}

int main() {
    int i;
    char input[MAX_DATA];
    int thread_status;

    printf("Enter hostname or IP address: ");
    scanf("%s", input);

    host = gethostbyname(input);

    if (host == NULL) {
        printf("Error resolving host\n");
        exit(0);
    }

    printf("Enter port number: ");
    scanf("%d", &port);

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_fd < 0) {
        printf("Error creating socket\n");
        exit(0);
    }

    setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt));

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&thread_id[i], NULL, monitor_thread, NULL);
        thread_count++;
    }

    for (i = 0; i < thread_count; i++) {
        pthread_join(thread_id[i], (void *)&thread_status);
    }

    close(socket_fd);
    exit(0);
}