//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int master_socket, client_socket[MAX_CLIENTS];
    int opt = 1;
    struct sockaddr_in server_addr, client_addr[MAX_CLIENTS];
    int addrlen = sizeof(client_addr[0]);
    char buffer[BUFFER_SIZE];
    int max_socket = 0;

    // Create socket
    if((master_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set options on the socket
    if(setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        printf("Error setting options on socket\n");
        exit(1);
    }

    // Initialize server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to an address and port
    if(bind(master_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("Error binding socket\n");
        exit(1);
    }

    // Listen for incoming connections
    if(listen(master_socket, MAX_CLIENTS) < 0)
    {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server is listening on port %d\n", PORT);

    while(1)
    {
        // Accept a new connection
        if((client_socket[max_socket] = accept(master_socket, (struct sockaddr *)&client_addr[max_socket], &addrlen)) < 0)
        {
            printf("Error accepting connection\n");
            exit(1);
        }

        printf("New client connected with socket fd %d\n", client_socket[max_socket]);

        max_socket++;
    }

    return 0;
}