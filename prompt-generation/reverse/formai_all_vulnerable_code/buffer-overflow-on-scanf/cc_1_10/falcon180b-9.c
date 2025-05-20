//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

#define MAX_THREADS 10
#define BUFFER_SIZE 1024

int target_port;
char target_ip[20];
int num_of_threads;
pthread_t threads[MAX_THREADS];

void *port_scanner(void *arg) {
    int port = *(int *) arg;
    int sockfd, ret;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, target_ip, &server_addr.sin_addr);

    ret = connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
    if (ret!= -1) {
        printf("Port %d is open\n", port);
    } else if (errno == ECONNREFUSED) {
        printf("Port %d is closed\n", port);
    } else {
        printf("Error connecting to port %d\n", port);
    }

    close(sockfd);
    return NULL;
}

int main() {
    int sockfd, ret, i;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    printf("Enter the target IP address: ");
    scanf("%s", target_ip);

    printf("Enter the target port range (start port - end port): ");
    scanf("%d %d", &target_port, &num_of_threads);

    for (i = 0; i < num_of_threads; i++) {
        ret = pthread_create(&threads[i], NULL, port_scanner, (void *) &target_port);
        if (ret!= 0) {
            printf("Error creating thread\n");
            exit(1);
        }
    }

    for (i = 0; i < num_of_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}