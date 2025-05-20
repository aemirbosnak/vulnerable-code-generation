//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_DEVICE_NUM 10
#define MAX_DEVICE_NAME_LEN 20
#define MAX_COMMAND_LEN 50

typedef struct device {
    char name[MAX_DEVICE_NAME_LEN];
    int sock;
} device_t;

device_t devices[MAX_DEVICE_NUM];
int device_num = 0;

void *handle_client(void *arg) {
    int client_sock = *(int*)arg;
    char buffer[1024];
    int len;

    while ((len = recv(client_sock, buffer, sizeof(buffer), 0)) > 0) {
        buffer[len] = '\0';
        printf("Received command: %s\n", buffer);

        int i;
        for (i = 0; i < device_num; i++) {
            if (strcmp(devices[i].name, buffer) == 0) {
                send(devices[i].sock, buffer, len, 0);
                break;
            }
        }
    }

    close(client_sock);
    return NULL;
}

int main() {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr));

    listen(server_sock, 10);

    while (1) {
        int client_sock = accept(server_sock, NULL, NULL);
        printf("New client connected\n");

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void*)&client_sock);
    }

    return 0;
}