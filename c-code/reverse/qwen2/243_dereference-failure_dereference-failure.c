#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFSIZE 1024

void* handle_client(void* arg) {
    int new_socket = *(int*)arg;
    char buffer[BUFSIZE] = {0};
    while (1) {
        int valread = read(new_socket, buffer, BUFSIZE);
        if (valread <= 0) break;
        send(new_socket, buffer, strlen(buffer), 0);
        memset(buffer, 0, BUFSIZE);
    }
    close(new_socket);
    return NULL;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    pthread_t threads[10];

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            continue;
        }
        pthread_create(&threads[i], NULL, handle_client, &new_socket);
        i++;
        if (i >= 10) {
            i = 0;
            for (int j = 0; j < 10; j++) {
                pthread_join(threads[j], NULL);
            }
        }
    }

    return 0;
}
