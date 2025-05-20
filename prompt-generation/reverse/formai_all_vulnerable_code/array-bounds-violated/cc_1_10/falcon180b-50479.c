//Falcon-180B DATASET v1.0 Category: Networking ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define BACKLOG 10
#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    int listen_socket, client_socket, bytes_received;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_LINE];

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (listen_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(2);
    }

    if (listen(listen_socket, BACKLOG) == -1) {
        printf("Error listening on socket\n");
        exit(3);
    }

    printf("Server is listening on port %d\n", PORT);

    while (TRUE) {
        bytes_received = recvfrom(listen_socket, buffer, MAX_LINE, 0, NULL, NULL);

        if (bytes_received <= 0) {
            continue;
        }

        buffer[bytes_received] = '\0';
        printf("Received message: %s\n", buffer);

        sendto(listen_socket, buffer, strlen(buffer), 0, NULL, NULL);
    }

    close(listen_socket);
    return 0;
}