//FormAI DATASET v1.0 Category: Networking ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

struct sockaddr_in server_address;

int main(int argc, char const *argv[]) {

    // Creating socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (client_socket == -1) {
        printf("Socket creation failed.\n");
        return -1;
    } else {
        printf("Socket created successfully.\n");
    }

    // Setting up the server address
    memset(&server_address, '0', sizeof(server_address));

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    if(inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr)<=0) {
        printf("Invalid address\n");
        return -1;
    }

    // Connecting to the server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        printf("Connection failed.\n");
        return -1;
    } else {
        printf("Connected to the server.\n");

        char name[20];

        printf("Enter your name : ");
        scanf("%s", name);

        // Sending the name to the server
        if (send(client_socket, name, strlen(name), 0) == -1) {
            printf("Sending failed.\n");
            return -1;
        }
    }

    // Receiving a message from the server
    char server_message[200];
    if (recv(client_socket, server_message, 200, 0) == -1) {
        printf("Receiving failed.\n");
        return -1;
    } else {
        printf("Server message : %s\n", server_message);
    }

    close(client_socket);

    return 0;
}