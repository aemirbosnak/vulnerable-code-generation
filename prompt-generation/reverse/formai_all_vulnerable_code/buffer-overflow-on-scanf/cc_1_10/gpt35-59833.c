//FormAI DATASET v1.0 Category: Client Server Application ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>

#define MAX_PENDING_REQUESTS 5
#define BUFFER_SIZE 1024
#define ENCRYPT_KEY 3

void *handle_client(void *arg){
    int sockfd = *(int*)arg;
    char buffer[BUFFER_SIZE];
    while (1){
        int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0){
            break;
        }
        for(int i=0;i<bytes_received;i++){
            buffer[i] = buffer[i] - ENCRYPT_KEY;
        }
        send(sockfd, buffer, bytes_received, 0);
        memset(buffer, 0, BUFFER_SIZE);
    }
    close(sockfd);
    return NULL;
}

int main(){
    int server_fd, client_fd, port_num;
    struct sockaddr_in server_addr, client_addr;
    pthread_t client_thread;
    socklen_t client_addr_len;
    char server_response[BUFFER_SIZE];

    printf("Enter port number: ");
    scanf("%d",&port_num);
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port_num);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0){
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, MAX_PENDING_REQUESTS) < 0){
        perror("listen");
        exit(EXIT_FAILURE);
    }
    printf("Server started listening on port %d...\n", port_num);

    while (1){
        client_addr_len = sizeof(client_addr);
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len)) < 0){
            perror("accept");
            exit(EXIT_FAILURE);
        }
        printf("Client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        if (pthread_create(&client_thread, NULL, handle_client, &client_fd)){
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }
    return 0;
}