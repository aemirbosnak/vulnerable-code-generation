//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: satisfied
/* This is a program that demonstrates the use of C language for TCP/IP programming */
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFF_SIZE 4096 // This is the buffer size of the messages

int main(int argc, char *argv[])
{
    int sock_fd, client_fd, read_size;
    struct sockaddr_in server, client;
    char client_msg[BUFF_SIZE];
    char server_msg[BUFF_SIZE] = "Hello from server!"; // This is the message sent from server to client

    // Create socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0)
    {
        perror("Socket creation error");
        return 1;
    }
    puts("Socket created successfully!");

    // Prepare the sockaddr_in structure for server
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);

    // Bind the socket to port 8888
    if (bind(sock_fd, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        perror("Bind error");
        return 1;
    }
    puts("Binding socket to port 8888");

    // Listen for incoming connections
    listen(sock_fd, 3);

    // Accept incoming connection
    puts("Waiting for incoming connections...");
    int c = sizeof(struct sockaddr_in);
    client_fd = accept(sock_fd, (struct sockaddr *)&client, (socklen_t *)&c);
    if (client_fd < 0)
    {
        perror("Connection accept error");
        return 1;
    }
    puts("Connection accepted successfully!");

    // Receive message from client and reply with server message
    while ((read_size = recv(client_fd, client_msg, BUFF_SIZE, 0)) > 0)
    {
        // Add null terminator to received message
        client_msg[read_size] = '\0';
        printf("Message received from client: %s\n", client_msg);

        // Send server message to client
        if (send(client_fd, server_msg, strlen(server_msg), 0) < 0)
        {
            perror("Send error");
            return 1;
        }
    }

    if (read_size == 0)
    {
        puts("Client disconnected");
        fflush(stdout);
    }
    else if (read_size == -1)
    {
        perror("Receive error");
        return 1;
    }

    // Cleanup and close the sockets
    close(sock_fd);
    close(client_fd);
    return 0;
}