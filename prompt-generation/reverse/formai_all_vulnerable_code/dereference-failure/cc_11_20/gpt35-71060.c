//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: interoperable
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 

#define BUFFER_SIZE 1024 

int main(int argc, char *argv[]) {
    int proxyPort,argsPort, socket_fd, client_socket_fd;
    char buffer[BUFFER_SIZE] = {0};
    struct sockaddr_in proxy_address, client_address, dest_address;
    socklen_t addr_len = sizeof(client_address);

    if(argc!=3){
        printf("Usage: <PROGRAM_NAME> <PROXY_PORT> <FORWARDED_PORT>");
        return 1;
    }

    proxyPort = atoi(argv[1]);

    argsPort = atoi(argv[2]);

    // create socket file descriptors
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        printf("Could not create socket.\n");
        return 1;
    }

    // set socket options
    int enable = 1;
    if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(enable)) == -1)
    {
        printf("Could not set socket options.\n");
        return 1;
    }

    // set up address structs for proxy and forwarded server
    memset(&proxy_address, '0', sizeof(proxy_address));
    proxy_address.sin_family = AF_INET;
    proxy_address.sin_addr.s_addr = htonl(INADDR_ANY);
    proxy_address.sin_port = htons(proxyPort);

    memset(&dest_address, '0', sizeof(dest_address));
    dest_address.sin_family = AF_INET;
    dest_address.sin_port = htons(argsPort);

    // bind proxy to specified port
    if(bind(socket_fd, (struct sockaddr *)&proxy_address, sizeof(proxy_address)) == -1)
    {
        printf("Could not bind socket to specified port.\n");
        return 1;
    }

    // wait for incoming connections from clients
    if(listen(socket_fd, 5) == -1)
    {
        printf("Could not listen for incoming connections.\n");
        return 1;
    }

    // keep proxy waiting for incoming connections from clients
    while(1)
    {
        // accept incoming connections from clients
        client_socket_fd = accept(socket_fd, (struct sockaddr *)&client_address, &addr_len);
        if (client_socket_fd == -1)
        {
            printf("Could not accept incoming connection.\n");
            continue;
        }

        // create a new process to handle the request
        if(!fork()){
            // create a new socket to connect to forwarded server
            int dest_fd = socket(AF_INET, SOCK_STREAM, 0);

            // connect to forwarded server
            if(connect(dest_fd, (struct sockaddr*)&dest_address, sizeof(dest_address)) == -1)
            {
                printf("Could not connect to forwarded server.\n");
                return 1;
            }

            // forward data from client to forwarded server
            while(1)
            {
                memset(buffer, 0, BUFFER_SIZE);
                int bytesRead = read(client_socket_fd, buffer, BUFFER_SIZE);
                if(bytesRead <= 0)
                {
                    break;
                }
                send(dest_fd, buffer, bytesRead, 0);
            }

            // close connections
            close(dest_fd);
            close(client_socket_fd);

            // exit child process
            exit(0);
        }
        // close client socket in parent process
        close(client_socket_fd);
    }
    // close proxy socket
    close(socket_fd);

    return 0;
}