//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define PORT 8080
#define IP "127.0.0.1"

void *receive_thread(void *arg);
void *send_thread(void *arg);

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(IP);

    connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

    pthread_t receive_id, send_id;
    pthread_create(&receive_id, NULL, receive_thread, NULL);
    pthread_create(&send_id, NULL, send_thread, NULL);

    pthread_join(receive_id, NULL);
    pthread_join(send_id, NULL);

    close(sock);
    return 0;
}

void *receive_thread(void *arg) {
    int sock = *(int *)arg;
    char buffer[BUFFER_SIZE];

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        recv(sock, buffer, BUFFER_SIZE, 0);
        printf("%s", buffer);
    }
}

void *send_thread(void *arg) {
    int sock = *(int *)arg;

    while (1) {
        char buffer[BUFFER_SIZE];
        fgets(buffer, BUFFER_SIZE, stdin);
        send(sock, buffer, strlen(buffer), 0);
    }
}