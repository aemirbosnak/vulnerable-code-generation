#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT_RANGE_START 1
#define PORT_RANGE_END 65535

void* scan_port(void* arg) {
    int port = *(int*)arg;
    struct sockaddr_in serv_addr;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Socket creation failed");
        return NULL;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        close(sock);
        return NULL;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        // Connection refused or other error
        close(sock);
        return NULL;
    } else {
        printf("Port %d is open\n", port);
        close(sock);
        return NULL;
    }
}

int main() {
    pthread_t threads[PORT_RANGE_END - PORT_RANGE_START + 1];
    int ports[PORT_RANGE_END - PORT_RANGE_START + 1];

    for (int i = 0; i < PORT_RANGE_END - PORT_RANGE_START + 1; i++) {
        ports[i] = PORT_RANGE_START + i;
        if (pthread_create(&threads[i], NULL, scan_port, &ports[i]) != 0) {
            perror("Thread creation failed");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < PORT_RANGE_END - PORT_RANGE_START + 1; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("Thread join failed");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
