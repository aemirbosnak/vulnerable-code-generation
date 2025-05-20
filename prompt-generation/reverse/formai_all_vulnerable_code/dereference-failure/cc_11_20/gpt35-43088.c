//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int port = 110; // default POP3 port

    // check if user provided a custom port number
    if (argc == 2) {
        port = atoi(argv[1]); // convert port number to integer
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Error creating socket");
        return 1;
    }

    // connect to localhost on specified port
    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("Error connecting to server");
        return 1;
    }

    // receive greeting message from server
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sock, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving message from server");
        return 1;
    }

    printf("%s\n", buffer);

    // send user credentials
    char username[100], password[100];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    char command[100];
    sprintf(command, "USER %s\r\n", username);
    if (send(sock, command, strlen(command), 0) < 0) {
        perror("Error sending command to server");
        return 1;
    }

    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sock, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving message from server");
        return 1;
    }

    printf("%s\n", buffer);

    sprintf(command, "PASS %s\r\n", password);
    if (send(sock, command, strlen(command), 0) < 0) {
        perror("Error sending command to server");
        return 1;
    }

    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sock, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving message from server");
        return 1;
    }

    printf("%s\n", buffer);

    // list all emails
    sprintf(command, "LIST\r\n");
    if (send(sock, command, strlen(command), 0) < 0) {
        perror("Error sending command to server");
        return 1;
    }

    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sock, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving message from server");
        return 1;
    }

    printf("%s\n", buffer);

    // select an email to read
    int email_number;
    printf("Enter email number to read: ");
    scanf("%d", &email_number);

    sprintf(command, "RETR %d\r\n", email_number);
    if (send(sock, command, strlen(command), 0) < 0) {
        perror("Error sending command to server");
        return 1;
    }

    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sock, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving message from server");
        return 1;
    }

    printf("%s\n", buffer);

    // quit session
    sprintf(command, "QUIT\r\n");
    if (send(sock, command, strlen(command), 0) < 0) {
        perror("Error sending command to server");
        return 1;
    }

    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sock, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving message from server");
        return 1;
    }

    printf("%s\n", buffer);

    close(sock);

    return 0;
}