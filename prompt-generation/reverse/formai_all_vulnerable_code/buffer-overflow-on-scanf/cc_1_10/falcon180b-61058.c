//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX 65535
#define BUF_SIZE 1024

int target_port = 80;
char target_ip[20];
int num_of_threads = 5;
pthread_t thread_id[5];
int thread_socket[5];

void *thread_func(void *arg) {
    int thread_num = *(int *) arg;
    int port = target_port + thread_num * (MAX / num_of_threads);

    thread_socket[thread_num] = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    inet_pton(AF_INET, target_ip, &server_addr.sin_addr);

    int result = connect(thread_socket[thread_num], (struct sockaddr *) &server_addr, sizeof(server_addr));

    if (result == 0) {
        printf("Port %d is open\n", port);
        close(thread_socket[thread_num]);
    } else {
        printf("Port %d is closed\n", port);
        close(thread_socket[thread_num]);
    }

    return NULL;
}

int main() {
    printf("Enter the target IP address: ");
    scanf("%s", target_ip);

    printf("Enter the target port number: ");
    scanf("%d", &target_port);

    printf("Enter the number of threads: ");
    scanf("%d", &num_of_threads);

    for (int i = 0; i < num_of_threads; i++) {
        pthread_create(&thread_id[i], NULL, thread_func, (void *) &i);
    }

    for (int i = 0; i < num_of_threads; i++) {
        pthread_join(thread_id[i], NULL);
    }

    return 0;
}