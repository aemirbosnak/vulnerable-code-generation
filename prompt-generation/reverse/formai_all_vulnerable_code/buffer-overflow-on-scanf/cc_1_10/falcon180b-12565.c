//Falcon-180B DATASET v1.0 Category: Email Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define MAX 1000

int main(int argc, char *argv[]) {
    char host[MAX];
    char user[MAX];
    char pass[MAX];
    int port = 110;
    int sock;
    struct hostent *he;
    struct sockaddr_in serv_addr;

    printf("Enter POP3 Server Hostname: ");
    scanf("%s", host);

    printf("Enter Username: ");
    scanf("%s", user);

    printf("Enter Password: ");
    scanf("%s", pass);

    if ((he = gethostbyname(host)) == NULL) {
        printf("No such host\n");
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0) {
        printf("socket failed\n");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr = *((struct in_addr *) he->h_addr);

    if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("connect failed\n");
        exit(1);
    }

    char auth[50];
    sprintf(auth, "USER %s", user);
    send(sock, auth, strlen(auth), 0);

    char pass_auth[50];
    sprintf(pass_auth, "PASS %s", pass);
    send(sock, pass_auth, strlen(pass_auth), 0);

    char response[MAX];
    memset(response, 0, sizeof(response));

    while (1) {
        if (recv(sock, response, MAX, 0) < 0) {
            printf("recv failed\n");
            exit(1);
        }

        printf("%s", response);
    }

    close(sock);

    return 0;
}