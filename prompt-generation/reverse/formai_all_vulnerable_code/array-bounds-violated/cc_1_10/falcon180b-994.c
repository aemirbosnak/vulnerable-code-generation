//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BACKLOG 10

void error_handling(char *message) {
    perror(message);
    exit(1);
}

int main() {
    int master_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    int addrlen = sizeof(client_addr);

    master_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (master_socket == -1) {
        error_handling("socket failed");
    }

    if (setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        error_handling("setsockopt");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(master_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error_handling("bind failed");
    }

    if (listen(master_socket, BACKLOG) < 0) {
        error_handling("listen");
    }

    while (1) {
        client_socket = accept(master_socket, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen);

        if (client_socket < 0) {
            error_handling("accept");
        }

        printf("New connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        char buffer[1024];
        int bytes_received;

        while ((bytes_received = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
            buffer[bytes_received] = '\0';
            printf("Received message: %s\n", buffer);

            if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
                error_handling("send");
            }
        }

        close(client_socket);
    }

    close(master_socket);

    return 0;
}