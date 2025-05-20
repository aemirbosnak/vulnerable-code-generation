//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <fcntl.h>
#include <signal.h>

#define MAX 1024
#define TRUE 1
#define FALSE 0
#define PORT 25
#define OK "OK"
#define ERR "ERR"

typedef struct {
    char *host;
    int port;
    int sock;
} SMTP;

int main(int argc, char *argv[]) {
    SMTP smtp = {0};
    char buffer[MAX];
    int n;

    smtp.host = argv[1];
    smtp.port = PORT;

    smtp.sock = socket(AF_INET, SOCK_STREAM, 0);

    if (smtp.sock == -1) {
        printf("Error: socket() failed\n");
        exit(1);
    }

    if (connect(smtp.sock, (struct sockaddr *)&smtp.host, sizeof(smtp.host)) == -1) {
        printf("Error: connect() failed\n");
        exit(1);
    }

    printf("Connected to %s:%d\n", smtp.host, smtp.port);

    while (1) {
        printf("SMTP> ");
        fgets(buffer, MAX, stdin);
        send(smtp.sock, buffer, strlen(buffer), 0);

        n = recv(smtp.sock, buffer, MAX, 0);
        buffer[n] = '\0';

        printf("SMTP< %s\n", buffer);

        if (strstr(buffer, OK)!= NULL) {
            printf("Message sent successfully\n");
            break;
        } else if (strstr(buffer, ERR)!= NULL) {
            printf("Error: %s\n", buffer);
            break;
        }
    }

    close(smtp.sock);
    return 0;
}