//Code Llama-13B DATASET v1.0 Category: Network Topology Mapper ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[1]));
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        return 1;
    }

    if (listen(sock, 10) < 0) {
        perror("listen");
        return 1;
    }

    printf("Listening on port %s...\n", argv[1]);

    while (1) {
        struct sockaddr_in client;
        socklen_t client_len = sizeof(client);
        int client_sock = accept(sock, (struct sockaddr *)&client, &client_len);
        if (client_sock < 0) {
            perror("accept");
            return 1;
        }

        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &client.sin_addr, client_ip, sizeof(client_ip));
        printf("Client connected from %s\n", client_ip);

        char buffer[1024];
        ssize_t bytes_received = recv(client_sock, buffer, sizeof(buffer), 0);
        if (bytes_received < 0) {
            perror("recv");
            return 1;
        }

        buffer[bytes_received] = '\0';
        printf("Received message from client: %s\n", buffer);

        char message[] = "Hello, client!";
        if (send(client_sock, message, strlen(message), 0) < 0) {
            perror("send");
            return 1;
        }

        printf("Sent message to client: %s\n", message);

        close(client_sock);
    }

    close(sock);
    return 0;
}