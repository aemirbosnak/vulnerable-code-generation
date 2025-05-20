//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[]) {
    int sd, new_sd, addrlen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    sd = socket(AF_INET, SOCK_STREAM, 0);
    if (sd == -1) {
        perror("socket failed");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(atoi(argv[1]));

    if (bind(sd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(sd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    while (TRUE) {
        addrlen = sizeof(cli_addr);
        new_sd = accept(sd, (struct sockaddr *)&cli_addr, &addrlen);
        if (new_sd < 0) {
            perror("accept");
            exit(1);
        }

        printf("Connection from: %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        while (TRUE) {
            bzero(buffer, BUFFER_SIZE);
            if (recv(new_sd, buffer, BUFFER_SIZE, 0) <= 0) {
                perror("recv");
                exit(1);
            }

            printf("Received message: %s\n", buffer);

            if (strcmp(buffer, "bye") == 0) {
                break;
            }

            send(new_sd, buffer, strlen(buffer), 0);
        }

        close(new_sd);
    }

    close(sd);

    return 0;
}