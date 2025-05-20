//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 100
#define BUFFER_SIZE 256

int clientSockets[MAX_CLIENTS];
int clientCount = 0;
pthread_mutex_t clientMutex;

void *handleClient(void *socketDesc) {
    int sock = *(int*)socketDesc;
    char buffer[BUFFER_SIZE];
    int readSize;

    while ((readSize = recv(sock, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[readSize] = '\0';
        printf("Received: %s", buffer);
        
        pthread_mutex_lock(&clientMutex);
        for (int i = 0; i < clientCount; i++) {
            if (clientSockets[i] != sock) {
                send(clientSockets[i], buffer, readSize, 0);
            }
        }
        pthread_mutex_unlock(&clientMutex);
    }

    close(sock);
    return NULL;
}

int main() {
    int serverSocket, newSocket;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t addr_size;

    pthread_t threadId;

    // Initialize mutex
    if (pthread_mutex_init(&clientMutex, NULL) != 0) {
        perror("Mutex init failed");
        return 1;
    }

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        perror("Socket creation failed");
        return 1;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);

    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Bind failed");
        return 1;
    }

    listen(serverSocket, MAX_CLIENTS);
    printf("Chat server started on port %d...\n", PORT);

    while (1) {
        addr_size = sizeof(clientAddr);
        newSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &addr_size);

        pthread_mutex_lock(&clientMutex);
        if (clientCount < MAX_CLIENTS) {
            clientSockets[clientCount++] = newSocket;
            printf("New client connected: %d\n", newSocket);
            pthread_create(&threadId, NULL, handleClient, (void*)&newSocket);
        } else {
            printf("Max clients reached, connection rejected for: %d\n", newSocket);
            close(newSocket);
        }
        pthread_mutex_unlock(&clientMutex);
    }

    close(serverSocket);
    pthread_mutex_destroy(&clientMutex);
    return 0;
}