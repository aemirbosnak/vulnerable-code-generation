//LLAMA2-13B DATASET v1.0 Category: Game ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char *argv[]) {
    int sock1, sock2, sum;
    struct sockaddr_in server, client1, client2;
    socklen_t clilen;
    char buffer1[256], buffer2[256];

    // Create socket
    sock1 = socket(AF_INET, SOCK_STREAM, 0);
    if (sock1 < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    // Bind socket to port
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);
    if (bind(sock1, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Binding failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sock1, 3) < 0) {
        perror("Listening failed");
        exit(1);
    }

    printf("Listening for connections...\n");

    // Accept incoming connection
    clilen = sizeof(client1);
    sock2 = accept(sock1, (struct sockaddr *)&client1, &clilen);
    if (sock2 < 0) {
        perror("Accept failed");
        exit(1);
    }

    printf("Connection accepted from %s\n", inet_ntoa(client1.sin_addr));

    // Receive first number from client 1
    recv(sock2, buffer1, 256, 0);
    printf("Received first number: %s\n", buffer1);

    // Receive second number from client 2
    sock2 = accept(sock1, (struct sockaddr *)&client2, &clilen);
    if (sock2 < 0) {
        perror("Second accept failed");
        exit(1);
    }
    recv(sock2, buffer2, 256, 0);
    printf("Received second number: %s\n", buffer2);

    // Calculate and send sum to client 1
    sum = atoi(buffer1) + atoi(buffer2);
    send(sock2, "Hello, client 1! The sum is: %d\n", sum, 0);

    // Close sockets
    close(sock1);
    close(sock2);

    return 0;
}