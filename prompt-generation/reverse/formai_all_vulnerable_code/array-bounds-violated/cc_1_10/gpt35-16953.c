//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

#define MAX_BUF_SIZE 256
#define SERVER_PORT 8080

int main(int argc, char *argv[]) {
    int sockfd, client_sock, read_size;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_BUF_SIZE], reply[MAX_BUF_SIZE];

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Failed to create socket");
        return 1;
    }
    printf("Socket created successfully\n");

    // prepare the sockaddr_in structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // bind
    if (bind(sockfd, (struct sockaddr *)&server_addr , sizeof(server_addr)) < 0) {
        perror("Bind failed. Error");
        exit(1);
    }
    printf("Bind completed\n");

    // listen
    listen(sockfd , 3);

    // accept incoming connection
    puts("Waiting for incoming connections...");
    int c = sizeof(struct sockaddr_in);
    client_sock = accept(sockfd, (struct sockaddr *)&client_addr, (socklen_t*)&c);
    if (client_sock < 0) {
        perror("Accept failed");
        exit(1);
    }
    printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // receive message from client
    while ((read_size = recv(client_sock, buffer, MAX_BUF_SIZE, 0)) > 0) {
        // add end of buffer marker
        buffer[read_size] = '\0';

        // print received message
        printf("Received message: %s\n", buffer);

        // prepare reply message
        strcpy(reply, "Echo: ");
        strcat(reply, buffer);

        // send reply to client
        write(client_sock, reply, strlen(reply));

        // clear buffers
        memset(buffer, 0, MAX_BUF_SIZE);
        memset(reply, 0, MAX_BUF_SIZE);
    }

    if (read_size == 0) {
        printf("Client disconnected\n");
    } else if (read_size == -1) {
        perror("Receive failed");
        exit(1);
    }

    return 0;
}