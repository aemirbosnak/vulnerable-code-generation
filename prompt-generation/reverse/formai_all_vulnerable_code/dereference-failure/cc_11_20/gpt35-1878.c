//FormAI DATASET v1.0 Category: Chat server ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXCONN 10
#define MAXMSG 1024

int main(int argc, char **argv) {
    int port;
    int i, sd, client_sds[MAXCONN];
    struct sockaddr_in server_addr;
    char msg[MAXMSG];

    if(argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }
    port = atoi(argv[1]);

    if((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    memset(&(server_addr.sin_zero), '\0', 8);

    if(bind(sd, (struct sockaddr*) &server_addr, sizeof(struct sockaddr)) == -1) {
        perror("bind");
        exit(1);
    }

    if(listen(sd, MAXCONN) == -1) {
        perror("listen");
        exit(1);
    }

    printf("Listening on port %d\n", port);

    for(i = 0; i < MAXCONN; i++) {
        client_sds[i] = -1;
    }

    while(1) {
        fd_set readfds;
        int max_sd;

        FD_ZERO(&readfds);

        FD_SET(sd, &readfds);
        max_sd = sd;

        for(i = 0; i < MAXCONN; i++) {
            if(client_sds[i] > 0) {
                FD_SET(client_sds[i], &readfds);
                if(client_sds[i] > max_sd) {
                    max_sd = client_sds[i];
                }
            }
        }

        if(select(max_sd + 1, &readfds, NULL, NULL, NULL) == -1) {
            perror("select");
            exit(1);
        }

        if(FD_ISSET(sd, &readfds)) {
            int client_sd;
            struct sockaddr_in client_addr;
            socklen_t addr_len = sizeof(client_addr);
            if((client_sd = accept(sd, (struct sockaddr*) &client_addr, &addr_len)) == -1) {
                perror("accept");
                exit(1);
            }

            printf("Accepted connection from '%s:%d'\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

            for(i = 0; i < MAXCONN; i++) {
                if(client_sds[i] == -1) {
                    client_sds[i] = client_sd;
                    break;
                }
            }
        }

        for(i = 0; i < MAXCONN; i++) {
            if(client_sds[i] > 0 && FD_ISSET(client_sds[i], &readfds)) {
                int bytes_read = recv(client_sds[i], msg, MAXMSG, 0);
                if(bytes_read <= 0) {
                    printf("Connection closed\n");
                    close(client_sds[i]);
                    client_sds[i] = -1;
                    continue;
                }
                msg[bytes_read] = '\0';
                printf("Received message from '%d': %s\n", client_sds[i], msg);
                send(client_sds[i], msg, strlen(msg), 0);
            }
        }
    }
    return 0;
}