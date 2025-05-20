//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int ports[MAX_PORTS];
int num_ports = 0;

void *scan_port(void *arg) {
    int port = *(int *) arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    int result = connect(sock, (struct sockaddr *) &server, sizeof(server));
    if (result == 0) {
        char buffer[BUFFER_SIZE];
        sprintf(buffer, "Port %d is open\n", port);
        write(1, buffer, strlen(buffer));
    } else {
        char buffer[BUFFER_SIZE];
        sprintf(buffer, "Port %d is closed\n", port);
        write(2, buffer, strlen(buffer));
    }
    close(sock);
    return NULL;
}

int main() {
    printf("Enter the number of ports to scan: ");
    scanf("%d", &num_ports);
    printf("Enter the ports to scan (comma-separated): ");
    char input[1000];
    scanf("%s", input);
    char *token = strtok(input, ",");
    while (token!= NULL) {
        ports[num_ports] = atoi(token);
        num_ports++;
        token = strtok(NULL, ",");
    }
    pthread_t threads[MAX_THREADS];
    int i = 0;
    while (i < num_ports) {
        pthread_create(&threads[i], NULL, scan_port, (void *) &ports[i]);
        i++;
    }
    for (i = 0; i < num_ports; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}