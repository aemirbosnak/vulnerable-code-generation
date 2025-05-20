//LLAMA2-13B DATASET v1.0 Category: Firewall ; Style: irregular
// Firewall of Dooooom! 🔥💣

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

#define MAX_CLIENT_CONNECTIONS 10
#define MAX_PACKET_SIZE 1024

struct client_info {
    int sock;
    char IPAddress[INET_ADDRSTRLEN];
};

int main(void) {
    int listen_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[MAX_PACKET_SIZE];
    struct client_info clients[MAX_CLIENT_CONNECTIONS];
    int i, j;

    // Create the listening socket
    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock < 0) {
        perror("Error creating listening socket");
        exit(1);
    }

    // Set up the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    // Bind the listening socket to the address and port
    if (bind(listen_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding listening socket");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(listen_sock, 3) < 0) {
        perror("Error listening for incoming connections");
        exit(1);
    }

    printf("Listening for incoming connections...\n");

    while (1) {
        // Accept an incoming connection
        client_sock = accept(listen_sock, (struct sockaddr *)&client_addr, &client_len);
        if (client_sock < 0) {
            perror("Error accepting incoming connection");
            exit(1);
        }

        // Print the client's IP address and port
        printf("New client connection from IP address: %s, port: %d\n",
               inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Add the client to the list of connected clients
        for (i = 0; i < MAX_CLIENT_CONNECTIONS; i++) {
            if (clients[i].sock == 0) {
                clients[i].sock = client_sock;
                strcpy(clients[i].IPAddress, inet_ntoa(client_addr.sin_addr));
                break;
            }
        }

        // If the list of connected clients is full, close the oldest client's connection
        if (i == MAX_CLIENT_CONNECTIONS) {
            for (j = 0; j < MAX_CLIENT_CONNECTIONS; j++) {
                if (clients[j].sock != 0) {
                    close(clients[j].sock);
                    clients[j].sock = 0;
                }
            }
        }

        // Read data from the client and send it back
        while (1) {
            read(client_sock, buffer, MAX_PACKET_SIZE);
            if (buffer[0] == '\0') {
                break;
            }
            send(client_sock, buffer, strlen(buffer), 0);
        }

        // Close the client's connection
        close(client_sock);
    }

    return 0;
}