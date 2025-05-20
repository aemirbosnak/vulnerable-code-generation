//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int socket_desc;
    struct sockaddr_in server_addr;
    char server_reply[BUFFER_SIZE];
    char user_name[BUFFER_SIZE];
    char password[BUFFER_SIZE];
    char email[BUFFER_SIZE];
    char command[BUFFER_SIZE];

    // create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc < 0) {
        perror("Cannot create socket");
        exit(EXIT_FAILURE);
    }

    // server address
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110);

    // connect to server
    if (connect(socket_desc, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Cannot connect to server");
        exit(EXIT_FAILURE);
    }

    // receive greeting message from server
    memset(server_reply, '\0', sizeof(server_reply));
    if (recv(socket_desc, server_reply, BUFFER_SIZE, 0) < 0) {
        perror("Cannot receive message from server");
        exit(EXIT_FAILURE);
    }

    printf("%s", server_reply);

    // send user name
    memset(command, '\0', sizeof(command));
    printf("USER: ");
    scanf("%s", user_name);
    sprintf(command, "USER %s\n", user_name);
    if (send(socket_desc, command, strlen(command), 0) < 0) {
        perror("Cannot send message to server");
        exit(EXIT_FAILURE);
    }

    // receive response from server
    memset(server_reply, '\0', sizeof(server_reply));
    if (recv(socket_desc, server_reply, BUFFER_SIZE, 0) < 0) {
        perror("Cannot receive message from server");
        exit(EXIT_FAILURE);
    }

    printf("%s", server_reply);

    // send password
    memset(command, '\0', sizeof(command));
    printf("PASSWORD: ");
    scanf("%s", password);
    sprintf(command, "PASS %s\n", password);
    if (send(socket_desc, command, strlen(command), 0) < 0) {
        perror("Cannot send message to server");
        exit(EXIT_FAILURE);
    }

    // receive response from server
    memset(server_reply, '\0', sizeof(server_reply));
    if (recv(socket_desc, server_reply, BUFFER_SIZE, 0) < 0) {
        perror("Cannot receive message from server");
        exit(EXIT_FAILURE);
    }

    printf("%s", server_reply);

    // list emails
    memset(command, '\0', sizeof(command));
    sprintf(command, "LIST\n");
    if (send(socket_desc, command, strlen(command), 0) < 0) {
        perror("Cannot send message to server");
        exit(EXIT_FAILURE);
    }

    // receive response from server
    memset(server_reply, '\0', sizeof(server_reply));
    if (recv(socket_desc, server_reply, BUFFER_SIZE, 0) < 0) {
        perror("Cannot receive message from server");
        exit(EXIT_FAILURE);
    }

    printf("%s", server_reply);

    // read email
    memset(command, '\0', sizeof(command));
    printf("Enter the email to view: ");
    scanf("%s", email);
    sprintf(command, "RETR %s\n", email);
    if (send(socket_desc, command, strlen(command), 0) < 0) {
        perror("Cannot send message to server");
        exit(EXIT_FAILURE);
    }

    // receive response from server
    memset(server_reply, '\0', sizeof(server_reply));
    if (recv(socket_desc, server_reply, BUFFER_SIZE, 0) < 0) {
        perror("Cannot receive message from server");
        exit(EXIT_FAILURE);
    }

    printf("%s", server_reply);

    // quit
    memset(command, '\0', sizeof(command));
    sprintf(command, "QUIT\n");
    if (send(socket_desc, command, strlen(command), 0) < 0) {
        perror("Cannot send message to server");
        exit(EXIT_FAILURE);
    }

    // receive response from server
    memset(server_reply, '\0', sizeof(server_reply));
    if (recv(socket_desc, server_reply, BUFFER_SIZE, 0) < 0) {
        perror("Cannot receive message from server");
        exit(EXIT_FAILURE);
    }

    printf("%s", server_reply);

    // close socket
    close(socket_desc);

    return 0;
}