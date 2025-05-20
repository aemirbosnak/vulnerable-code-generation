//FormAI DATASET v1.0 Category: Socket programming ; Style: happy
//Let's create a happy chat client that connects to a server and sends messages!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT_NUMBER 9000
#define MAX_MSG_SIZE 256

int main()
{
    int sock;
    struct sockaddr_in server_address;
    char message[MAX_MSG_SIZE];
    int bytes_read;

    printf("Welcome to Happy Chat Client!\n");
    printf("We are connecting you to the Happy Chat Server...\n");

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: Failed to create socket\n");
        exit(1);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT_NUMBER);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1"); //change this address if server not on local machine

    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        printf("Error: Failed to connect to server\n");
        exit(1);
    }

    printf("Connected to server!\n");

    while(1) {
        printf("> ");
        fgets(message, MAX_MSG_SIZE, stdin);
        message[strcspn(message, "\n")] = '\0'; //remove newline character

        if (send(sock, message, strlen(message), 0) == -1) {
            printf("Error: Failed to send message\n");
            exit(1);
        }

        bytes_read = recv(sock, message, MAX_MSG_SIZE-1, 0);
        if (bytes_read == -1) {
            printf("Error: Failed to receive message\n");
            exit(1);
        } else if (bytes_read == 0) {
            printf("Connection closed by server\n");
            exit(1);
        }

        message[bytes_read] = '\0'; //add null character to end of string
        printf("Server: %s\n", message);
    }

    close(sock);

    return 0;
}