//FormAI DATASET v1.0 Category: Client Server Application ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8888
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int num_clients = 0;
int client_sockets[MAX_CLIENTS] = {0};

void *handle_client(void *client_socket)
{
    int sock = *(int *)client_socket;
    char buffer[BUFFER_SIZE] = {0};
    int read_size;

    printf("New connection. Socket fd is %d\n", sock);

    while((read_size = recv(sock, buffer, BUFFER_SIZE, 0)) > 0)
    {
        printf("Message received: %s\n", buffer);
        write(sock, buffer, strlen(buffer));
    }

    if(read_size == 0)
    {
        puts("Client disconnected");
        fflush(stdout);
    }
    else if(read_size == -1)
    {
        perror("recv failed");
    }

    close(sock);
    num_clients--;
    client_sockets[sock] = 0;
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    int server_fd, client_fd, opt = 1;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    pthread_t threads[MAX_CLIENTS];

    // Create socket file descriptor
    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Set address parameters
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the address and port specified
    if(bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming client connections
    if(listen(server_fd, MAX_CLIENTS) < 0)
    {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    while(1)
    {
        // Accept a client connection
        if((client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
        {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Add client socket to array
        int i;
        for(i = 0; i < MAX_CLIENTS; i++)
        {
            if(client_sockets[i] == 0)
            {
                client_sockets[i] = client_fd;
                break;
            }
        }

        // Create thread to handle client
        pthread_create(&threads[num_clients], NULL, handle_client, &client_fd);
        num_clients++;
    }

    return 0;
}