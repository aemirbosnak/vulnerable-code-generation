//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX 1000
#define PORT 8080
#define SA struct sockaddr

void die(const char *s) {
    perror(s);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    int opt = 1;
    int sd, addrlen = sizeof(struct sockaddr);
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX];

    if(argc < 3) {
        fprintf(stderr,"usage : %s <host> <port>\n", argv[0]);
        exit(1);
    }

    sd = socket(AF_INET, SOCK_STREAM, 0);
    if(sd == -1) {
        die("socket failed");
    }

    if(setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt))) {
        die("setsockopt");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if(connect(sd, (SA*)&serv_addr, addrlen) < 0) {
        die("connect");
    }

    while(1) {
        memset(buffer, 0, MAX);
        fgets(buffer, MAX, stdin);
        send(sd, buffer, strlen(buffer), 0);

        int len = recv(sd, buffer, MAX, 0);
        if(len <= 0) {
            break;
        }
        buffer[len] = '\0';
        printf("%s", buffer);
    }

    close(sd);
    return 0;
}