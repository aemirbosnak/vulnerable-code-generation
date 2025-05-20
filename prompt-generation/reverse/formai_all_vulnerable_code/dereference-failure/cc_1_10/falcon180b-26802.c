//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535

int ports[MAX_PORTS];
int num_ports = 0;

void *thread_func(void *arg) {
    int port = *(int *) arg;
    int sock;
    struct sockaddr_in server;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return NULL;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) == -1) {
        printf("Port %d is closed\n", port);
        close(sock);
        return NULL;
    } else {
        printf("Port %d is open\n", port);
        close(sock);
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    int i, j;
    pthread_t threads[MAX_THREADS];
    char *ip_address = "127.0.0.1";

    if (argc < 3) {
        printf("Usage: %s <start_port> <end_port>\n", argv[0]);
        return 1;
    }

    srand(time(NULL));
    for (i = atoi(argv[1]); i <= atoi(argv[2]); i++) {
        if (num_ports >= MAX_PORTS) {
            printf("Maximum number of ports reached\n");
            return 1;
        }
        ports[num_ports++] = i;
    }

    for (i = 0; i < num_ports; i++) {
        for (j = 0; j < MAX_THREADS; j++) {
            if (pthread_create(&threads[j], NULL, thread_func, (void *) &ports[i])!= 0) {
                printf("Error creating thread: %s\n", strerror(errno));
                exit(1);
            }
        }
        for (j = 0; j < MAX_THREADS; j++) {
            pthread_join(threads[j], NULL);
        }
    }

    return 0;
}