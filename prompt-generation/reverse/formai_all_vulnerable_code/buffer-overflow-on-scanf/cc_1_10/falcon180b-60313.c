//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535

int target_ip;
int target_port;
int num_threads;

pthread_t threads[MAX_THREADS];

void *scan_ports(void *arg) {
    int thread_num = *(int *) arg;
    int start_port = (thread_num * MAX_PORTS) / num_threads;
    int end_port = ((thread_num + 1) * MAX_PORTS) / num_threads;

    for (int i = start_port; i <= end_port; i++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);

        if (sock == -1) {
            printf("Error creating socket: %s\n", strerror(errno));
            continue;
        }

        struct sockaddr_in server_addr;
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(i);
        inet_pton(AF_INET, "192.168.1.1", &server_addr.sin_addr);

        if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr))!= -1) {
            printf("Port %d is open\n", i);
        } else {
            printf("Port %d is closed\n", i);
        }

        close(sock);
    }

    return NULL;
}

int main() {
    printf("Enter target IP address: ");
    scanf("%d", &target_ip);

    printf("Enter target port (or 0 for all ports): ");
    scanf("%d", &target_port);

    printf("Enter number of threads: ");
    scanf("%d", &num_threads);

    if (num_threads > MAX_THREADS) {
        printf("Error: Number of threads must be less than or equal to %d\n", MAX_THREADS);
        return 1;
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, scan_ports, (void *)&i);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}