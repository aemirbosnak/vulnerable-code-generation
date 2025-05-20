//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/time.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define POP3_PORT 110
#define USERNAME "your_username"
#define PASSWORD "your_password"

int main(int argc, char *argv[]) {
    int sock, ret;
    struct sockaddr_in server_addr;
    int addrlen = sizeof(server_addr);
    char buffer[BUFFER_SIZE];
    char username[20];
    char password[20];
    char command[50];
    int status;

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    inet_pton(AF_INET, "pop.gmail.com", &server_addr.sin_addr);

    ret = connect(sock, (struct sockaddr *)&server_addr, addrlen);
    if (ret == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    sprintf(command, "USER %s\r\n", username);
    send(sock, command, strlen(command), 0);

    ret = recv(sock, buffer, BUFFER_SIZE, 0);
    if (ret <= 0) {
        printf("Error receiving data\n");
        exit(1);
    }

    printf("Received response: %s\n", buffer);

    sprintf(command, "PASS %s\r\n", password);
    send(sock, command, strlen(command), 0);

    ret = recv(sock, buffer, BUFFER_SIZE, 0);
    if (ret <= 0) {
        printf("Error receiving data\n");
        exit(1);
    }

    printf("Received response: %s\n", buffer);

    sprintf(command, "STAT\r\n");
    send(sock, command, strlen(command), 0);

    ret = recv(sock, buffer, BUFFER_SIZE, 0);
    if (ret <= 0) {
        printf("Error receiving data\n");
        exit(1);
    }

    printf("Received response: %s\n", buffer);

    close(sock);

    return 0;
}