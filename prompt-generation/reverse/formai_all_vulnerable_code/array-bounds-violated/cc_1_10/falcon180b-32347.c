//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

int main() {
    int sd, new_sd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1025];
    int n;

    sd = socket(AF_INET, SOCK_STREAM, 0);

    if (sd == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    bzero(&serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(8080);

    if (bind(sd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    listen(sd, 5);

    while (1) {
        new_sd = accept(sd, (struct sockaddr *)&cli_addr, sizeof(cli_addr));

        if (new_sd < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        send(new_sd, "Welcome to the server\n", strlen("Welcome to the server\n"), 0);

        while ((n = recv(new_sd, buffer, sizeof(buffer), 0)) > 0) {
            buffer[n] = '\0';
            printf("Received: %s", buffer);
        }

        close(new_sd);
    }

    close(sd);

    return 0;
}