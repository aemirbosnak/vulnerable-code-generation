//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535

int ports[MAX_PORTS];
int num_ports = 0;

void *scan_port(void *arg) {
    int port = *(int *) arg;
    struct sockaddr_in addr;
    int sockfd, ret;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return NULL;
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    ret = connect(sockfd, (struct sockaddr *) &addr, sizeof(addr));
    if (ret == -1) {
        printf("Port %d is closed\n", port);
    } else {
        printf("Port %d is open\n", port);
        close(sockfd);
    }

    return NULL;
}

int main() {
    int i, ret;
    pthread_t threads[MAX_THREADS];

    printf("Enter number of ports to scan: ");
    scanf("%d", &num_ports);

    for (i = 0; i < num_ports; i++) {
        ports[i] = i;
    }

    for (i = 0; i < num_ports; i++) {
        ret = pthread_create(&threads[i], NULL, scan_port, &ports[i]);
        if (ret!= 0) {
            printf("Error creating thread\n");
            exit(1);
        }
    }

    for (i = 0; i < num_ports; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}