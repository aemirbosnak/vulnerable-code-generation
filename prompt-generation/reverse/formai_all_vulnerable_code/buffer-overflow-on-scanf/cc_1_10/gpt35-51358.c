//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define BUF_SIZE 1024

void *send_file(void *arg) {
    int sockfd = *(int*)arg;
    char filename[100];
    printf("Enter filename to send: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "rb");
    if(fp == NULL) {
        printf("Error: File not found.\n");
        return NULL;
    }

    char buffer[BUF_SIZE];
    int nread;

    while((nread = fread(buffer, 1, BUF_SIZE, fp)) > 0) {
        if(send(sockfd, buffer, nread, 0) < 0) {
            printf("Error: Failed to send file.\n");
            break;
        }
        bzero(buffer, BUF_SIZE);
    }

    fclose(fp);
    printf("File sent successfully.\n");
    return NULL;
}

void *recv_file(void *arg) {
    int sockfd = *(int*)arg;
    char filename[100];
    printf("Enter filename to save: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "wb");
    if(fp == NULL) {
        printf("Error: Failed to create file.\n");
        return NULL;
    }

    char buffer[BUF_SIZE];
    int nread;

    while ((nread = recv(sockfd, buffer, BUF_SIZE, 0)) > 0) {
        if(fwrite(buffer, 1, nread, fp) < nread) {
            printf("Error: Failed to write file.\n");
            break;
        }
        bzero(buffer, BUF_SIZE);
    }

    fclose(fp);
    printf("File received successfully.\n");
    return NULL;
}

int main() {
    char server_ip[16];
    int server_port;

    printf("Enter server IP: ");
    scanf("%s", server_ip);

    printf("Enter server port: ");
    scanf("%d", &server_port);

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        printf("Error: Failed to create socket.\n");
        return -1;
    }

    // Connect to server
    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server_ip);
    server_addr.sin_port = htons(server_port);

    if(connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error: Failed to connect to server.\n");
        return -1;
    }

    // Create threads to send and receive files simultaneously
    pthread_t send_thread, recv_thread;

    if(pthread_create(&send_thread, NULL, send_file, &sockfd) < 0) {
        printf("Error: Failed to create send thread.\n");
        return -1;
    }

    if(pthread_create(&recv_thread, NULL, recv_file, &sockfd) < 0) {
        printf("Error: Failed to create receive thread.\n");
        return -1;
    }

    // Wait for threads to finish
    pthread_join(send_thread, NULL);
    pthread_join(recv_thread, NULL);

    // Close socket
    close(sockfd);
    return 0;
}