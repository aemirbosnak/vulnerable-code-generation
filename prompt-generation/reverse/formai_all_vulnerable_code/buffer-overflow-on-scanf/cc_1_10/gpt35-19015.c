//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    
    printf("Welcome to TCP/IP programming in C\n");
    printf("Please input the IP address you wish to connect to: ");

    char server_ip[16];
    scanf("%s", server_ip);

    printf("Please input the port you wish to connect to: ");

    int server_port;
    scanf("%d", &server_port);

    printf("\nConnecting to %s:%d ... \n", server_ip, server_port);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(server_ip);
    server_address.sin_port = htons(server_port);

    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Failed to create socket");
        return -1;
    }

    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection failed");
        return -1;
    }

    printf("\nConnection successful!\n");
    
    char message[256];
    char response[256];

    while (1) {
        printf("\nPlease input the message you wish to send to the server: ");
        fgets(message, 256, stdin);
        message[strcspn(message, "\n")] = '\0';

        if (send(client_socket, message, strlen(message), 0) < 0) {
            perror("Failed to send message");
            break;
        }

        printf("\nMessage sent successfully!\n");

        if (recv(client_socket, response, sizeof(response), 0) < 0) {
            perror("Failed to receive response");
            break;
        }

        printf("\nServer response: %s\n", response);
    }

    close(client_socket);
    printf("\nProgram terminated\n");

    return 0;
}