#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int clientSocket, addrLen, bytesRecv;
    struct sockaddr_in serverAddr;
    char buffer[BUFFER_SIZE];
    char fileContent[BUFFER_SIZE];

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

    recv(clientSocket, buffer, BUFFER_SIZE, 0);
    printf("Received file name: %s\n", buffer);

    FILE *file = fopen(buffer, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (!feof(file)) {
        bytesRecv = fread(fileContent, sizeof(char), BUFFER_SIZE, file);
        send(clientSocket, fileContent, bytesRecv, 0);
        memset(fileContent, 0, BUFFER_SIZE);
    }

    fclose(file);
    close(clientSocket);
    return 0;
}
