//Falcon-180B DATASET v1.0 Category: Firewall ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define PORT 8080

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_socket, 5);

    while(1) {
        printf("Waiting for connection...\n");
        socklen_t client_size = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_size);

        if(client_socket < 0) {
            printf("Error accepting connection\n");
            close(client_socket);
            continue;
        }

        printf("Connection accepted\n");
        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, INET_ADDRSTRLEN);
        printf("Client IP: %s\n", client_ip);

        while(1) {
            memset(buffer, 0, BUFFER_SIZE);
            int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);

            if(bytes_received <= 0) {
                printf("Client disconnected\n");
                close(client_socket);
                break;
            }

            buffer[bytes_received] = '\0';
            printf("Received message: %s", buffer);

            if(strstr(buffer, "quit")!= NULL) {
                printf("Client quit\n");
                break;
            }
        }
    }

    return 0;
}