//FormAI DATASET v1.0 Category: Networking ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>

#define PORT 8080

int main(){
    int sockfd, connfd;
    struct sockaddr_in server_address, client_address;

    // Create Socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1){
        printf("Socket Creation Failed...\n");
        exit(0);
    }
    printf("Socket Created Successfully...\n");

    // Socket Address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(PORT);

    // Bind
    if(bind(sockfd, (const struct sockaddr *)&server_address, sizeof(server_address)) == -1){
        printf("Binding Failed...\n");
        exit(0);
    }
    printf("Socket Binded Successfully...\n");

    // Listen
    if(listen(sockfd, 5) == -1){
        printf("Listening Failed...\n");
        exit(0);
    }
    printf("Server Listening...\n");

    // Accept
    while(1){
        socklen_t size_client = sizeof(client_address);
        connfd = accept(sockfd, (struct sockaddr *)&client_address, &size_client);
        if(connfd == -1){
            printf("Connection Failed...\n");
            exit(0);
        }
        printf("Client Connected Successfully...\n");

        // Read and Write
        char buffer[1024];
        int read_size = recv(connfd, &buffer, 1024, 0);
        buffer[read_size] = '\0';
        printf("Client Message: %s\n", buffer);

        char *reply = "Hello Client!";
        int write_size = send(connfd, reply, strlen(reply), 0);
        if(write_size == -1){
            printf("Failed to send reply...\n");
        }
        printf("Reply Sent Successfully...\n");

        // Close Connection
        close(connfd);
        printf("Connection Closed...\n");
    }

    // Close Socket
    close(sockfd);
    printf("Socket Closed...\n");

    return 0;
}