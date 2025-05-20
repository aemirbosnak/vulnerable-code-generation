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
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <target_ip> <start_port> <end_port>\n", argv[0]);
        return 1;
    }

    char* target_ip = argv[1];
    int start_port, end_port;
    sscanf(argv[2], "%d", &start_port);
    sscanf(argv[3], "%d", &end_port);

    pthread_t threads[end_port - start_port + 1];
    int ports[end_port - start_port + 1];

    for (int i = 0; i <= end_port - start_port; i++) {
        ports[i] = start_port + i;
        pthread_create(&threads[i], NULL, scan_port, &ports[i]);
    }

    for (int i = 0; i <= end_port - start_port; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
