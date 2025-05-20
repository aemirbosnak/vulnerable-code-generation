//FormAI DATASET v1.0 Category: Networking ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8000
#define SERVER_ADDR "127.0.0.1"
#define BUFFER_SIZE 1024

int main(int argc, char **argv)
{
    printf("Welcome to the Medieval Chatting Room!\n");

    // Create a socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1)
    {
        perror("Error creating server socket");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to an address and port
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(SERVER_ADDR);
    server_address.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1)
    {
        perror("Error binding server socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) == -1)
    {
        perror("Error listening to server socket");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for someone to knock the door...\n");
    int client_socket;
    struct sockaddr_in client_address;
    socklen_t addrlen = sizeof(client_address);
    char buffer[BUFFER_SIZE];
    while ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, &addrlen)) != -1)
    {
        printf("New guest has arrived!\n");
        inet_ntop(AF_INET, &client_address.sin_addr, buffer, BUFFER_SIZE);
        printf("Guest from %s:%d has entered the room.\n", buffer, ntohs(client_address.sin_port));

        while (1)
        {
            // Receive message from client
            int message_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
            if (message_received == -1)
            {
                perror("Error receiving message from guest");
                exit(EXIT_FAILURE);
            }
            else if (message_received == 0)
            {
                printf("Guest has left the room!\n");
                break;
            }

            buffer[message_received] = '\0';
            printf("%s", buffer);

            // Send message to client
            char *medieval_reply = "Greetings, brave adventurer!\n";
            if (send(client_socket, medieval_reply, strlen(medieval_reply), 0) == -1)
            {
                perror("Error sending message to guest");
                exit(EXIT_FAILURE);
            }
        }
    }

    return 0;
}