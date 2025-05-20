//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct hostent *host;
    struct sockaddr_in server_addr;
    char username[50], password[50];
    char buffer[BUFFER_SIZE];
    int n, i;

    printf("Enter POP3 server address: ");
    scanf("%s", argv[1]);

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    host = gethostbyname(argv[1]);
    if (host == NULL) {
        printf("Error resolving hostname\n");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    printf("Connected to server\n");

    send(sockfd, username, strlen(username), 0);
    send(sockfd, password, strlen(password), 0);

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        n = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (n <= 0) {
            printf("Disconnected from server\n");
            break;
        }

        printf("Server response: %s", buffer);

        for (i = 0; i < strlen(buffer); i++) {
            if (isdigit(buffer[i])) {
                printf("%d", buffer[i] - '0');
            } else if (buffer[i] == '.' || buffer[i] == '-') {
                printf("%c", buffer[i]);
            } else if (buffer[i] == '\r' || buffer[i] == '\n') {
                printf("\n");
            } else {
                printf("%c", buffer[i]);
            }
        }
    }

    close(sockfd);
    return 0;
}