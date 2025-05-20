//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <ctype.h>
#include <time.h>

#define MAX_LINE 1024
#define MAX_COMMAND 64
#define MAX_RESPONSE 1024
#define POP3_PORT 110
#define DELAY_SEC 5

char *host;
int port;
int sock;
char username[MAX_LINE];
char password[MAX_LINE];
char command[MAX_COMMAND];
char response[MAX_RESPONSE];

void error(char *msg)
{
    perror(msg);
    exit(1);
}

void read_response(int timeout)
{
    int len;
    char *p;

    memset(response, 0, sizeof(response));
    p = response;
    while ((len = recv(sock, p, MAX_RESPONSE - strlen(response), 0)) > 0) {
        p += len;
        if (p - response >= MAX_RESPONSE) {
            error("Response too long");
        }
        if (*p == '\n') {
            break;
        }
    }
    if (len <= 0) {
        error("Read error");
    }
    response[strlen(response) - 1] = '\0'; // remove newline character
}

void write_command(char *cmd)
{
    int len;

    len = strlen(cmd);
    if (send(sock, cmd, len, 0)!= len) {
        error("Write error");
    }
}

int main(int argc, char *argv[])
{
    struct hostent *hostinfo;
    struct sockaddr_in server;

    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <host> <username> <password>\n", argv[0]);
        exit(1);
    }

    strcpy(host, argv[1]);
    strcpy(username, argv[2]);
    strcpy(password, argv[3]);

    if ((hostinfo = gethostbyname(host)) == NULL) {
        fprintf(stderr, "Host not found\n");
        exit(1);
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(POP3_PORT);
    memcpy(&server.sin_addr, hostinfo->h_addr, hostinfo->h_length);

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        error("Socket error");
    }

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        error("Connect error");
    }

    printf("Connected to %s\n", host);

    write_command("USER ");
    write_command(username);
    read_response(DELAY_SEC);

    write_command("PASS ");
    write_command(password);
    read_response(DELAY_SEC);

    printf("Logged in\n");

    close(sock);
    return 0;
}