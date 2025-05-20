//FormAI DATASET v1.0 Category: Networking ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#define PORT 8080

void greet() {
    printf("Hello and welcome to our happy networking program!\n");
    printf("We're excited to connect you with others!\n");
}

void server() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Connection established and welcome to the server!";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Attach socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept new connections
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    // Send greeting message
    send(new_socket, hello, strlen(hello), 0);
    printf("Greeting message sent\n");

    // Read message from client
    valread = read(new_socket, buffer, 1024);
    printf("%s\n", buffer);
    close(new_socket);
    close(server_fd);
}

void client() {
    struct sockaddr_in serv_addr;
    int sock = 0, valread;
    char *hello = "Hello from client";
    char buffer[1024] = {0};

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IP address from text to binary format
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        printf("\nInvalid address/ Address not supported \n");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        exit(EXIT_FAILURE);
    }

    // Read greeting message from server
    valread = read(sock, buffer, 1024);
    printf("%s\n", buffer);

    // Send message to server
    send(sock, hello, strlen(hello), 0);
    printf("Hello message sent\n");

    close(sock);
}

int main(int argc, char const *argv[]) {
    greet();
    int option;
    printf("Press 1 to start the server, press 2 to connect to a server: ");
    scanf("%d", &option);

    switch(option) {
        case 1: server(); break;
        case 2: client(); break;
        default: printf("Invalid option\n"); break;
    }
    return 0;
}