//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: puzzling
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>

#define PORT 8080
#define BUFSIZE 4096

void create_socket(int *sfd){
    if ((*sfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        printf("Socket creation error\n");
        exit(EXIT_FAILURE);
    }
    printf("Proxy socket created successfully.\n");
}

void bind_socket(int sfd){
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    if (bind(sfd, (struct sockaddr*)&addr, sizeof(addr)) < 0){
        printf("Socket bind error\n");
        exit(EXIT_FAILURE);
    }
    printf("Proxy socket binded successfully.\n");
}

void listen_socket(int sfd){
    if (listen(sfd, 3) < 0){
        printf("Socket listen error\n");
        exit(EXIT_FAILURE);
    }
    printf("Proxy socket listening on port %d...\n", PORT);
}

void connect_server(int *cfd, char *ip, int port){
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip);
    server_addr.sin_port = htons(port);

    if (connect(*cfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0){
        printf("Server connection error\n");
        exit(EXIT_FAILURE);
    }
    printf("Connection established successfully with server.\n");
}

void forward_data(int from_fd, int to_fd, char *client, char *server){
    char buffer[BUFSIZE] = {0};
    int valread;

    while (1){
        valread = read(from_fd, buffer, BUFSIZE);
        printf("%s\n", client);
        printf("%s\n", buffer);
        
        if (valread <= 0) break;

        send(to_fd, buffer, valread, 0);
        printf("%s\n", server);
        printf("%s\n", buffer);

        memset(buffer, 0, BUFSIZE);
    }
}

int main(){
    int proxy_sfd, server_sfd, client_socket;
    struct sockaddr_in client_addr;
    int addrlen = sizeof(client_addr);
    char request[BUFSIZE], *client_ip, *server_ip;
    int client_port, server_port;

    create_socket(&proxy_sfd);
    bind_socket(proxy_sfd);
    listen_socket(proxy_sfd);

    printf("Enter the client IP address: ");
    scanf("%s", client_ip);
    printf("Enter the client port: ");
    scanf("%d", &client_port);
    printf("Enter the server IP address: ");
    scanf("%s", server_ip);
    printf("Enter the server port: ");
    scanf("%d", &server_port);

    while (1){
        printf("Proxy is waiting for connections...\n");
        if ((client_socket = accept(proxy_sfd, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen)) < 0){
            printf("Connection accept error");
            exit(EXIT_FAILURE);
        }

        printf("Client connected successfully\n");
        printf("Client Address: %s\n", inet_ntoa(client_addr.sin_addr));
        printf("Client Port: %d\n\n", ntohs(client_addr.sin_port));

        create_socket(&server_sfd);
        connect_server(&server_sfd, server_ip, server_port);

        forward_data(client_socket, server_sfd, "Message from client:", "Message from server:");

        printf("\nClosing connection...\n");
        close(server_sfd);
        close(client_socket);
    }
    return 0;
}