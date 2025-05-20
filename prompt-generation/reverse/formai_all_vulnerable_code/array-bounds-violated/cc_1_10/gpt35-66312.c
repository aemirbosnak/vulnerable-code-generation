//FormAI DATASET v1.0 Category: Chat server ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>

int server_socket, client_socket[10], num_clients;

void *handle_client(void *index){
    int client_index = *(int*)index;
    char message[256];
    while(1){
        memset(message, 0, sizeof(message));
        if(recv(client_socket[client_index], message, sizeof(message), 0) < 0){
            perror("recv error");
            break;
        }
        printf("Client %d: %s", client_index, message);
        if(strcmp(message, "exit\n") == 0){
            break;
        }
    }
    close(client_socket[client_index]);
    num_clients--;
}

int main(){
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char message[256];
    pthread_t thread_id;

    // create server socket
    if((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("socket creation error");
        return 1;
    }

    // set server address settings
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8888);

    // bind server socket to address
    if(bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0){
        perror("bind error");
        return 1;
    }

    // listen for clients
    if(listen(server_socket, 5) < 0){
        perror("listen error");
        return 1;
    }

    num_clients = 0;

    while(1){
        // accept new client
        if((client_socket[num_clients] = accept(server_socket, (struct sockaddr*)&client_addr, &client_len)) < 0){
            perror("accept error");
            continue;
        }
        printf("New client connected. Client index: %d\n", num_clients);
        // start a new thread to handle the client
        pthread_create(&thread_id, NULL, handle_client, &num_clients);
        num_clients++;
    }

    close(server_socket);
    return 0;
}