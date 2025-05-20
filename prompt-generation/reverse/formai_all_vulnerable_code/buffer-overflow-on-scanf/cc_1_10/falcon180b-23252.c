//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535

int ports[MAX_PORTS];
int num_ports = 0;

void *scan_port(void *arg) {
    int port = *(int *) arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr;

    if (sock == -1) {
        return NULL;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr *) &addr, sizeof(addr)) == 0) {
        close(sock);
        return (void *) 1;
    } else {
        close(sock);
        return NULL;
    }
}

int main() {
    printf("Enter the number of ports to scan: ");
    scanf("%d", &num_ports);

    for (int i = 0; i < num_ports; i++) {
        ports[i] = i;
    }

    pthread_t threads[MAX_THREADS];
    int rc;
    void *status;

    for (int i = 0; i < num_ports; i++) {
        rc = pthread_create(&threads[i], NULL, scan_port, &ports[i]);
        if (rc) {
            printf("Error: unable to create thread, %d\n", rc);
            exit(-1);
        }
    }

    for (int i = 0; i < num_ports; i++) {
        rc = pthread_join(threads[i], &status);
        if (rc) {
            printf("Error: unable to join, %d\n", rc);
            exit(-1);
        }

        if (status!= NULL) {
            printf("Port %d is open.\n", ports[i]);
        } else {
            printf("Port %d is closed.\n", ports[i]);
        }
    }

    return 0;
}