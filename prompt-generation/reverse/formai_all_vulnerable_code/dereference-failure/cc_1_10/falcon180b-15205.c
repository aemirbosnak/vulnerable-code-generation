//Falcon-180B DATASET v1.0 Category: Networking ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 8080
#define BACKLOG 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int listen_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    int addrlen = sizeof(client_addr);
    int bytes_received;
    time_t current_time;

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        perror("socket failed");
        exit(errno);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind failed");
        exit(errno);
    }

    if (listen(listen_socket, BACKLOG) == -1) {
        perror("listen");
        exit(errno);
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        current_time = time(NULL);
        char timestamp[30];
        strftime(timestamp, 30, "[%Y-%m-%d %H:%M:%S] ", localtime(&current_time));

        bytes_received = recv(listen_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            continue;
        }

        buffer[bytes_received] = '\0';
        printf("%sClient: %s", timestamp, buffer);

        send(listen_socket, buffer, bytes_received, 0);
    }

    close(listen_socket);
    return 0;
}