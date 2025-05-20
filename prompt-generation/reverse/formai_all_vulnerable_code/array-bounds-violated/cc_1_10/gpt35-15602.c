//FormAI DATASET v1.0 Category: Networking ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int clientSocket;
    struct sockaddr_in serverAddr;
    char buffer[BUFSIZE];
    int bytesRead, bytesWritten, totalBytes = 0;

    if ((argc < 2) || (argc > 3)) {
        printf("Usage: %s server_ip [port]\n", argv[0]);
        exit(1);
    }

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(argv[1]);

    if (argc == 2) {
        serverAddr.sin_port = htons(1234);
    } else if (argc == 3) {
        serverAddr.sin_port = htons(atoi(argv[2]));
    }

    if ((clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        perror("Error: socket creation");
        exit(1);
    }

    if (connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Error: connection failed");
        exit(1);
    }

    printf("Connected to server: %s\n", inet_ntoa(serverAddr.sin_addr));

    while (1) {
        printf("> ");
        fgets(buffer, BUFSIZE, stdin);
        buffer[strlen(buffer)-1] = '\0';
        totalBytes = strlen(buffer);

        bytesWritten = send(clientSocket, buffer, totalBytes, 0);
        if (bytesWritten < 0) {
            perror("Error: send failed");
            exit(1);
        }

        printf("Waiting for response...\n");

        bytesRead = recv(clientSocket, buffer, BUFSIZE, 0);
        if (bytesRead < 0) {
            perror("Error: recv failed");
            exit(1);
        }

        printf("Response received: %s\n", buffer);
    }

    close(clientSocket);

    return 0;
}