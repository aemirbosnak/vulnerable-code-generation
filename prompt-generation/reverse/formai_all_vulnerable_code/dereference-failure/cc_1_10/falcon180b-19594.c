//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <pthread.h>

#define BUF_SIZE 1024
#define NUM_THREADS 5

int sockfd;
int portno;
struct sockaddr_in serv_addr;
struct sockaddr_in cli_addr;
int opt = 1;
int addrlen = sizeof(cli_addr);

void *thread_func(void *arg) {
    char *message = (char *) arg;
    send(sockfd, message, strlen(message), 0);
    close(sockfd);
    return NULL;
}

int main(int argc, char **argv) {

    if (argc!= 3) {
        printf("Usage:./client <IP Address> <Port Number>\n");
        exit(1);
    }

    portno = atoi(argv[2]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set socket options
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    setsockopt(sockfd, SOL_SOCKET, SO_KEEPALIVE, &opt, sizeof(opt));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(portno);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    pthread_t threads[NUM_THREADS];
    char message[BUF_SIZE];

    for (int i = 0; i < NUM_THREADS; i++) {
        int thread_id = i + 1;
        sprintf(message, "Thread %d started\n", thread_id);
        pthread_create(&threads[i], NULL, thread_func, (void *) message);
        sleep(1);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    close(sockfd);
    return 0;
}