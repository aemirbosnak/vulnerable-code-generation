//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_COMMAND_LENGTH 2048
#define MAX_RESPONSE_LENGTH 4096

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // create socket
    int client_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (client_sock < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // connect to server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    if (connect(client_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // receive server's greeting message
    char response[MAX_RESPONSE_LENGTH] = {0};
    if (recv(client_sock, response, MAX_RESPONSE_LENGTH, 0) < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }
    printf("%s", response);

    // send user's credentials
    char user_command[MAX_COMMAND_LENGTH] = {0};
    printf("Username: ");
    fgets(user_command, MAX_COMMAND_LENGTH, stdin);
    char* newline_pos = strchr(user_command, '\n');
    if (newline_pos) {
        *newline_pos = '\0';
    }
    strcat(user_command, "\r\n");
    if (send(client_sock, user_command, strlen(user_command), 0) < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    // receive server's response to user's credentials
    if (recv(client_sock, response, MAX_RESPONSE_LENGTH, 0) < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }
    printf("%s", response);

    // send password
    char pass_command[MAX_COMMAND_LENGTH] = {0};
    printf("Password: ");
    fgets(pass_command, MAX_COMMAND_LENGTH, stdin);
    newline_pos = strchr(pass_command, '\n');
    if (newline_pos) {
        *newline_pos = '\0';
    }
    strcat(pass_command, "\r\n");
    if (send(client_sock, pass_command, strlen(pass_command), 0) < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    // receive server's response to password
    if (recv(client_sock, response, MAX_RESPONSE_LENGTH, 0) < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }
    printf("%s", response);

    // send list command
    char list_command[MAX_COMMAND_LENGTH] = "LIST\r\n";
    if (send(client_sock, list_command, strlen(list_command), 0) < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    // receive list of emails from server
    if (recv(client_sock, response, MAX_RESPONSE_LENGTH, 0) < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }
    printf("%s", response);

    // send quit command
    char quit_command[MAX_COMMAND_LENGTH] = "QUIT\r\n";
    if (send(client_sock, quit_command, strlen(quit_command), 0) < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    // receive server's goodbye message
    if (recv(client_sock, response, MAX_RESPONSE_LENGTH, 0) < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }
    printf("%s", response);

    // close socket
    if (close(client_sock) < 0) {
        perror("close failed");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}