//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>

#define MAX 100

// Function to create socket
int create_socket(int port) {
    int sockfd;
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    listen(sockfd, 5);

    return sockfd;
}

// Function to accept connection
int accept_connection(int sockfd) {
    struct sockaddr_in cli_addr;
    socklen_t clilen;
    int newsockfd;

    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);

    if (newsockfd < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    return newsockfd;
}

// Function to send data
int send_data(int sockfd, char *message) {
    int sent = 0;
    while (sent < strlen(message)) {
        sent += send(sockfd, message + sent, strlen(message) - sent, 0);
    }

    return sent;
}

// Function to receive data
int receive_data(int sockfd, char *buffer, int buffsize) {
    int received = 0;
    while (received < buffsize) {
        received += recv(sockfd, buffer + received, buffsize - received, 0);
    }

    buffer[received] = '\0';

    return received;
}

// Function to handle multiple clients
void handle_clients(int master_socket) {
    int addrlen;
    struct sockaddr_in addr;
    int newsocket;

    while (1) {
        addrlen = sizeof(addr);
        newsocket = accept(master_socket, (struct sockaddr *)&addr, &addrlen);

        if (newsocket < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("Client %s connected\n", inet_ntoa(addr.sin_addr));

        char buffer[MAX];
        while (1) {
            memset(buffer, 0, MAX);
            int bytes_received = receive_data(newsocket, buffer, MAX);

            if (bytes_received <= 0) {
                close(newsocket);
                break;
            }

            printf("Message from client: %s\n", buffer);

            send_data(newsocket, buffer);
        }
    }
}

int main() {
    int master_socket;

    master_socket = create_socket(8080);

    handle_clients(master_socket);

    return 0;
}