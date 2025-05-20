//LLAMA2-13B DATASET v1.0 Category: Firewall ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define MAX_CONNECTIONS 10
#define MAX_PACKET_SIZE 1024

struct connection {
    int sock;
    struct sockaddr_in client_addr;
    char client_name[50];
};

int main(int argc, char *argv[]) {
    int listen_sock, client_sock;
    struct sockaddr_in listen_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[MAX_PACKET_SIZE];
    struct connection connections[MAX_CONNECTIONS];
    int i, j;

    // Create the listening socket
    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock < 0) {
        perror("socket failed");
        exit(1);
    }

    // Set up the listening address
    memset(&listen_addr, 0, sizeof(listen_addr));
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_addr.s_addr = INADDR_ANY;
    listen_addr.sin_port = htons(8080);

    // Bind the listening socket to the address and port
    if (bind(listen_sock, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(listen_sock, 3) < 0) {
        perror("listen failed");
        exit(1);
    }

    printf("Listening for incoming connections...\n");

    while (1) {
        // Accept an incoming connection
        client_sock = accept(listen_sock, (struct sockaddr *)&client_addr, &client_len);
        if (client_sock < 0) {
            perror("accept failed");
            continue;
        }

        // Print the client address and port
        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Create a new connection structure for the client
        connections[i] = (struct connection) {
            .sock = client_sock,
            .client_addr = client_addr,
            .client_name = "Unknown"
        };

        // Increment the connection count
        i++;

        // Loop through the connections and check if any are complete
        for (j = 0; j < i; j++) {
            if (connections[j].sock == client_sock) {
                // Check if the client has sent a complete packet
                if (recv(connections[j].sock, buffer, MAX_PACKET_SIZE, 0) > 0) {
                    // If the client has sent a complete packet, print the packet
                    printf("Received packet from %s:%d: %s\n", inet_ntoa(connections[j].client_addr.sin_addr), ntohs(connections[j].client_addr.sin_port), buffer);

                    // Check if the packet is a "SHUTDOWN" command
                    if (strcmp(buffer, "SHUTDOWN") == 0) {
                        // If the packet is a "SHUTDOWN" command, shut down the connection
                        shutdown(connections[j].sock, SHUT_RDWR);
                        printf("Shut down connection from %s:%d\n", inet_ntoa(connections[j].client_addr.sin_addr), ntohs(connections[j].client_addr.sin_port));
                    }
                }
            }
        }
    }

    // Close the listening socket
    close(listen_sock);

    return 0;
}