//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

void error_handling(char* message) {
    perror(message);
    exit(1);
}

int main(int argc, char* argv[]) {
    int server_socket, client_socket, bytes_received;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port_number>\n", argv[0]);
        exit(1);
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        error_handling("socket failed");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        error_handling("bind failed");
    }

    if (listen(server_socket, 5) == -1) {
        error_handling("listen failed");
    }

    printf("Server is listening on port %s...\n", argv[1]);

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, sizeof(client_addr));
        if (client_socket == -1) {
            error_handling("accept failed");
        }

        printf("Client connected with IP address: %s and port: %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);

            if (bytes_received <= 0) {
                break;
            }

            printf("Received message: %s\n", buffer);

            if (send(client_socket, buffer, strlen(buffer), 0)!= strlen(buffer)) {
                error_handling("send failed");
            }
        }

        close(client_socket);
    }

    close(server_socket);
    return 0;
}