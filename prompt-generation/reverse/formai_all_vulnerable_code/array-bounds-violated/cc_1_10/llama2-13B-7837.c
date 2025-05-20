//LLAMA2-13B DATASET v1.0 Category: Firewall ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>

#define MAX_CONNECTIONS 100
#define MAX_PACKET_SIZE 1024

struct connection {
    int sock;
    char IP[16];
    char port[6];
};

int main(int argc, char *argv[]) {
    int listen_sock, client_sock;
    struct sockaddr_in listen_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[MAX_PACKET_SIZE];
    struct connection connections[MAX_CONNECTIONS];
    int i, j;

    // Initialize the socket
    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock < 0) {
        perror("socket failed");
        exit(1);
    }

    // Set up the listen address
    memset(&listen_addr, 0, sizeof(listen_addr));
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_port = htons(8080);
    listen_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the listen address
    if (bind(listen_sock, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(listen_sock, 3) < 0) {
        perror("listen failed");
        exit(1);
    }

    // Accept an incoming connection
    client_sock = accept(listen_sock, (struct sockaddr *)&client_addr, &client_len);
    if (client_sock < 0) {
        perror("accept failed");
        exit(1);
    }

    // Print the client's IP address and port
    printf("Client IP: %s, Port: %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // Set up the connection struct
    connections[i].sock = client_sock;
    memcpy(connections[i].IP, client_addr.sin_addr.s_addr, 16);
    memcpy(connections[i].port, client_addr.sin_port, 6);
    i++;

    // Loop through the connections and print their data
    for (j = 0; j < i; j++) {
        printf("Connection %d: IP: %s, Port: %d\n", j, connections[j].IP, connections[j].port);
    }

    // Close the sockets
    for (j = 0; j < i; j++) {
        close(connections[j].sock);
    }

    return 0;
}