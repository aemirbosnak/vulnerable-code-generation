//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define MAX 100

void die(char *str) {
    perror(str);
    exit(1);
}

int main(int argc, char *argv[]) {
    int opt = TRUE;
    int sd, ret, reuse = 1;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX];
    int addrlen = sizeof(cli_addr);

    if (argc < 3) {
        printf("Usage: %s <IP Address> <Port Number>\n", argv[0]);
        exit(0);
    }

    if ((sd = socket(AF_INET, SOCK_DGRAM, 0)) == 0)
        die("socket failed");

    if (setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)))
        die("setsockopt");

    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    while (opt) {
        ret = sendto(sd, "PING", strlen("PING"), 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
        if (ret < 0)
            die("sendto");

        ret = recvfrom(sd, buffer, MAX, 0, (struct sockaddr *)&cli_addr, &addrlen);
        if (ret < 0)
            die("recvfrom");

        printf("Received from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
        if (strcmp(buffer, "PONG") == 0)
            printf("PONG received\n");
        else
            printf("Invalid response\n");
    }

    close(sd);
    return 0;
}