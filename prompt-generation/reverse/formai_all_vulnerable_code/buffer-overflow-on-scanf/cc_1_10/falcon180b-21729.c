//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024
#define POP3_PORT 110
#define CRLF "\r\n"

int main(int argc, char** argv)
{
    int sock = -1;
    struct sockaddr_in server_addr;
    char username[64], password[64], response[BUF_SIZE];
    int ret, len;
    char* token;

    printf("POP3 Client\n");

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1)
    {
        printf("socket error: %s\n", strerror(errno));
        return -1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);

    printf("Enter POP3 Server IP: ");
    scanf("%s", inet_ntoa(server_addr.sin_addr));

    printf("Enter Username: ");
    scanf("%s", username);

    printf("Enter Password: ");
    scanf("%s", password);

    ret = connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if(ret == -1)
    {
        printf("connect error: %s\n", strerror(errno));
        return -1;
    }

    printf("Connected to POP3 Server\n");

    send(sock, "USER ", 5, 0);
    ret = recv(sock, response, BUF_SIZE, 0);
    if(ret <= 0)
    {
        printf("recv error: %s\n", strerror(errno));
        return -1;
    }

    printf("Server Response: %s\n", response);

    send(sock, "PASS ", 5, 0);
    send(sock, password, strlen(password), 0);
    send(sock, CRLF, 2, 0);
    ret = recv(sock, response, BUF_SIZE, 0);
    if(ret <= 0)
    {
        printf("recv error: %s\n", strerror(errno));
        return -1;
    }

    printf("Server Response: %s\n", response);

    send(sock, "LIST\r\n", 6, 0);
    ret = recv(sock, response, BUF_SIZE, 0);
    if(ret <= 0)
    {
        printf("recv error: %s\n", strerror(errno));
        return -1;
    }

    printf("Server Response: %s\n", response);

    token = strtok(response, "\r\n");
    while(token!= NULL)
    {
        printf("Message #: %s\n", token);
        token = strtok(NULL, "\r\n");
    }

    close(sock);

    return 0;
}