//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 110
#define USERNAME "user"
#define PASSWORD "password"

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char username[20] = USERNAME;
    char password[20] = PASSWORD;
    int n;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to server
    n = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (n == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Authenticate with server
    sprintf(buffer, "USER %s\r\n", username);
    send(sock, buffer, strlen(buffer), 0);
    n = recv(sock, buffer, BUFFER_SIZE, 0);
    if (n <= 0) {
        printf("Error receiving server response\n");
        exit(1);
    }
    printf("Server response: %s", buffer);

    sprintf(buffer, "PASS %s\r\n", password);
    send(sock, buffer, strlen(buffer), 0);
    n = recv(sock, buffer, BUFFER_SIZE, 0);
    if (n <= 0) {
        printf("Error receiving server response\n");
        exit(1);
    }
    printf("Server response: %s", buffer);

    // Send commands to server
    char command[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        printf("Enter command: ");
        scanf("%s", command);
        sprintf(buffer, "%s\r\n", command);
        send(sock, buffer, strlen(buffer), 0);
        n = recv(sock, buffer, BUFFER_SIZE, 0);
        if (n <= 0) {
            printf("Error receiving server response\n");
            exit(1);
        }
        printf("Server response: %s", buffer);
    }

    // Close socket
    close(sock);
    return 0;
}