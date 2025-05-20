//LLAMA2-13B DATASET v1.0 Category: Firewall ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

#define MAX_CONNECTIONS 100
#define MAX_PACKET_SIZE 1024

struct connection {
    int sock;
    struct sockaddr_in client_addr;
    char client_ip[INET_ADDRSTRLEN];
};

int main(int argc, char *argv[]) {
    int listen_sock, client_sock;
    struct sockaddr_in listen_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[MAX_PACKET_SIZE];
    struct connection connections[MAX_CONNECTIONS];
    int connection_count = 0;

    // Initialize the socket
    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock < 0) {
        perror("socket failed");
        exit(1);
    }

    // Set up the address structure for the listen socket
    memset(&listen_addr, 0, sizeof(listen_addr));
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_addr.s_addr = INADDR_ANY;
    listen_addr.sin_port = htons(8080);

    // Bind the listen socket to the address and port
    if (bind(listen_sock, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(listen_sock, 5) < 0) {
        perror("listen failed");
        exit(1);
    }

    while (1) {
        // Accept an incoming connection
        client_sock = accept(listen_sock, (struct sockaddr *)&client_addr, &client_len);
        if (client_sock < 0) {
            perror("accept failed");
            exit(1);
        }

        // Print the client IP address and port
        printf("Connection from %s port %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Add the client to the list of connections
        connections[connection_count].sock = client_sock;
        connections[connection_count].client_addr = client_addr;
        strncpy(connections[connection_count].client_ip, inet_ntoa(client_addr.sin_addr), INET_ADDRSTRLEN);
        connection_count++;

        // Handle the incoming data
        while (1) {
            int bytes_read = recv(client_sock, buffer, MAX_PACKET_SIZE, 0);
            if (bytes_read < 0) {
                perror("recv failed");
                break;
            }
            printf("Received packet of %d bytes\n", bytes_read);

            // Check if the client is sending a valid packet
            if (bytes_read == 0 || buffer[0] != 'H' || buffer[1] != 'E' || buffer[2] != 'L' || buffer[3] != 'L' || buffer[4] != 'O') {
                printf("Invalid packet received, closing connection\n");
                close(client_sock);
                break;
            }

            // Check if the client is trying to connect to a valid port
            if (strcmp(buffer + 5, "8080") != 0) {
                printf("Invalid port specified, closing connection\n");
                close(client_sock);
                break;
            }

            // Send a response packet back to the client
            char *response = "Hello, client!";
            send(client_sock, response, strlen(response), 0);
        }

        // Close the client connection
        close(client_sock);
    }

    return 0;
}