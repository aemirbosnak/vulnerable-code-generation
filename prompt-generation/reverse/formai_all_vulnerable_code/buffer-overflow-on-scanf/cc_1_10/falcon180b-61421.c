//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535

int ports[MAX_PORTS];
int num_ports = 0;

void *thread_func(void *arg) {
    int port = *(int *) arg;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (connect(sock, (struct sockaddr *) &addr, sizeof(addr)) == 0) {
        printf("Port %d is open\n", port);
        close(sock);
    } else if (errno == ECONNREFUSED) {
        printf("Port %d is closed\n", port);
    } else {
        printf("Error on port %d: %s\n", port, strerror(errno));
    }

    pthread_exit(0);
}

int main() {
    printf("Enter the number of ports to scan (1-%d): ", MAX_PORTS);
    scanf("%d", &num_ports);

    printf("Enter the ports to scan (comma-separated): ");
    char *ports_str = malloc(1000);
    scanf("%s", ports_str);

    char *token = strtok(ports_str, ",");
    int i = 0;
    while (token!= NULL) {
        ports[i] = atoi(token);
        i++;
        token = strtok(NULL, ",");
    }

    pthread_t threads[MAX_THREADS];
    int rc;
    for (i = 0; i < num_ports; i++) {
        rc = pthread_create(&threads[i], NULL, thread_func, &ports[i]);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    for (i = 0; i < num_ports; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}