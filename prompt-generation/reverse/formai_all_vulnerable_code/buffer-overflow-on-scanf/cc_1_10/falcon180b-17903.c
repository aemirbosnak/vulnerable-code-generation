//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_THREADS 100
#define BUF_SIZE 1024

struct hostent *gethostbyname(const char *name);

void *scan_port(void *arg) {
    int sockfd, portno, n;
    char buf[BUF_SIZE];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    portno = *(int *) arg;
    server = gethostbyname("127.0.0.1");

    if (server == NULL) {
        printf("Error: No such host is known\n");
        exit(1);
    }

    if (server->h_addrtype!= AF_INET) {
        printf("Error: Invalid address type\n");
        exit(2);
    }

    if (server->h_length!= 4) {
        printf("Error: Invalid address length\n");
        exit(3);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error: Socket creation failed\n");
        exit(4);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr.s_addr = *(unsigned long *) server->h_addr;

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Port %d is closed\n", portno);
    } else {
        printf("Port %d is open\n", portno);
    }

    close(sockfd);
    return NULL;
}

int main() {
    int num_threads, i;
    pthread_t threads[MAX_THREADS];
    int ports[] = { 80, 443, 22, 23, 25, 110, 143, 21, 53 };

    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    if (num_threads > MAX_THREADS) {
        printf("Error: Number of threads exceeds the limit\n");
        exit(5);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, scan_port, (void *) &ports[i]);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}