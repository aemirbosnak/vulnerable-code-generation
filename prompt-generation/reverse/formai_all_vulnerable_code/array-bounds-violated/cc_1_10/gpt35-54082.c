//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

/* Define constants */
#define SERVER_ADDR "127.0.0.1"
#define SERVER_PORT 9000
#define MAX_MSG_LENGTH 1024

/* Main function */
int main() {
    int sock_fd, msg_len;
    char msg[MAX_MSG_LENGTH];
    struct sockaddr_in server_addr;

    /* Create socket */
    sock_fd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sock_fd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    /* Configure server address */
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDR);
    memset(server_addr.sin_zero, '\0', sizeof server_addr.sin_zero);

    /* Connect to server */
    if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof server_addr) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    /* Send message to server */
    printf("Enter message to send to server: ");
    fgets(msg, MAX_MSG_LENGTH, stdin);
    msg_len = strlen(msg);
    msg[msg_len - 1] = '\0';
    if (send(sock_fd, msg, strlen(msg), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    /* Receive message from server */
    if (recv(sock_fd, msg, MAX_MSG_LENGTH, 0) < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    /* Print server response */
    printf("Server response: %s\n", msg);

    /* Close socket */
    close(sock_fd);

    return 0;
}