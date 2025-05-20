//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define THREADS_NUM 10

void *scan_port(void *arg) {
    int port = *(int *) arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket on port %d\n", port);
        return NULL;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Port %d is closed\n", port);
        close(sock);
        return NULL;
    }

    printf("Port %d is open\n", port);
    close(sock);
    return NULL;
}

int main() {
    int ports[MAX_PORTS];
    int num_ports = 0;

    printf("Enter the number of ports to scan: ");
    scanf("%d", &num_ports);

    printf("Enter the ports to scan (comma separated): ");
    char input[1000];
    scanf("%s", input);

    char *token = strtok(input, ",");
    while (token!= NULL) {
        ports[num_ports] = atoi(token);
        num_ports++;
        token = strtok(NULL, ",");
    }

    pthread_t threads[THREADS_NUM];
    int thread_args[THREADS_NUM];

    for (int i = 0; i < THREADS_NUM; i++) {
        int start_port = i * (num_ports / THREADS_NUM);
        int end_port = (i == THREADS_NUM - 1)? num_ports - 1 : (i + 1) * (num_ports / THREADS_NUM) - 1;
        thread_args[i] = start_port;

        for (int j = start_port; j <= end_port; j++) {
            ports[j] = -1;
        }
    }

    for (int i = 0; i < THREADS_NUM; i++) {
        pthread_create(&threads[i], NULL, scan_port, (void *) &thread_args[i]);
    }

    for (int i = 0; i < THREADS_NUM; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}