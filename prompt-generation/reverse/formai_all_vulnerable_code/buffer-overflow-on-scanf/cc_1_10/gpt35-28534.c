//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: accurate
// IMAP client example program
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>

#define MAX_LEN 300

int main() {
    char buffer[MAX_LEN];
    char username[MAX_LEN];
    char password[MAX_LEN];
    char hostname[MAX_LEN];
    int sock_fd, port;
    struct sockaddr_in serv_addr;

    printf("***IMAP CLIENT***\n");
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    printf("Enter hostname: ");
    scanf("%s", hostname);
    printf("Enter port number: ");
    scanf("%d", &port);

    // create socket
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Error creating socket\n");
        return -1;
    }

    // set server address values
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    // convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, hostname, &serv_addr.sin_addr) <= 0) {
        printf("Invalid address/ Address not supported\n");
        return -1;
    }

    // connect to server
    if (connect(sock_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection Failed\n");
        return -1;
    }

    // receive and print banner greeting
    if (read(sock_fd, buffer, MAX_LEN) < 0) {
        printf("Error reading from socket\n");
        return -1;
    }
    printf("%s\n",buffer);

    // send login command
    char login_cmd[MAX_LEN];
    sprintf(login_cmd, "LOGIN %s %s\r\n", username, password);
    if (send(sock_fd, login_cmd, strlen(login_cmd), 0) < 0) {
        printf("Error sending login command\n");
        return -1;
    }

    // receive and print response for login command
    if (read(sock_fd, buffer, MAX_LEN) < 0) {
        printf("Error reading from socket\n");
        return -1;
    }
    printf("%s\n",buffer);

    // send logout command
    char logout_cmd[MAX_LEN];
    sprintf(logout_cmd, "LOGOUT\r\n");
    if (send(sock_fd, logout_cmd, strlen(logout_cmd), 0) < 0) {
        printf("Error sending logout command\n");
        return -1;
    }

    // receive and print response for logout command
    if (read(sock_fd, buffer, MAX_LEN) < 0) {
        printf("Error reading from socket\n");
        return -1;
    }
    printf("%s\n",buffer);

    // close socket
    close(sock_fd);
    return 0;
}