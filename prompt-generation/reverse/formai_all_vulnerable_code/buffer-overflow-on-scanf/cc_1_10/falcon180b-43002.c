//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_THREADS 100
#define PORT_RANGE_MIN 1
#define PORT_RANGE_MAX 65535

int ports[PORT_RANGE_MAX];
int num_open_ports = 0;

void *thread_func(void *arg) {
    int port = *(int *) arg;
    int sockfd;
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd == -1) {
        printf("Error: Unable to create socket\n");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    if(bind(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) == -1) {
        close(sockfd);
        printf("Port %d is closed\n", port);
        return NULL;
    }

    close(sockfd);
    printf("Port %d is open\n", port);
    return NULL;
}

int main() {
    int i, j, max_threads;
    pthread_t threads[MAX_THREADS];

    printf("Enter the number of threads to use (1-%d): ", MAX_THREADS);
    scanf("%d", &max_threads);

    for(i = PORT_RANGE_MIN; i <= PORT_RANGE_MAX; i++) {
        ports[i] = 1;
    }

    for(i = 0; i < max_threads; i++) {
        for(j = PORT_RANGE_MIN; j <= PORT_RANGE_MAX; j++) {
            if(ports[j] == 1) {
                ports[j] = 0;
                pthread_create(&threads[i], NULL, thread_func, (void *) &j);
                break;
            }
        }
    }

    for(i = 0; i < max_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\nOpen Ports:\n");
    for(i = PORT_RANGE_MIN; i <= PORT_RANGE_MAX; i++) {
        if(ports[i] == 1) {
            printf("%d\n", i);
        }
    }

    return 0;
}