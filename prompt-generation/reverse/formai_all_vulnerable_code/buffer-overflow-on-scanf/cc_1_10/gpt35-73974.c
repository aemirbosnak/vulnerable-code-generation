//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LEN 1024

void receiveMessage(int sock, char *msg) {
    // Function to receive message
    memset(msg, 0, MAX_LEN);
    recv(sock, msg, MAX_LEN, 0);
}

// Main function
int main() {
    char serverAddr[MAX_LEN], username[MAX_LEN], password[MAX_LEN], msg[MAX_LEN], command[MAX_LEN];
    int port, sock, ret;

    printf("Welcome to POP3 client!\n");
    printf("Please enter the server address: ");
    scanf("%s", serverAddr);
    printf("Please enter the port number: ");
    scanf("%d", &port);

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error creating socket!\n");
        return 1;
    }

    // Set server address
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, serverAddr, &server.sin_addr);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Error connecting to server!\n");
        close(sock);
        return 1;
    }

    // Receive greeting message from server
    receiveMessage(sock, msg);
    printf("%s\n", msg);

    // Login to server
    printf("Please enter your username: ");
    scanf("%s", username);
    sprintf(msg, "USER %s\r\n", username);
    send(sock, msg, strlen(msg), 0);
    receiveMessage(sock, msg);
    printf("%s\n", msg);

    printf("Please enter your password: ");
    scanf("%s", password);
    sprintf(msg, "PASS %s\r\n", password);
    send(sock, msg, strlen(msg), 0);
    receiveMessage(sock, msg);
    printf("%s\n", msg);

    // Retrieve message list
    send(sock, "LIST\r\n", strlen("LIST\r\n"), 0);
    receiveMessage(sock, msg);
    printf("%s\n", msg);
    sscanf(msg, "+OK %d messages", &ret); // get number of messages

    // Retrieve messages
    for (int i = 1; i <= ret; i++) {
        sprintf(command, "RETR %d\r\n",i);
        send(sock, command, strlen(command), 0);
        receiveMessage(sock, msg);
        printf("%s\n", msg);
        while (strstr(msg, "\r\n.\r\n") == NULL) {
            receiveMessage(sock, msg);
            printf("%s", msg); // print message content line by line
        }
        printf("\n"); // print extra line
    }

    // Quit connection
    send(sock, "QUIT\r\n", strlen("QUIT\r\n"), 0);
    receiveMessage(sock, msg);
    printf("%s\n", msg);

    // Close socket
    close(sock);

    printf("Thank you for using POP3 client!\n");

    return 0;
}