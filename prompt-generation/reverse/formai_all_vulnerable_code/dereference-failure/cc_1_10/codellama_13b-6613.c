//Code Llama-13B DATASET v1.0 Category: Building a POP3 Client ; Style: real-life
// A simple POP3 client example in C

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define POP3_PORT 110
#define POP3_MAX_MSG_LEN 1024

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <server> <username> <password>\n", argv[0]);
        return 1;
    }

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Connect to the POP3 server
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(POP3_PORT);
    server.sin_addr.s_addr = inet_addr(argv[1]);
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect");
        return 1;
    }

    // Send the username and password
    char *username = argv[2];
    char *password = argv[3];
    char cmd[100];
    sprintf(cmd, "USER %s\r\n", username);
    if (send(sock, cmd, strlen(cmd), 0) < 0) {
        perror("send");
        return 1;
    }
    sprintf(cmd, "PASS %s\r\n", password);
    if (send(sock, cmd, strlen(cmd), 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive the server response
    char response[POP3_MAX_MSG_LEN];
    if (recv(sock, response, POP3_MAX_MSG_LEN, 0) < 0) {
        perror("recv");
        return 1;
    }
    printf("Server response: %s\n", response);

    // Send the command to list the emails
    char cmd2[100];
    sprintf(cmd2, "LIST\r\n");
    if (send(sock, cmd2, strlen(cmd2), 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive the email list
    char email_list[POP3_MAX_MSG_LEN];
    if (recv(sock, email_list, POP3_MAX_MSG_LEN, 0) < 0) {
        perror("recv");
        return 1;
    }
    printf("Email list: %s\n", email_list);

    // Close the socket
    close(sock);

    return 0;
}