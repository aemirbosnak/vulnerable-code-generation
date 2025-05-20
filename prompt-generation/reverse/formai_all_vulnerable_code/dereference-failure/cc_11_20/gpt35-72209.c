//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int client_fd, server_fd, len, num_bytes;
    struct sockaddr_in client_addr, server_addr;
    char buffer[BUFFER_SIZE];
    struct hostent *host_info;

    //Create socket for client
    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error: Failed to create socket for client: %s\n", strerror(errno));
        exit(1);
    }

    //Configure client address
    memset(&client_addr, 0, sizeof(client_addr));
    client_addr.sin_family = AF_INET; 
    client_addr.sin_port = htons(PORT); 
    client_addr.sin_addr.s_addr = INADDR_ANY; 

    //Bind client socket to address and port
    if (bind(client_fd, (struct sockaddr*)&client_addr, sizeof(client_addr)) == -1) {
        printf("Error: Binding the client: %s\n", strerror(errno));
        exit(1);
    }

    //Listen on client socket for incoming connections
    if (listen(client_fd, 1) == -1) {
        printf("Error: Listening on the client: %s\n", strerror(errno));
        exit(1);
    }

    len = sizeof(server_addr);

    //Accept connection from client
    while(1) {
        if ((server_fd = accept(client_fd, (struct sockaddr*)&server_addr, &len)) == -1) {
            printf("Error: Accepting the client connection: %s\n", strerror(errno));
            exit(1);
        }

        //Get host information from the client's request
        if ((host_info = gethostbyname(buffer)) == NULL) {
            printf("Error: Failed to resolve hostname: %s\n", strerror(errno));
            exit(1);
        } 

        //Configure server address
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(80);
        server_addr.sin_addr = *((struct in_addr *)host_info->h_addr);

        //Create socket for server
        if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
            printf("Error: Failed to create socket for server: %s\n", strerror(errno));
            exit(1);
        }

        //Connect to server
        if (connect(client_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
            printf("Error: Failed to connect to server: %s\n", strerror(errno));
            exit(1);
        }

        //Forward client request to server
        while((num_bytes = recv(server_fd, buffer, BUFFER_SIZE, 0)) > 0) {
            if (send(client_fd, buffer, num_bytes, 0) == -1) {
                printf("Error: Failed to forward request to server: %s\n", strerror(errno));
                exit(1);
            }
        }

        //Close connections
        close(server_fd);
        close(client_fd);
    }

    return 0;
}