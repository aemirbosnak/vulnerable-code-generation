#include <stdint.h>
#include <stddef.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080

void handle_request(int client_socket) {
    char buffer[1024];
    recv(client_socket, buffer, sizeof(buffer), 0);
    printf("Received request:\n%s\n", buffer);
    char *method = strtok(buffer, " ");
    char *path = strtok(NULL, " ");
    char *version = strtok(NULL, "\n");

    // HTTP headers and body can be processed here...

    // Buffered response
    char response[] = "HTTP/1.1 200 OK\r\nContent-Length: 15\r\n\r\nHello, World!";

    send(client_socket, response, strlen(response), 0);
    close(client_socket);
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_socket, 5);

    printf("Listening on port %d...\n", PORT);

    while (true) {
        int client_socket = accept(server_socket, NULL, NULL);
        handle_request(client_socket);
    }

    close(server_socket);
    return 0;
}
