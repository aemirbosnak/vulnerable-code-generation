//Code Llama-13B DATASET v1.0 Category: Socket programming ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sock, client_sock, port_num, n;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024];

    if (argc < 2) {
        printf("Usage: %s <port_number>\n", argv[0]);
        return 1;
    }

    port_num = atoi(argv[1]);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port_num);

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        return 1;
    }

    if (listen(sock, 3) < 0) {
        perror("Listen failed");
        return 1;
    }

    printf("Server listening on port %d\n", port_num);

    client_sock = accept(sock, (struct sockaddr *)&client_addr, &n);
    if (client_sock < 0) {
        perror("Accept failed");
        return 1;
    }

    printf("Client connected with IP address %s and port %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    while (1) {
        n = read(client_sock, buffer, 1024);
        if (n < 0) {
            perror("Read failed");
            return 1;
        }
        if (n == 0) {
            printf("Client disconnected\n");
            break;
        }
        printf("Client sent: %s\n", buffer);
        n = write(client_sock, buffer, n);
        if (n < 0) {
            perror("Write failed");
            return 1;
        }
    }

    return 0;
}