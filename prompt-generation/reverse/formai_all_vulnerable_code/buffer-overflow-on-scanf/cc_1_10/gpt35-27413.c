//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(110); // POP3 port
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); // loopback address

    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    recv(sock, buffer, BUFFER_SIZE, 0); // read greeting message

    printf("%s", buffer); // print the greeting message

    // send user name
    char user_name[BUFFER_SIZE];
    printf("Enter user name: ");
    scanf("%s", user_name);

    char username_command[BUFFER_SIZE];
    sprintf(username_command, "USER %s\r\n", user_name);
    send(sock, username_command, strlen(username_command), 0);

    memset(buffer, 0, BUFFER_SIZE);
    recv(sock, buffer, BUFFER_SIZE, 0); // read response to user name
    printf("%s", buffer);

    // send password
    char password[BUFFER_SIZE];
    printf("Enter password: ");
    scanf("%s", password);

    char password_command[BUFFER_SIZE];
    sprintf(password_command, "PASS %s\r\n", password);
    send(sock, password_command, strlen(password_command), 0);

    memset(buffer, 0, BUFFER_SIZE);
    recv(sock, buffer, BUFFER_SIZE, 0); // read response to password
    printf("%s", buffer);

    // list emails
    send(sock, "LIST\r\n", 6, 0);

    memset(buffer, 0, BUFFER_SIZE);
    recv(sock, buffer, BUFFER_SIZE, 0); // read response to LIST command
    printf("%s", buffer);

    // get email
    int email_index;
    printf("Enter email index to retrieve: ");
    scanf("%d", &email_index);

    char retr_command[BUFFER_SIZE];
    sprintf(retr_command, "RETR %d\r\n", email_index);
    send(sock, retr_command, strlen(retr_command), 0);

    memset(buffer, 0, BUFFER_SIZE);
    recv(sock, buffer, BUFFER_SIZE, 0); // read response to RETR command
    printf("%s", buffer);

    close(sock);
    exit(EXIT_SUCCESS);
}