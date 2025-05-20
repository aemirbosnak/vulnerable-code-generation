//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>

#define MAX 1000
#define PORT "80"
#define SA struct sockaddr
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define CLOSE_SOCKET(s) close(s)
#define RECV(s,buf,len) recv(s,buf,len,0)
#define SEND(s,buf,len) send(s,buf,len,0)
#define GET_LAST_ERROR() strerror(errno)

int main(int argc, char *argv[])
{
    int sock, portno, clilen, i, valread, sd;
    char buffer[MAX];
    char *host;
    struct hostent *server;
    struct sockaddr_in serv_addr;
    int opt = 1;

    printf("Enter the hostname: ");
    scanf("%s", host);

    if ( (server = gethostbyname(host)) == NULL ) {
        printf("No such host\n");
        exit(0);
    }

    if ( server->h_addrtype == AF_INET ) {
        printf("IP Address: %s\n", inet_ntoa(*(struct in_addr *)server->h_addr));
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if ( sock == INVALID_SOCKET ) {
        printf("socket failed\n");
        exit(0);
    }

    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(inet_ntoa(*(struct in_addr *)server->h_addr));
    serv_addr.sin_port = htons(atoi(PORT));

    if ( connect(sock,(SA *)&serv_addr,sizeof(serv_addr)) < 0 ) {
        printf("connect failed\n");
        exit(0);
    }

    printf("Connected to %s\n", host);

    while(1)
    {
        memset(buffer, 0, MAX);
        valread = RECV(sock, buffer, MAX);
        if ( valread <= 0 )
            break;
        printf("%s", buffer);
    }

    CLOSE_SOCKET(sock);
    return 0;
}