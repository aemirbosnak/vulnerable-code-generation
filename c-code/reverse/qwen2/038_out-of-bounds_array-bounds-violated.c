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
    struct sockaddr_in server_addr;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) return NULL;

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        close(sock);
        return NULL;
    }

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == 0) {
        printf("Port %d is open\n", port);
        char buffer[1024];
        recv(sock, buffer, sizeof(buffer), 0);
        printf("Response: %s\n", buffer);
    }
    close(sock);
    return NULL;
}

int main() {
    pthread_t threads[PORT_RANGE_END - PORT_RANGE_START + 1];
    int ports[PORT_RANGE_END - PORT_RANGE_START + 1];

    for (int i = 0; i < PORT_RANGE_END - PORT_RANGE_START + 1; i++) {
        ports[i] = PORT_RANGE_START + i;
        pthread_create(&threads[i], NULL, scan_port, &ports[i]);
    }

    for (int i = 0; i < PORT_RANGE_END - PORT_RANGE_START + 1; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
