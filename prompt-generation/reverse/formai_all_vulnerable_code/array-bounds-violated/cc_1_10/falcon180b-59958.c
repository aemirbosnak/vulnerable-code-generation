//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define SERVER "localhost"
#define PORT 110
#define USER "your_username"
#define PASS "your_password"

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char message[BUFFER_SIZE];
    char *user = USER;
    char *pass = PASS;
    int n;
    time_t now;

    if (argc!= 1) {
        printf("Usage: %s\n", argv[0]);
        return 1;
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, SERVER, &server_addr.sin_addr) <= 0) {
        printf("Error converting server address\n");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    printf("Connected to server\n");

    now = time(NULL);
    snprintf(message, BUFFER_SIZE, "USER %s\r\n", user);
    send(sockfd, message, strlen(message), 0);
    snprintf(message, BUFFER_SIZE, "PASS %s\r\n", pass);
    send(sockfd, message, strlen(message), 0);

    while (1) {
        memset(message, 0, BUFFER_SIZE);
        n = recv(sockfd, message, BUFFER_SIZE, 0);
        if (n <= 0) {
            printf("Error receiving message\n");
            break;
        }
        message[n] = '\0';
        printf("Received message: %s", message);
    }

    close(sockfd);
    return 0;
}