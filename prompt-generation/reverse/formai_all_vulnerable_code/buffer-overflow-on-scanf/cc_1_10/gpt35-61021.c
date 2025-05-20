//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

void handle_sigint(int sig) {
    printf("Stopping QoS monitor...\n");
    exit(0);
}

int main(int argc, char *argv[]) {
    signal(SIGINT, handle_sigint);
    int port;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0) {
        printf("Unable to create socket\n");
        exit(0);
    }
    printf("Socket created successfully\n");
    printf("Enter port number to listen on: ");
    scanf("%d", &port);
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    if(bind(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        printf("Unable to bind socket to port %d\n", port);
        exit(0);
    }
    printf("Socket bound successfully to port %d\n", port);
    listen(sock, 5);
    printf("Listening for connections...\n");
    while(1) {
        struct sockaddr_in client_addr;
        int client_sock = accept(sock,(struct sockaddr *) &client_addr, (socklen_t *) &client_addr);
        if(client_sock < 0) {
            printf("Unable to accept connection\n");
            continue;
        }
        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        char buffer[1024];
        int read_size;
        while((read_size = recv(client_sock, buffer, sizeof(buffer), 0)) > 0) {
            printf("Received data from client %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
            printf("%s\n", buffer);
            // Here goes the QoS measurement logic
        }
        if(read_size == 0) {
            printf("Client %s:%d disconnected\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        }
        else {
            printf("Unable to receive data from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        }
        close(client_sock);
    }
    return 0;
}