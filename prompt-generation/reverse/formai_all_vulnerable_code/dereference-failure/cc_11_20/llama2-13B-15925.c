//LLAMA2-13B DATASET v1.0 Category: Firewall ; Style: relaxed
// firewall.c - A relaxed C firewall program

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

#define MAX_CLIENT_CONNECTIONS 10
#define MAX_PACKET_SIZE 1024

struct client_info {
    int sock;
    char ip_addr[INET_ADDRSTRLEN];
};

int main(void) {
    int listen_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[MAX_PACKET_SIZE];
    struct client_info clients[MAX_CLIENT_CONNECTIONS];
    int i, j;

    // Create a listening socket
    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock < 0) {
        perror("Error creating listening socket");
        return 1;
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    // Bind the listening socket to the address and port
    if (bind(listen_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding listening socket");
        return 1;
    }

    // Listen for incoming connections
    if (listen(listen_sock, 3) < 0) {
        perror("Error listening for incoming connections");
        return 1;
    }

    // Accept and handle incoming connections
    while (1) {
        // Accept an incoming connection
        client_sock = accept(listen_sock, (struct sockaddr *)&client_addr, &client_len);
        if (client_sock < 0) {
            perror("Error accepting incoming connection");
            continue;
        }

        // Print the client's IP address and port
        printf("New client connection from IP address: %s, port: %d\n",
               inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Add the client to the list of connected clients
        for (i = 0; i < MAX_CLIENT_CONNECTIONS; i++) {
            if (clients[i].sock == -1) {
                break;
            }
        }
        if (i == MAX_CLIENT_CONNECTIONS) {
            printf("Error: Too many clients connected\n");
            close(client_sock);
            continue;
        }
        clients[i].sock = client_sock;
        strcpy(clients[i].ip_addr, inet_ntoa(client_addr.sin_addr));

        // Handle incoming data from the client
        while (1) {
            int bytes_read = recv(client_sock, buffer, MAX_PACKET_SIZE, 0);
            if (bytes_read < 0) {
                perror("Error reading from client");
                break;
            }
            if (bytes_read == 0) {
                printf("Client disconnected\n");
                break;
            }
            // Do something with the incoming data...
            // ... like filtering out bad packets or
            // forwarding them to a log file or a web server
            // For this example, we'll just print the received data
            printf("Received packet from client: %s\n", buffer);
        }

        // Close the client socket and remove the client from the list
        close(client_sock);
        for (i = 0; i < MAX_CLIENT_CONNECTIONS; i++) {
            if (clients[i].sock == client_sock) {
                clients[i].sock = -1;
                break;
            }
        }
    }

    // Close the listening socket
    close(listen_sock);

    return 0;
}