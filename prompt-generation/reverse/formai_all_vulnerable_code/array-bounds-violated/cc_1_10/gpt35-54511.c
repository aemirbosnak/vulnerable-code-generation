//FormAI DATASET v1.0 Category: Chat server ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int clientCount = 0;
int clients[10];

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *handleClient(void *clientSocket) {
    int sock = *(int *)clientSocket;
    char buffer[BUFFER_SIZE];
    int readBytes;

    while((readBytes = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[readBytes] = '\0';

        pthread_mutex_lock(&mutex);
        for(int i = 0; i < clientCount; i++) {
            if(clients[i] != sock) {
                write(clients[i], buffer, strlen(buffer));
            }
        }
        pthread_mutex_unlock(&mutex);
    }

    pthread_mutex_lock(&mutex);
    for(int i = 0; i < clientCount; i++) {
        if(clients[i] == sock) {
            close(clients[i]);
            clients[i] = -1;
        }
    }
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t addrSize = sizeof(clientAddr);

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);

    bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr));

    listen(serverSocket, 10);

    printf("Chat server started on port %d\n", PORT);

    while(1) {
        clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &addrSize);

        pthread_mutex_lock(&mutex);
        clients[clientCount] = clientSocket;
        clientCount++;
        pthread_mutex_unlock(&mutex);

        pthread_t threadId;
        if(pthread_create(&threadId, NULL, handleClient, (void *)&clientSocket) != 0) {
            printf("Failed to create thread for client\n");
            close(clientSocket);
        }
    }

    for(int i = 0; i < clientCount; i++) {
        close(clients[i]);
    }

    close(serverSocket);
    return 0;
}