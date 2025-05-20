//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024
#define TRUE 1
#define FALSE 0

char *server_address = "localhost";
int server_port = 110;
int client_socket;
char username[50];
char password[50];

int main(int argc, char *argv[]) {
    char buffer[BUF_SIZE];
    char command[BUF_SIZE];
    char response[BUF_SIZE];
    int bytes_received;
    int bytes_sent;
    int state = 0;

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (client_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    server_addr.sin_addr.s_addr = inet_addr(server_address);

    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (state!= 3) {
        bytes_received = recv(client_socket, buffer, BUF_SIZE, 0);

        if (bytes_received == 0) {
            printf("Connection closed\n");
            exit(0);
        }

        buffer[bytes_received] = '\0';

        if (state == 0) {
            if (strstr(buffer, "+OK")!= NULL) {
                printf("Login successful\n");
                state = 1;
            } else {
                printf("Login failed\n");
                close(client_socket);
                exit(1);
            }
        } else if (state == 1) {
            if (strstr(buffer, "+OK")!= NULL) {
                printf("Command successful\n");
            } else {
                printf("Command failed\n");
            }
        } else if (state == 2) {
            if (strstr(buffer, "+OK")!= NULL) {
                printf("Message sent\n");
            } else {
                printf("Message failed\n");
            }
        }
    }

    return 0;
}