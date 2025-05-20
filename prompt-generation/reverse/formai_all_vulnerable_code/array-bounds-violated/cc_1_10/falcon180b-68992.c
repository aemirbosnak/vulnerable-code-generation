//Falcon-180B DATASET v1.0 Category: Email Client ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX 1000
#define SERVER "127.0.0.1"
#define PORT 8080

char username[20];
char password[20];
int sock;
struct sockaddr_in serv_addr;

void main() {
    char buffer[MAX];
    int n;

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0) {
        printf("Error in socket creation");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(SERVER);
    serv_addr.sin_port = htons(PORT);

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error in connection");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        memset(buffer, 0, MAX);
        fgets(buffer, MAX, stdin);
        send(sock, buffer, strlen(buffer), 0);
        n = recv(sock, buffer, MAX, 0);
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sock);
}