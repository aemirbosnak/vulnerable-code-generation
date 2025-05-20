//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535

int ports[MAX_PORTS];
int num_ports = 0;

void *scan_port(void *arg) {
    int port = *(int *) arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) == 0) {
        close(sock);
        printf("%d - Open\n", port);
    } else {
        close(sock);
        printf("%d - Closed\n", port);
    }

    return NULL;
}

int main() {
    int i, j;
    char host[100];
    struct hostent *he;

    printf("Enter host name: ");
    scanf("%s", host);

    he = gethostbyname(host);

    if (he == NULL) {
        printf("Host not found\n");
        exit(1);
    }

    for (i = 1; i <= MAX_PORTS; i++) {
        ports[num_ports] = i;
        num_ports++;
    }

    pthread_t threads[MAX_THREADS];

    for (j = 0; j < num_ports; j++) {
        pthread_create(&threads[j], NULL, scan_port, &ports[j]);
    }

    for (j = 0; j < num_ports; j++) {
        pthread_join(threads[j], NULL);
    }

    return 0;
}