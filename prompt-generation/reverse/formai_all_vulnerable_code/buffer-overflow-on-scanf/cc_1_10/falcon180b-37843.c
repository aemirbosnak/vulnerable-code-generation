//Falcon-180B DATASET v1.0 Category: Email Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define EMAIL_SERVER "localhost"
#define EMAIL_PORT "110"

char *username;
char *password;

int main() {
    printf("Welcome to the Email Client!\n");
    printf("Please enter your username: ");
    scanf("%s", username);
    printf("Please enter your password: ");
    scanf("%s", password);

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(EMAIL_PORT));
    server_addr.sin_addr.s_addr = inet_addr(EMAIL_SERVER);

    connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));

    char *login_message = "LOGIN ";
    strcat(login_message, username);
    strcat(login_message, " ");
    strcat(login_message, password);
    strcat(login_message, "\r\n");

    send(server_socket, login_message, strlen(login_message), 0);

    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(server_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    close(server_socket);
    return 0;
}