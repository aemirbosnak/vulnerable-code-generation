//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct hostent *host;
    struct sockaddr_in server_addr;
    char buf[BUF_SIZE];
    char user[50];
    char pass[50];
    char cmd[50];
    int n;

    printf("Enter POP3 server name: ");
    scanf("%s", user);

    printf("Enter your username: ");
    scanf("%s", pass);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    host = gethostbyname(user);
    if (host == NULL) {
        printf("Error resolving hostname\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    sprintf(cmd, "USER %s", pass);
    send(sock, cmd, strlen(cmd), 0);
    n = recv(sock, buf, BUF_SIZE, 0);
    buf[n] = '\0';
    printf("Server response: %s\n", buf);

    sprintf(cmd, "PASS %s", pass);
    send(sock, cmd, strlen(cmd), 0);
    n = recv(sock, buf, BUF_SIZE, 0);
    buf[n] = '\0';
    printf("Server response: %s\n", buf);

    close(sock);

    return 0;
}