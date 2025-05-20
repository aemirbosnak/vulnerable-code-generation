//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535

struct hostent *host;
int sock;

void *port_scanner(void *arg) {
    int port = *(int *) arg;
    char *ip = inet_ntoa(*(struct in_addr *) host->h_addr);
    printf("Scanning port %d on %s...\n", port, ip);

    int s = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);
    sin.sin_addr.s_addr = *(unsigned long *) host->h_addr;

    int res = connect(s, (struct sockaddr *) &sin, sizeof(sin));

    if (res == 0) {
        printf("Port %d is open.\n", port);
    } else {
        printf("Port %d is closed.\n", port);
    }

    close(s);
    return NULL;
}

int main() {
    char target[100];
    printf("Enter target IP address: ");
    scanf("%s", target);

    host = gethostbyname(target);
    if (host == NULL) {
        printf("Invalid IP address.\n");
        return -1;
    }

    printf("Enter the number of threads: ");
    int num_threads;
    scanf("%d", &num_threads);

    pthread_t threads[MAX_THREADS];
    int ports[MAX_PORTS];

    int i = 0;
    for (int j = 1; j <= MAX_PORTS; j++) {
        if (j % 1000 == 0) {
            printf("Scanning ports %d - %d...\n", j - 999, j);
        }
        ports[i++] = j;
    }

    int rc;
    for (int j = 0; j < num_threads; j++) {
        rc = pthread_create(&threads[j], NULL, port_scanner, (void *) &ports[j * MAX_PORTS / num_threads]);
        if (rc) {
            printf("Error: unable to create thread, %d\n", rc);
            exit(-1);
        }
    }

    for (int j = 0; j < num_threads; j++) {
        pthread_join(threads[j], NULL);
    }

    return 0;
}