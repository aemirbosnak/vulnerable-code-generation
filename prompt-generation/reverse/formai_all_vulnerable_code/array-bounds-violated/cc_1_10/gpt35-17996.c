//FormAI DATASET v1.0 Category: Email Client ; Style: complex
/*
 * C Email Client Example Program
 * Author: [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_MSG_LEN 1024
#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8888

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error: failed to create socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        perror("Error: failed to convert IP address");
        exit(EXIT_FAILURE);
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error: failed to connect to server");
        exit(EXIT_FAILURE);
    }

    while (1) {
        char msg[MAX_MSG_LEN];
        printf("Enter email message (type 'exit' to quit): ");
        fgets(msg, MAX_MSG_LEN, stdin);
        size_t len = strlen(msg);
        msg[len - 1] = '\0'; // remove new line character

        if (strcmp(msg, "exit") == 0) {
            break;
        }

        if (send(sock, msg, len, 0) < 0) {
            perror("Error: failed to send message");
            exit(EXIT_FAILURE);
        }

        char buffer[MAX_MSG_LEN];
        if (recv(sock, buffer, MAX_MSG_LEN, 0) < 0) {
            perror("Error: failed to receive message");
            exit(EXIT_FAILURE);
        }

        printf("Server response: %s\n", buffer);
    }

    close(sock);
    return 0;
}