//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char *argv[]) {
    /* Check if the command line parameters are correct */
    if (argc != 3) {
        printf("Usage: %s <IP address> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        printf("Error: %s Failed to create client socket\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[2]));

    if (inet_pton(AF_INET, argv[1], &server_address.sin_addr) == -1) {
        printf("Error: %s Invalid IP address format\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        printf("Error: %s Failed to connect to server\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_BUF_SIZE];
    int bytes_recv;
    while (1) {
        printf("Enter a message: ");
        fgets(buffer, MAX_BUF_SIZE, stdin);

        if (send(client_socket, buffer, strlen(buffer), 0) == -1) {
            printf("Error: %s Failed to send message to the server\n", strerror(errno));
            exit(EXIT_FAILURE);
        }

        bytes_recv = recv(client_socket, buffer, MAX_BUF_SIZE - 1, 0);
        if (bytes_recv == -1) {
            printf("Error: %s Failed to receive message from the server\n", strerror(errno));
            exit(EXIT_FAILURE);
        }

        buffer[bytes_recv] = '\0';
        printf("Server sent: %s", buffer);
    }

    close(client_socket);
    return 0;
}