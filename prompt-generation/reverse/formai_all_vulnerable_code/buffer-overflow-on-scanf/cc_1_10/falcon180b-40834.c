//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535

int ports[MAX_PORTS];
int num_ports = 0;
pthread_t threads[MAX_THREADS];

void *scan_port(void *arg) {
    int port = *(int *) arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    if(connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
        close(sock);
        printf("Port %d is open\n", port);
    } else {
        close(sock);
    }
    return NULL;
}

int main() {
    int i, j, opt;
    char input[100];

    printf("Enter ports to scan (comma-separated): ");
    scanf("%s", input);

    char *token = strtok(input, ",");
    while(token!= NULL) {
        ports[num_ports] = atoi(token);
        num_ports++;
        token = strtok(NULL, ",");
    }

    for(i = 0; i < num_ports; i++) {
        pthread_create(&threads[i], NULL, scan_port, &ports[i]);
    }

    for(i = 0; i < num_ports; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}