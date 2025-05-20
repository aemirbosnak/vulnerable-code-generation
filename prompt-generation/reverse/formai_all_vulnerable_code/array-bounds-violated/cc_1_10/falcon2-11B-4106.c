//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int server_fd, client_fd, valread;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket");
        return 1;
    }

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        return 1;
    }

    if (listen(server_fd, 5) == -1) {
        perror("listen");
        return 1;
    }

    while (1) {
        client_fd = accept(server_fd, (struct sockaddr *) &client_addr, (socklen_t *) &valread);
        if (client_fd == -1) {
            perror("accept");
            continue;
        }

        printf("New connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        char buffer[256];
        bzero(buffer, 256);

        while ((valread = recv(client_fd, buffer, 256, 0)) > 0) {
            buffer[valread] = '\0';
            printf("Received: %s\n", buffer);
        }

        close(client_fd);
    }

    close(server_fd);
    return 0;
}