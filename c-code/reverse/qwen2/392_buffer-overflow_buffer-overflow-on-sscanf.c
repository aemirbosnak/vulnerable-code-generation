#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>

void* scan_port(void* arg) {
    int port = *(int*)arg;
    struct sockaddr_in server_addr;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) return NULL;

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == 0) {
        printf("Port %d is open\n", port);
    }
    close(sock);
    return NULL;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port_range>\n", argv[0]);
        return 1;
    }

    char* port_range = argv[1];
    int start_port, end_port;
    if (sscanf(port_range, "%d-%d", &start_port, &end_port) != 2) {
        fprintf(stderr, "Invalid port range format\n");
        return 1;
    }

    pthread_t threads[end_port - start_port + 1];
    for (int i = start_port; i <= end_port; i++) {
        pthread_create(&threads[i - start_port], NULL, scan_port, &i);
    }

    for (int i = start_port; i <= end_port; i++) {
        pthread_join(threads[i - start_port], NULL);
    }

    return 0;
}
