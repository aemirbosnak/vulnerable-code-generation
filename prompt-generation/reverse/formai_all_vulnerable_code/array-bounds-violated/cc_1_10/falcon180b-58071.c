//Falcon-180B DATASET v1.0 Category: Firewall ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define PORT 8080

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(2);
    }

    if (listen(sock, 5) == -1) {
        printf("Error listening on socket\n");
        exit(3);
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        int client_sock = accept(sock, NULL, NULL);
        if (client_sock == -1) {
            printf("Error accepting connection\n");
            exit(4);
        }

        char buffer[BUFFER_SIZE];
        memset(buffer, 0, BUFFER_SIZE);

        int bytes_received = recv(client_sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received == -1) {
            printf("Error receiving data\n");
            exit(5);
        }

        buffer[bytes_received] = '\0';
        printf("Received data: %s\n", buffer);

        char response[BUFFER_SIZE];
        snprintf(response, BUFFER_SIZE, "You sent: %s", buffer);

        send(client_sock, response, strlen(response), 0);
        close(client_sock);
    }

    close(sock);
    return 0;
}