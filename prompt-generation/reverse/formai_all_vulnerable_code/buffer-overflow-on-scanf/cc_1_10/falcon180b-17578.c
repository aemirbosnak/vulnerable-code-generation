//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 110
#define SERVER_ADDRESS "localhost"

int main(int argc, char *argv[]) {
    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char username[50];
    char password[50];
    char command[100];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (client_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);

    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    sprintf(command, "USER %s\r\n", username);
    send(client_socket, command, strlen(command), 0);

    sprintf(command, "PASS %s\r\n", password);
    send(client_socket, command, strlen(command), 0);

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            printf("Error receiving data\n");
            exit(1);
        }

        printf("%s", buffer);

        if (strstr(buffer, "OK")!= NULL) {
            break;
        }
    }

    close(client_socket);

    return 0;
}