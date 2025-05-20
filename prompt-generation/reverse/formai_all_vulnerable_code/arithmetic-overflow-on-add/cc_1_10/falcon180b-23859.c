//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535

struct thread_data {
    int thread_id;
    int port;
};

void *scan_port(void *arg) {
    struct thread_data *data = (struct thread_data *) arg;
    int sockfd, retval, portno;
    struct sockaddr_in server_addr;
    char *message = "HELLO";

    portno = data->port;
    printf("Thread %d scanning port %d\n", data->thread_id, portno);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Socket creation failed for port %d\n", portno);
        return NULL;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(portno);

    retval = connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
    if (retval == -1) {
        printf("Connection failed for port %d\n", portno);
        close(sockfd);
        return NULL;
    }

    send(sockfd, message, strlen(message), 0);
    close(sockfd);

    printf("Port %d is open\n", portno);
    return NULL;
}

int main() {
    int num_threads, i;
    pthread_t threads[MAX_THREADS];
    struct thread_data data[MAX_THREADS];

    printf("Enter number of threads: ");
    scanf("%d", &num_threads);

    printf("Enter starting port: ");
    scanf("%d", &data[0].port);

    for (i = 1; i < num_threads; i++) {
        data[i].port = data[i-1].port + 1;
    }

    for (i = 0; i < num_threads; i++) {
        data[i].thread_id = i + 1;
        pthread_create(&threads[i], NULL, scan_port, &data[i]);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}