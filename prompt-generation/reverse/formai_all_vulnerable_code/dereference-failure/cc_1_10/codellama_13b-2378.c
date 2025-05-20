//Code Llama-13B DATASET v1.0 Category: Networking ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
    int sock, conn;
    struct sockaddr_in server, client;
    char *server_ip, *server_port, *client_ip, *client_port;
    char *message = "Hello, world!";
    int message_length = strlen(message);

    // Parse command line arguments
    if (argc != 5) {
        printf("Usage: %s <server_ip> <server_port> <client_ip> <client_port>\n", argv[0]);
        return 1;
    }
    server_ip = argv[1];
    server_port = argv[2];
    client_ip = argv[3];
    client_port = argv[4];

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        return 1;
    }

    // Set up the server address structure
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(server_ip);
    server.sin_port = htons(atoi(server_port));

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect failed");
        return 1;
    }

    // Set up the client address structure
    memset(&client, 0, sizeof(client));
    client.sin_family = AF_INET;
    client.sin_addr.s_addr = inet_addr(client_ip);
    client.sin_port = htons(atoi(client_port));

    // Send a message to the server
    if (sendto(sock, message, message_length, 0, (struct sockaddr *)&client, sizeof(client)) < 0) {
        perror("sendto failed");
        return 1;
    }

    // Receive a message from the server
    if (recvfrom(sock, message, message_length, 0, (struct sockaddr *)&client, &client_port) < 0) {
        perror("recvfrom failed");
        return 1;
    }

    // Print the received message
    printf("Received message from %s:%s: %s\n", inet_ntoa(client.sin_addr), client_port, message);

    return 0;
}