//Falcon-180B DATASET v1.0 Category: Email Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX 1000
#define PORT 8080
#define SERVER "localhost"

char username[50], password[50];
char message[MAX];
char *token;
int sock;

void main() {
    int n;
    char ch;
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Socket creation failed\n");
        exit(0);
    }

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &serv_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection failed\n");
        exit(0);
    }

    printf("Enter message: ");
    fgets(message, MAX, stdin);
    message[strcspn(message, "\r")] = '\0';

    send(sock, username, strlen(username), 0);
    send(sock, password, strlen(password), 0);
    send(sock, message, strlen(message), 0);

    close(sock);
}