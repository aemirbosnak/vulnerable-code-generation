//FormAI DATASET v1.0 Category: Socket programming ; Style: multiplayer
// This is a multi-player chatroom program using sockets in C

#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <sys/types.h>  
#include <sys/socket.h>  
#include <netinet/in.h>  
#include <arpa/inet.h>  
#include <unistd.h>  
#include <pthread.h>  

#define PORT 3000  
#define MAX_CLIENTS 5  

int clients[MAX_CLIENTS]; // array to store client sockets 
int client_count = 0;  
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // mutex to prevent multiple access 

// function to send message to all clients except sender  
void send_message(char *message, int curr) {  
    pthread_mutex_lock(&mutex);  
    for(int i=0; i<client_count;i++) {  
        if(clients[i] != curr) {  
            if(send(clients[i],message,strlen(message),0) < 0) {  
                perror("send messages error");  
                exit(1);  
            }  
        }  
    }  
    pthread_mutex_unlock(&mutex);  
}  

// function for handling client 
void* handle_client(void *client_socket) {  
    int socket_fd = *((int*)client_socket);  
    char buffer[256];  
    int read_len;  

    // receive incoming messages from client 
    while((read_len = recv(socket_fd, buffer, sizeof(buffer), 0)) > 0) {  
        buffer[read_len] = '\0';  
        send_message(buffer, socket_fd);  
    }  
    
    // remove client from server list on client close
    pthread_mutex_lock(&mutex);  
    for(int i=0; i<client_count;i++) {  
        if(clients[i] == socket_fd) {  
            while(i < MAX_CLIENTS-1) {  
                clients[i] = clients[i+1];  
                i++;  
            }  
        }  
    }  
    client_count--;  
    pthread_mutex_unlock(&mutex);  
    close(socket_fd);  
    pthread_exit(NULL);  
}  

int main() {  
    int server_fd, client_fd;  
    struct sockaddr_in server_addr,client_addr;  
    socklen_t client_len;  
    pthread_t client_threads[MAX_CLIENTS];  

    memset(&server_addr,0,sizeof(server_addr));  
    server_addr.sin_family = AF_INET;  
    server_addr.sin_port = htons(PORT);  
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  

    server_fd = socket(AF_INET,SOCK_STREAM,0);  
    
    if(bind(server_fd,(struct sockaddr *)&server_addr,sizeof(server_addr)) == -1) {  
        perror("bind error");  
        exit(1);  
    }  
    
    if(listen(server_fd,MAX_CLIENTS) == -1) {  
        perror("listen error");  
        exit(1);  
    }  
    
    printf("Server started and listening on port %d...\n",PORT);  
    
    // keep accepting incoming clients and spawn a new thread for each 
    while(1) {  
        client_len = sizeof(client_addr);  
        client_fd = accept(server_fd,(struct sockaddr*)&client_addr, &client_len);  
        if(client_fd == -1) {  
            perror("accept error");  
            continue;  
        }  

        if(client_count > MAX_CLIENTS) {  
            printf("Too many clients\n");  
            close(client_fd);  
            continue;  
        }  

        clients[client_count++] = client_fd;  
        printf("New client joined %d from %s:%d\n", client_count, inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));  

        if(pthread_create(&client_threads[client_count-1], NULL, handle_client, &clients[client_count-1]) != 0) {  
            printf("Failed to create thread\n");  
        }  
    }  

    close(server_fd);  
    return 0;  
}