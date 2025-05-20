//FormAI DATASET v1.0 Category: Chat server ; Style: medieval
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <unistd.h> 
#include <arpa/inet.h> 

#define MAX_CLIENTS 10 
#define MAX_NAME_LEN 20 
#define MAX_MSG_LEN 100 

typedef struct 
{ 
    int socket_fd; 
    char name[MAX_NAME_LEN]; 
} Client; 

typedef struct 
{ 
    Client clients[MAX_CLIENTS]; 
    int num_clients; 
} ClientList; 

ClientList client_list = {0}; 

void send_message(char* message, int sender_fd) 
{ 
    for (int i = 0; i < client_list.num_clients; i++) 
    { 
        if (client_list.clients[i].socket_fd != sender_fd) 
        { 
            char full_message[MAX_MSG_LEN + MAX_NAME_LEN + 3]; 
            sprintf(full_message, "%s: %s\n", client_list.clients[i].name, message); 
            send(client_list.clients[i].socket_fd, full_message, strlen(full_message), 0); 
        } 
    } 
} 

void notify_clients() 
{ 
    char message[MAX_MSG_LEN + MAX_NAME_LEN + 3]; 

    sprintf(message, "%s has joined the chat\n", client_list.clients[client_list.num_clients - 1].name); 
    send_message(message, -1); 
} 

int main() 
{ 
    int server_fd = socket(AF_INET, SOCK_STREAM, 0); 

    struct sockaddr_in server_address, client_address; 
    server_address.sin_family = AF_INET; 
    server_address.sin_addr.s_addr = INADDR_ANY; 
    server_address.sin_port = htons(9001); 

    bind(server_fd, (struct sockaddr*) &server_address, sizeof(server_address)); 
    listen(server_fd, MAX_CLIENTS); 
    printf("The Chat Server is online and awaits your order, My Lord.\n"); 

    while (1) 
    { 
        int address_len = sizeof(client_address); 
        int client_fd = accept(server_fd, (struct sockaddr*) &client_address, &address_len); 

        if (client_list.num_clients == MAX_CLIENTS) 
        { 
            char message[] = "The chat room is full, my lord!\n"; 
            send(client_fd, message, strlen(message), 0); 
            close(client_fd); 
            continue; 
        } 

        char name[MAX_NAME_LEN]; 
        int name_len = recv(client_fd, name, MAX_NAME_LEN, 0); 

        if (name_len <= 0) 
        { 
            close(client_fd); 
            continue; 
        } 

        name[name_len - 1] = '\0'; 

        int i; 
        for (i = 0; i < client_list.num_clients; i++) 
            if (strcmp(name, client_list.clients[i].name) == 0) 
            { 
                char message[] = "A user with this name already exists, my lord!\n"; 
                send(client_fd, message, strlen(message), 0); 
                close(client_fd); 
                break; 
            } 

        if (i != client_list.num_clients) 
            continue; 

        Client new_client = {client_fd, ""}; 
        strcpy(new_client.name, name); 
        client_list.clients[client_list.num_clients] = new_client; 
        client_list.num_clients++; 

        printf("%s has joined the chat\n", name); 

        notify_clients(); 

        char message[MAX_MSG_LEN]; 

        while (1) 
        { 
            int bytes_received = recv(client_fd, message, MAX_MSG_LEN, 0); 

            if (bytes_received <= 0) 
                break; 

            message[bytes_received - 1] = '\0'; 
            send_message(message, client_fd); 
        } 

        for (i = 0; i < client_list.num_clients; i++) 
            if (client_list.clients[i].socket_fd == client_fd) 
            { 
                close(client_fd); 
                printf("%s has left the chat\n", client_list.clients[i].name); 
                for (; i < client_list.num_clients - 1; i++) 
                    client_list.clients[i] = client_list.clients[i + 1]; 
                client_list.num_clients--; 
                notify_clients(); 
                break; 
            } 
    } 

    return 0; 
}