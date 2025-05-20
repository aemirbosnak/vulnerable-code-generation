//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: single-threaded
#include<netinet/in.h>
#include<sys/socket.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>

int main()
{
    int server_socket, new_socket, port_number;
    struct sockaddr_in server_address, client_address;
    int client_length, recv_size;
    char server_response[2000], client_message[2000];
    
    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // If socket creation fails
    if (server_socket == -1)
    {
        printf("Could not create socket!");
        return 1;
    }

    // Assign server details
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(5555);

    // Bind the socket to our specified IP and port
    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1)
    {
            printf("Could not bind socket!");
            return 1;
    }
    printf("Bind done!\n");

    // Listen to the incoming connections
    if (listen(server_socket, 3) == -1)
    {
        printf("Error, could not listen!");
        return 1;
    }

    printf("Waiting for incoming connections...\n");

    // Accept and incoming connection
    client_length = sizeof(struct sockaddr_in);
    new_socket = accept(server_socket, (struct sockaddr*)&client_address, (socklen_t*)&client_length);

    if (new_socket < 0)
    {
        printf("Error, could not accept connection!");
        return 1;
    }

    printf("Connection accepted from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

    // Send message to client
    strcpy(server_response, "Hello from server!");
    if (send(new_socket, server_response, strlen(server_response), 0) < 0)
    {
        printf("Error, could not send message!");
        return 1;
    }

    // Receive message from client
    while ((recv_size = recv(new_socket, client_message, 2000, 0)) > 0)
    {
        client_message[recv_size] = '\0';
        printf("Client says: %s\n", client_message);
    }

    if (recv_size == 0)
    {
        printf("Client disconnected.");
    }
    else if (recv_size < 0)
    {
        printf("Error, receiving message from client!");
        return 1;
    }

    close(server_socket);
    return 0;
}