//Code Llama-13B DATASET v1.0 Category: Socket programming ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUF_SIZE 1024

int main(int argc, char **argv) {
    int sockfd, new_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[BUF_SIZE];

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // initialize server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // bind socket to address
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    // listen for incoming connections
    if (listen(sockfd, 3) == -1) {
        perror("listen");
        exit(1);
    }

    // accept incoming connections
    new_fd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);
    if (new_fd == -1) {
        perror("accept");
        exit(1);
    }

    // receive data from client
    memset(buffer, 0, BUF_SIZE);
    read(new_fd, buffer, BUF_SIZE);

    // send data to client
    write(new_fd, buffer, strlen(buffer));

    // close socket
    close(new_fd);
    close(sockfd);

    return 0;
}