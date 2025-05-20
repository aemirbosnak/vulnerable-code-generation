//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define BUFFER_SIZE 1024

struct file_info {
    char filename[256];
    char md5[33];
};

void *send_file_info(void *arg) {
    int sock = *(int *)arg;
    struct file_info *file_info = (struct file_info *)arg;

    send(sock, file_info->filename, strlen(file_info->filename)+1, 0);
    send(sock, file_info->md5, strlen(file_info->md5)+1, 0);
}

void *recv_file_info(void *arg) {
    int sock = *(int *)arg;
    struct file_info *file_info = (struct file_info *)malloc(sizeof(struct file_info));

    char filename[256];
    char md5[33];

    if (recv(sock, filename, 256, 0) <= 0 || recv(sock, md5, 33, 0) <= 0) {
        printf("Error receiving file info\n");
        exit(1);
    }

    strcpy(file_info->filename, filename);
    strcpy(file_info->md5, md5);

    pthread_t thread;
    pthread_create(&thread, NULL, send_file_info, file_info);
}

int main(int argc, char *argv[]) {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_sock, 5) < 0) {
        printf("Error listening on socket\n");
        exit(1);
    }

    pthread_t thread;
    while (1) {
        int client_sock = accept(server_sock, NULL, NULL);
        pthread_create(&thread, NULL, recv_file_info, &client_sock);
    }

    return 0;
}