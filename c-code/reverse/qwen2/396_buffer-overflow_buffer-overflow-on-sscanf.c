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
    int start = *(int*)arg;
    for (int i = start; i <= 65535; i++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_port = htons(i);
        inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);
        if (connect(sock, (struct sockaddr*)&addr, sizeof(addr)) == 0) {
            printf("Port %d is open\n", i);
        }
        close(sock);
    }
    return NULL;
}

int main() {
    char input[256];
    printf("Enter port range: ");
    fgets(input, sizeof(input), stdin);
    int start, end;
    sscanf(input, "%d-%d", &start, &end);

    pthread_t threads[end - start + 1];
    for (int i = 0; i < end - start + 1; i++) {
        pthread_create(&threads[i], NULL, scan_port, &start + i);
    }

    for (int i = 0; i < end - start + 1; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
