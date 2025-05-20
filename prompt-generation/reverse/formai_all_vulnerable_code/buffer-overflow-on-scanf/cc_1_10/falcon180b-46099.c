//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>
#include <pthread.h>

#define MAX_THREADS 100
#define PORT "12345"
#define SERVER_ADDR "127.0.0.1"
#define BUFFER_SIZE 1024

int sockfd;
struct sockaddr_in server_addr;
char buffer[BUFFER_SIZE];
int buffer_len;

void *thread_func(void *arg) {
    int thread_num = *((int *) arg);
    char *ip_address = inet_ntoa(server_addr.sin_addr);
    printf("Thread %d: Connected to %s\n", thread_num, ip_address);
    close(sockfd);
    return NULL;
}

int main() {
    int num_threads;
    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    if (num_threads > MAX_THREADS) {
        printf("Maximum number of threads exceeded\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(PORT));
    server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDR);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    printf("Connected to server\n");
    pthread_t threads[num_threads];
    int thread_args[num_threads];

    for (int i = 0; i < num_threads; i++) {
        thread_args[i] = i;
        pthread_create(&threads[i], NULL, thread_func, (void *) &thread_args[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    close(sockfd);
    return 0;
}