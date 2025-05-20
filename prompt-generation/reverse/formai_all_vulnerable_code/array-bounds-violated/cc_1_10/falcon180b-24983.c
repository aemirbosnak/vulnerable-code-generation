//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 110
#define USERNAME "your_username"
#define PASSWORD "your_password"

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char username[20] = USERNAME;
    char password[20] = PASSWORD;
    char response[BUFFER_SIZE];
    int n;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    send(sock, username, strlen(username), 0);
    send(sock, password, strlen(password), 0);

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        n = recv(sock, buffer, BUFFER_SIZE, 0);
        if (n <= 0) {
            printf("Error receiving data\n");
            exit(1);
        }

        printf("Received data: %s\n", buffer);

        // Check for end of message
        if (buffer[n-1] == '.' && buffer[n-2] == '.' && buffer[n-3] == '.') {
            printf("End of message\n");
            break;
        }
    }

    close(sock);
    return 0;
}