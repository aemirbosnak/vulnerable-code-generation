//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_SIZE 1024
#define PORT 110

int sock;
char buffer[MAX_SIZE];

void receive() {
    memset(buffer, 0, MAX_SIZE);
    recv(sock, buffer, MAX_SIZE, 0);
    printf("%s", buffer);
}

void login(char* username, char* password) {
    char command[MAX_SIZE];
    sprintf(command, "USER %s\r\n", username);
    send(sock, command, strlen(command), 0);
    receive();
    sprintf(command, "PASS %s\r\n", password);
    send(sock, command, strlen(command), 0);
    receive();
}

void list() {
    char command[MAX_SIZE];
    sprintf(command, "LIST\r\n");
    send(sock, command, strlen(command), 0);
    receive();
}

void retrieve(int num) {
    char command[MAX_SIZE];
    sprintf(command, "RETR %d\r\n", num);
    send(sock, command, strlen(command), 0);
    receive();
}

void quit() {
    char command[MAX_SIZE];
    sprintf(command, "QUIT\r\n");
    send(sock, command, strlen(command), 0);
    receive();
    close(sock);
}

int main() {
    struct sockaddr_in server;
    char username[MAX_SIZE], password[MAX_SIZE];
    int choice, num;

    printf("Welcome to the POP3 Client\n");
    printf("Please enter your username: ");
    scanf("%s", username);
    printf("Please enter your password: ");
    scanf("%s", password);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: Failed to create socket.\n");
        return EXIT_FAILURE;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) != 0) {
        printf("Error: Failed to connect to server.\n");
        return EXIT_FAILURE;
    }

    printf("Login Successful!\n");

    do {
        printf("\n1. List all emails\n");
        printf("2. Retrieve an email\n");
        printf("3. Quit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                list();
                break;
            case 2:
                printf("Please enter the email number you want to retrieve: ");
                scanf("%d", &num);
                retrieve(num);
                break;
            case 3:
                quit();
                break;
            default:
                printf("Invalid input, please try again.\n");
        }
    } while (choice != 3);

    printf("Logout Successful!\n");

    return EXIT_SUCCESS;
}