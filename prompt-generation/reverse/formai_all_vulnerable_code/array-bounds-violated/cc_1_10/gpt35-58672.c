//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: excited
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// define the buffer size
#define BUF_SIZE 4096

int main(int argc, char *argv[]) {
    int client_sock, proxy_sock, recv_size;
    char message[BUF_SIZE], server_reply[BUF_SIZE];
    struct sockaddr_in proxy_addr, server_addr;
     
    // create socket for receiving client request
    client_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (client_sock == -1) {
        printf("Could not create socket");
        return 1;
    }
    puts("Client socket created");

    // define proxy server address
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY;
    proxy_addr.sin_port = htons(8888);

    // bind the socket to the proxy server address
    if (bind(client_sock, (struct sockaddr *) &proxy_addr, sizeof(proxy_addr)) < 0) {
        perror("Bind failed. Error");
        return 1;
    }
    puts("Bind done");

    // listen for incoming client connections
    listen(client_sock, 3);

    // accept incoming client connection
    puts("Waiting for incoming connections...");
    socklen_t addr_len = sizeof(server_addr);
    int c = sizeof(struct sockaddr_in);
    proxy_sock = accept(client_sock, (struct sockaddr *) &server_addr, &c);
    if (proxy_sock < 0) {
        perror("Accept failed");
        return 1;
    }
    puts("Connection accepted");

    // receive client message
    if ((recv_size = recv(proxy_sock, message, BUF_SIZE, 0)) < 0) {
        perror("Receive failed");
        return 1;
    }
    message[recv_size] = '\0';
    printf("Client Message: %s\n", message);

    // create socket for sending message to server
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        printf("Could not create socket");
        return 1;
    }
    puts("Server socket created");

    // connect to the destination server
    if (connect(server_sock, (struct sockaddr *) &server_addr, addr_len) < 0) {
        perror("Connection failed");
        return 1;
    }
    puts("Connected to server");

    // send the client message to the server
    if (send(server_sock, message, strlen(message), 0) < 0) {
        perror("Send failed");
        return 1;
    }

    // receive response from server
    if ((recv_size = recv(server_sock, server_reply, BUF_SIZE, 0)) < 0) {
        perror("Receive failed");
        return 1;
    }
    server_reply[recv_size] = '\0';
    printf("Server Reply: %s\n", server_reply);

    // send server reply to client
    if (send(proxy_sock, server_reply, strlen(server_reply), 0) < 0) {
        perror("Send failed");
        return 1;
    }

    // close all sockets
    close(client_sock);
    close(proxy_sock);
    close(server_sock);
    return 0;
}