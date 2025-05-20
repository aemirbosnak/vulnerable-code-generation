//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define MAX_MESSAGE_SIZE 1024

int main(int argc, char *argv[]) {
    int sock, client_sock;
    struct sockaddr_in server, client;
    socklen_t client_len = sizeof(client);
    char buffer[MAX_MESSAGE_SIZE];
    int i, j, n = 0;

    // Create the server socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(1);
    }

    // Set up the server address
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind the server socket
    if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sock, MAX_CLIENTS) < 0) {
        perror("listen failed");
        exit(1);
    }

    // Accept an incoming connection
    client_sock = accept(sock, (struct sockaddr *)&client, &client_len);
    if (client_sock < 0) {
        perror("accept failed");
        exit(1);
    }

    // Sort the client's message
    printf("Client: %s\n", inet_ntoa(client.sin_addr));
    n = recv(client_sock, buffer, MAX_MESSAGE_SIZE, 0);
    if (n < 0) {
        perror("recv failed");
        exit(1);
    }
    buffer[n] = '\0';
    printf("Received message: %s\n", buffer);

    // Send the sorted message back to the client
    qsort(buffer, n, 1, strcmp);
    send(client_sock, buffer, n, 0);

    // Close the client socket
    close(client_sock);

    // Loop to handle multiple clients
    while (1) {
        // Accept an incoming connection
        client_sock = accept(sock, (struct sockaddr *)&client, &client_len);
        if (client_sock < 0) {
            perror("accept failed");
            exit(1);
        }

        // Sort the client's message
        printf("Client: %s\n", inet_ntoa(client.sin_addr));
        n = recv(client_sock, buffer, MAX_MESSAGE_SIZE, 0);
        if (n < 0) {
            perror("recv failed");
            exit(1);
        }
        buffer[n] = '\0';
        printf("Received message: %s\n", buffer);

        // Send the sorted message back to the client
        qsort(buffer, n, 1, strcmp);
        send(client_sock, buffer, n, 0);

        // Close the client socket
        close(client_sock);
    }

    return 0;
}