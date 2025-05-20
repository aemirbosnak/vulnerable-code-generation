//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<netdb.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<fcntl.h>

#define MAX_BUFFER_SIZE 4096
#define MAX_CONNECTIONS 10

int main(int argc, char *argv[])
{
    if(argc!=4)
    {
        printf("Usage: ./proxy <ip_address> <port_number> <url>\n");
        exit(1);
    }

    int listen_socket_fd, comm_socket_fd, client_socket_fd;
    struct sockaddr_in server_address, client_address;
    char buffer[MAX_BUFFER_SIZE];
    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);
    char *url = argv[3];

    //Create a Socket
    listen_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(listen_socket_fd<0)
    {
        perror("Error in Socket Creation: ");
        exit(1);
    }

    //Initialize Server Address Struct
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port_number);
    server_address.sin_addr.s_addr = inet_addr(ip_address);

    //Bind Socket to Address
    if(bind(listen_socket_fd, (struct sockaddr*)&server_address, sizeof(server_address))<0)
    {
        perror("Error in Binding: ");
        exit(1);
    }

    //Listen for Incoming Connections
    if(listen(listen_socket_fd, MAX_CONNECTIONS)<0)
    {
        perror("Error in Listening: ");
        exit(1);    
    }

    socklen_t client_address_length = sizeof(client_address);

    //Accept Incoming Connections and Create New Socket for Communication
    while(1)
    {
        comm_socket_fd = accept(listen_socket_fd, (struct sockaddr*)&client_address, &client_address_length);
        if(comm_socket_fd<0)
        {
            perror("Error in Accepting: ");
            exit(1);
        }

        //Fork a process for New Connection and Handle Communication
        if(fork()==0)
        {
            client_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
            if(client_socket_fd<0)
            {
                perror("Error in Socket Creation: ");
                exit(1);
            }

            //Get Server Address Structure Using DNS Lookup
            struct hostent *server;
            server = gethostbyname(url);
            if(server==NULL)
            {
                printf("Error in Getting Host: %s\n", hstrerror(h_errno));
            }

            struct sockaddr_in server_address;
            server_address.sin_family = AF_INET;
            server_address.sin_port = htons(80);
            bcopy((char *)server->h_addr, (char *)&server_address.sin_addr.s_addr, server->h_length);
            
            //Establish Connection with Server
            if(connect(client_socket_fd, (struct sockaddr*)&server_address, sizeof(server_address))<0)
            {
                perror("Error in Connecting to Server: ");
                exit(1);
            }

            //Forward Client Request to Server
            if(send(client_socket_fd, buffer, strlen(buffer), 0)<0)
            {
                perror("Error in Sending Request to Server: ");
                exit(1);
            }

            //Receive Response from Server
            memset(buffer, 0, MAX_BUFFER_SIZE);
            if(recv(client_socket_fd, buffer, MAX_BUFFER_SIZE, 0)<0)
            {
                perror("Error in Receiving Response from Server: ");
                exit(1);
            }

            //Forward Server Response to Client
            if(send(comm_socket_fd, buffer, strlen(buffer), 0)<0)
            {
                perror("Error in Sending Response to Client: ");
                exit(1);
            }

            //Close Sockets
            close(client_socket_fd);
            close(comm_socket_fd);
            exit(0);
        }
        //Close Communication Socket in Parent Process
        close(comm_socket_fd);
    }
    //Close Listening Socket
    close(listen_socket_fd);
    return 0;
}