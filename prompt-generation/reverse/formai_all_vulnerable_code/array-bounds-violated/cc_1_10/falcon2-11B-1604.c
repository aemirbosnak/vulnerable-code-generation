//Falcon2-11B DATASET v1.0 Category: Firewall ; Style: enthusiastic
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Function to create a TCP socket
int create_socket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }
    return sockfd;
}

// Function to bind the socket to a specific port
int bind_socket(int sockfd, int port) {
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    int bind_result = bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (bind_result == -1) {
        perror("bind");
        return -1;
    }
    return 0;
}

// Function to listen for incoming connections
int listen_socket(int sockfd, int backlog) {
    int listen_result = listen(sockfd, backlog);
    if (listen_result == -1) {
        perror("listen");
        return -1;
    }
    return 0;
}

// Function to accept incoming connections
int accept_socket(int sockfd, struct sockaddr *client_addr, socklen_t *addrlen) {
    int new_socket = accept(sockfd, client_addr, addrlen);
    if (new_socket == -1) {
        perror("accept");
        return -1;
    }
    return new_socket;
}

// Function to send data to a client
int send_data(int sockfd, const char *data, int length) {
    int send_result = send(sockfd, data, length, 0);
    if (send_result == -1) {
        perror("send");
        return -1;
    }
    return 0;
}

// Function to receive data from a client
int receive_data(int sockfd, char *data, int length) {
    int recv_result = recv(sockfd, data, length, 0);
    if (recv_result == -1) {
        perror("recv");
        return -1;
    }
    return recv_result;
}

// Main program
int main() {
    // Create a TCP socket
    int sockfd = create_socket();
    if (sockfd == -1) {
        perror("create_socket");
        return 1;
    }

    // Bind the socket to a specific port
    int port = 8080;
    int bind_result = bind_socket(sockfd, port);
    if (bind_result == -1) {
        perror("bind_socket");
        return 1;
    }

    // Listen for incoming connections
    int backlog = 5;
    int listen_result = listen_socket(sockfd, backlog);
    if (listen_result == -1) {
        perror("listen_socket");
        return 1;
    }

    printf("Server is listening on port %d\n", port);

    // Accept incoming connections
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t addrlen = sizeof(client_addr);
        int new_socket = accept_socket(sockfd, &client_addr, &addrlen);
        if (new_socket == -1) {
            perror("accept_socket");
            return 1;
        }

        printf("Accepted connection from %s:%d\n",
               inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Receive data from the client
        char buffer[1024];
        int received = receive_data(new_socket, buffer, sizeof(buffer));
        if (received == -1) {
            perror("receive_data");
            return 1;
        }
        buffer[received] = '\0';
        printf("Received data from client: %s\n", buffer);

        // Send data to the client
        int sent = send_data(new_socket, "Hello from server!\n", 20);
        if (sent == -1) {
            perror("send_data");
            return 1;
        }
        printf("Sent data to client: %s\n", "Hello from server!");

        // Close the connection
        close(new_socket);
    }

    return 0;
}