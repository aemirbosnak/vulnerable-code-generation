//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535

int ports[MAX_PORTS];
int num_ports = 0;

void *scan_port(void *arg) {
    int port = *(int *) arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;
    if (sock == -1) {
        printf("Error creating socket\n");
        return NULL;
    }
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(port);
    if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1) {
        printf("Port %d is closed\n", port);
    } else {
        printf("Port %d is open\n", port);
    }
    close(sock);
    return NULL;
}

int main() {
    int i, j;
    FILE *fp;
    char line[100];
    int port;

    if ((fp = fopen("ports.txt", "r")) == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        sscanf(line, "%d", &port);
        ports[num_ports++] = port;
    }

    fclose(fp);

    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    for (i = 0; i < num_ports; i++) {
        if (thread_count == MAX_THREADS) {
            for (j = 0; j < MAX_THREADS; j++) {
                pthread_join(threads[j], NULL);
            }
            thread_count = 0;
        }
        pthread_create(&threads[thread_count], NULL, scan_port, (void *) &ports[i]);
        thread_count++;
    }

    for (i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}