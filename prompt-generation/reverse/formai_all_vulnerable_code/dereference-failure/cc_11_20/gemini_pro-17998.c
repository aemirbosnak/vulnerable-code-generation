//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

// Configuration options
#define DEFAULT_PORT 80
#define MAX_CONNECTIONS 10
#define BUFFER_SIZE 4096

// Firewall rules configuration
struct firewall_rule {
    char *source_ip;
    char *source_port;
    char *destination_ip;
    char *destination_port;
    char *protocol;
    char *action;
};

// Initialize the firewall rules
struct firewall_rule rules[] = {
    { "192.168.1.1", "80", "0.0.0.0", "80", "tcp", "allow" },
    { "192.168.1.2", "443", "0.0.0.0", "443", "tcp", "allow" },
    { "192.168.1.3", "22", "0.0.0.0", "22", "tcp", "allow" },
    { "0.0.0.0", "0", "0.0.0.0", "0", "all", "deny" }
};

// Check if a packet matches a firewall rule
int check_firewall(struct firewall_rule *rule, struct sockaddr_in *source_addr, struct sockaddr_in *destination_addr, char *protocol) {
    int source_ip = ntohl(source_addr->sin_addr.s_addr);
    int source_port = ntohs(source_addr->sin_port);
    int destination_ip = ntohl(destination_addr->sin_addr.s_addr);
    int destination_port = ntohs(destination_addr->sin_port);

    // Check if the source IP matches
    if (strcmp(rule->source_ip, "0.0.0.0") != 0 && source_ip != inet_addr(rule->source_ip)) {
        return 0;
    }

    // Check if the source port matches
    if (strcmp(rule->source_port, "0") != 0 && source_port != atoi(rule->source_port)) {
        return 0;
    }

    // Check if the destination IP matches
    if (strcmp(rule->destination_ip, "0.0.0.0") != 0 && destination_ip != inet_addr(rule->destination_ip)) {
        return 0;
    }

    // Check if the destination port matches
    if (strcmp(rule->destination_port, "0") != 0 && destination_port != atoi(rule->destination_port)) {
        return 0;
    }

    // Check if the protocol matches
    if (strcmp(rule->protocol, "all") != 0 && strcmp(rule->protocol, protocol) != 0) {
        return 0;
    }

    // Return the action
    return strcmp(rule->action, "allow") == 0;
}

// Main function
int main(int argc, char *argv[]) {
    // Parse the command line arguments
    int port = DEFAULT_PORT;
    if (argc > 1) {
        port = atoi(argv[1]);
    }

    // Create the server socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error creating server socket");
        return EXIT_FAILURE;
    }

    // Bind the server socket to the specified port
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);
    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("Error binding server socket");
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CONNECTIONS) == -1) {
        perror("Error listening for incoming connections");
        return EXIT_FAILURE;
    }

    // Main loop
    while (1) {
        // Accept incoming connections
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &client_addr_len);
        if (client_socket == -1) {
            perror("Error accepting incoming connection");
            continue;
        }

        // Receive the data from the client
        char buffer[BUFFER_SIZE];
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received == -1) {
            perror("Error receiving data from client");
            continue;
        }

        // Check if the data matches a firewall rule
        char *protocol = strstr(buffer, "HTTP/");
        if (protocol == NULL) {
            protocol = "unknown";
        } else {
            protocol++;
        }
        int allowed = 0;
        for (int i = 0; i < sizeof(rules) / sizeof(struct firewall_rule); i++) {
            if (check_firewall(&rules[i], &client_addr, &server_addr, protocol)) {
                allowed = 1;
                break;
            }
        }

        // Send the response to the client
        const char *response = allowed ? "HTTP/1.1 200 OK\r\n\r\n" : "HTTP/1.1 403 Forbidden\r\n\r\n";
        int bytes_sent = send(client_socket, response, strlen(response), 0);
        if (bytes_sent == -1) {
            perror("Error sending data to client");
            continue;
        }

        // Close the client socket
        close(client_socket);
    }

    // Close the server socket
    close(server_socket);

    return EXIT_SUCCESS;
}