//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    int addrlen;
    char buffer[1024];
    struct hostent *server;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "Error: No such host\n");
        exit(1);
    }

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    listen(server_fd, 5);

    while (1) {
        addrlen = sizeof(client_addr);
        client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &addrlen);
        if (client_fd < 0) {
            perror("accept");
            continue;
        }

        printf("Client connected from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            bzero(buffer, sizeof(buffer));
            if (recv(client_fd, buffer, sizeof(buffer), 0) < 0) {
                perror("recv");
                break;
            }

            printf("Received: %s\n", buffer);

            if (strcmp(buffer, "exit") == 0) {
                printf("Client requested exit\n");
                break;
            }

            if (send(client_fd, "ACK", sizeof("ACK"), 0) < 0) {
                perror("send");
                break;
            }
        }

        close(client_fd);
    }

    close(server_fd);
    return 0;
}