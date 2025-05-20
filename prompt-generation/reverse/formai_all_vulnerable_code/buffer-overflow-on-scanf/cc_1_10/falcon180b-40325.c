//Falcon-180B DATASET v1.0 Category: Email Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define PORT "110"
#define BUFFER_SIZE 1024
#define EMAIL_ADDRESS_MAX_LENGTH 50
#define PASSWORD_MAX_LENGTH 20
#define SUBJECT_MAX_LENGTH 100
#define BODY_MAX_LENGTH 1000

struct Email {
    char from[EMAIL_ADDRESS_MAX_LENGTH];
    char to[EMAIL_ADDRESS_MAX_LENGTH];
    char subject[SUBJECT_MAX_LENGTH];
    char body[BODY_MAX_LENGTH];
};

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(PORT));
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);
    connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr));

    char username[EMAIL_ADDRESS_MAX_LENGTH];
    char password[PASSWORD_MAX_LENGTH];
    printf("Enter your email address: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    char login_command[100];
    sprintf(login_command, "LOGIN %s %s\r\n", username, password);
    send(sock, login_command, strlen(login_command), 0);

    char response[BUFFER_SIZE];
    memset(response, 0, BUFFER_SIZE);
    recv(sock, response, BUFFER_SIZE, 0);
    printf("%s\n", response);

    char list_command[50];
    sprintf(list_command, "LIST\r\n");
    send(sock, list_command, strlen(list_command), 0);

    memset(response, 0, BUFFER_SIZE);
    recv(sock, response, BUFFER_SIZE, 0);
    printf("%s\n", response);

    close(sock);
    return 0;
}