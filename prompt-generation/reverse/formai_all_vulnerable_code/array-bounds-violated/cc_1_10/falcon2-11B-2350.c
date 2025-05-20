//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int serverSocketFD, connSocketFD, n;
    struct sockaddr_in serverAddr, clientAddr;
    char buffer[BUFFER_SIZE];

    serverSocketFD = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocketFD < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);

    if (bind(serverSocketFD, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Error on binding");
        exit(EXIT_FAILURE);
    }

    listen(serverSocketFD, 5);

    while (1) {
        connSocketFD = accept(serverSocketFD, (struct sockaddr *)&clientAddr, (socklen_t*)&n);
        if (connSocketFD < 0) {
            perror("Error on accepting");
            exit(EXIT_FAILURE);
        }

        printf("Connected to client\n");
        char *ip = inet_ntoa(clientAddr.sin_addr);
        printf("Client IP: %s\n", ip);

        while ((n = recv(connSocketFD, buffer, BUFFER_SIZE - 1, 0)) > 0) {
            buffer[n] = '\0';
            printf("Received from client: %s\n", buffer);

            send(connSocketFD, buffer, n, 0);
            printf("Sent to client: %s\n", buffer);
        }

        close(connSocketFD);
    }

    close(serverSocketFD);
    return 0;
}