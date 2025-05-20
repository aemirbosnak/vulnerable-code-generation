//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>

#define PORT 5000
#define BUFSIZE 1024

int main(int argc, char* argv[]) {
    int client_sock, server_sock;
    struct sockaddr_in server_addr;
    char buf[BUFSIZE];
    int n;

    // Create a client socket
    client_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (client_sock == -1) {
        perror("socket");
        exit(1);
    }

    // Initialize the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) != 1) {
        perror("inet_pton");
        exit(1);
    }

    // Connect to the server
    if (connect(client_sock, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Send data to the server
    while (1) {
        printf("Enter a message to send to the server: ");
        fgets(buf, BUFSIZE, stdin);
        if (strcmp(buf, "exit\n") == 0) {
            break;
        }
        if (send(client_sock, buf, strlen(buf), 0) == -1) {
            perror("send");
            exit(1);
        }

        // Receive data from the server
        if ((n = recv(client_sock, buf, BUFSIZE, 0)) == -1) {
            perror("recv");
            exit(1);
        }
        buf[n] = '\0';
        printf("Received message from server: %s\n", buf);
    }

    // Close the client socket
    close(client_sock);

    return 0;
}