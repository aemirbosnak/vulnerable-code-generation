//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX 65535
#define TRUE 1
#define FALSE 0
#define BUF_SIZE 1024

struct hostent *gethostbyname(const char *name);

int main(int argc, char *argv[]) {
    int sock, port, valread, sd, maxsd, activity, i, j;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUF_SIZE];
    fd_set readfds;

    if(argc!= 3) {
        printf("Usage:./portscanner <IP Address> <Port Range>\n");
        exit(0);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if(sock == -1) {
        perror("socket failed");
        exit(0);
    }

    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (char *)&valread, sizeof(int));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(0);
    }

    for(port = 1; port <= MAX; port++) {
        if(port == atoi(argv[2]))
            continue;

        cli_addr.sin_family = AF_INET;
        cli_addr.sin_addr.s_addr = inet_addr(argv[1]);
        cli_addr.sin_port = htons(port);

        if(connect(sock, (struct sockaddr *)&cli_addr, sizeof(cli_addr)) == 0) {
            printf("Port %d: Open\n", port);
            close(sock);
        } else {
            printf("Port %d: Closed\n", port);
        }
    }

    close(sock);
    return 0;
}