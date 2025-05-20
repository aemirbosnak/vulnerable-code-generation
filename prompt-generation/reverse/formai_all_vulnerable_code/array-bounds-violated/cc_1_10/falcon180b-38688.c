//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define SERVER "localhost"
#define PORT 110
#define USER "user"
#define PASS "password"

int main(void) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct hostent *server = gethostbyname(SERVER);
    struct sockaddr_in addr;

    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr = *((struct in_addr*)server->h_addr);

    if (connect(sock, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    char buffer[1024];
    char username[50];
    char password[50];

    sprintf(buffer, "USER %s\r\n", USER);
    send(sock, buffer, strlen(buffer), 0);

    while (1) {
        bzero(buffer, sizeof(buffer));
        int len = recv(sock, buffer, sizeof(buffer), 0);
        if (len <= 0) {
            printf("Error receiving data\n");
            return 1;
        }
        buffer[len] = '\0';
        printf("%s", buffer);

        if (strstr(buffer, "+OK")!= NULL) {
            bzero(buffer, sizeof(buffer));
            sprintf(buffer, "PASS %s\r\n", PASS);
            send(sock, buffer, strlen(buffer), 0);
        } else if (strstr(buffer, "+OK")!= NULL) {
            bzero(buffer, sizeof(buffer));
            sprintf(buffer, "LIST\r\n");
            send(sock, buffer, strlen(buffer), 0);
        }
    }

    close(sock);
    return 0;
}