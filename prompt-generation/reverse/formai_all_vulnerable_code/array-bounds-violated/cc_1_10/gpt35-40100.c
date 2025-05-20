//FormAI DATASET v1.0 Category: Socket programming ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {

    /*Declare our socket and address format*/
    int server_socket, new_socket, status, client_length;
    struct sockaddr_in server_address, client_address;
    char buffer[1024];

    /*Create a TCP socket*/
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    /*Check if the socket was created*/
    if (server_socket == -1) {
        printf("Error: Unable to create socket!\n");
        exit(-1);
    }

    /*Define our server address format*/
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);

    /*Bind our socket to our address format*/
    status = bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));

    /*Check if the socket was binded*/
    if (status == -1) {
        printf("Error: Unable to bind socket!\n");
        exit(-1);
    }

    /*Listen for incoming connections*/
    status = listen(server_socket, 5);

    /*Check if the socket is listening*/
    if (status == -1) {
        printf("Error: Unable to listen to socket!\n");
        exit(-1);
    }

    printf("Socket is listening on port 8080...\n");

    /*Accept incoming connections*/
    while (1) {
        client_length = sizeof(client_address);
        new_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_length);

        /*Check if the socket is accepted*/
        if (new_socket == -1) {
            printf("Error: Unable to accept socket connection!\n");
            exit(-1);
        }

        /*Extract client IP address and print message*/
        char *ip = inet_ntoa(client_address.sin_addr);
        printf("Connection accepted from: %s\n", ip);

        /*Send a welcome message to the client*/
        char *message = "Welcome to our server!\n";
        send(new_socket, message, strlen(message), 0);

        /*Receive message from the client*/
        status = recv(new_socket, buffer, sizeof(buffer), 0);

        /*Check if we have received a message*/
        if (status == -1) {
            printf("Error: Unable to receive message from client!\n");
            exit(-1);
        }

        /*Print received message to console*/
        buffer[status] = '\0';
        printf("Received message from client: %s", buffer);

        /*Send confirmation message to client*/
        char *confirmation = "Your message was received!\n";
        send(new_socket, confirmation, strlen(confirmation), 0);

        /*Close the socket*/
        close(new_socket);
    }

    return 0;
}