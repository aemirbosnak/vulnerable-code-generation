//Code Llama-13B DATASET v1.0 Category: Building a FTP Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define FTP_PORT 21
#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in serv_addr;
    char buf[BUFSIZE];
    int n;

    if (argc != 2) {
        fprintf(stderr, "usage: %s <host>\n", argv[0]);
        exit(1);
    }

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket() failed");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(FTP_PORT);
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect() failed");
        exit(1);
    }

    printf("Connected to %s\n", argv[1]);

    while (fgets(buf, sizeof(buf), stdin) != NULL) {
        if (buf[strlen(buf) - 1] == '\n')
            buf[strlen(buf) - 1] = '\0';
        if (send(sock, buf, strlen(buf), 0) < 0) {
            perror("send() failed");
            exit(1);
        }
        if (recv(sock, buf, sizeof(buf), 0) < 0) {
            perror("recv() failed");
            exit(1);
        }
        printf("%s\n", buf);
    }

    close(sock);
    return 0;
}