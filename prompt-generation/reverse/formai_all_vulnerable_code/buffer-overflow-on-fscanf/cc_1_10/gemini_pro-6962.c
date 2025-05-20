//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Macros
#define MAX_CONNECTIONS 10
#define MAX_BUFFER_SIZE 1024
#define RULES_FILE "firewall.rules"

// Structures
typedef struct {
    char *ip_address;
    int port;
    int allowed;
} rule;

// Global variables
rule rules[MAX_CONNECTIONS];
int num_rules = 0;

// Function declarations
int load_rules();
int check_rule(char *ip_address, int port);
void handle_connection(int connection_socket);
void firewall_loop();

// Main function
int main() {
    // Load the firewall rules
    if (load_rules() < 0) {
        fprintf(stderr, "Error loading firewall rules.\n");
        return -1;
    }

    // Start the firewall loop
    firewall_loop();

    return 0;
}

// Load the firewall rules from the RULES_FILE file
int load_rules() {
    // Open the RULES_FILE file
    FILE *rules_file = fopen(RULES_FILE, "r");
    if (rules_file == NULL) {
        perror("fopen");
        return -1;
    }

    // Read the rules from the file
    while (fscanf(rules_file, "%s %d %d", rules[num_rules].ip_address, &rules[num_rules].port, &rules[num_rules].allowed) != EOF) {
        num_rules++;
    }

    // Close the RULES_FILE file
    fclose(rules_file);

    return 0;
}

// Check if the given IP address and port are allowed by the firewall rules
int check_rule(char *ip_address, int port) {
    // Iterate over the rules
    for (int i = 0; i < num_rules; i++) {
        // Check if the IP address and port match the rule
        if (strcmp(ip_address, rules[i].ip_address) == 0 && port == rules[i].port) {
            // Return the allowed flag
            return rules[i].allowed;
        }
    }

    // No rule was found, so return -1
    return -1;
}

// Handle a new connection
void handle_connection(int connection_socket) {
    // Get the IP address and port of the client
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    getpeername(connection_socket, (struct sockaddr *)&client_addr, &client_addr_len);

    // Check if the connection is allowed by the firewall rules
    int allowed = check_rule(inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // If the connection is not allowed, send a rejection message
    if (allowed == 0) {
        const char *rejection_message = "Connection refused by firewall.\n";
        send(connection_socket, rejection_message, strlen(rejection_message), 0);
        close(connection_socket);
        return;
    }

    // If the connection is allowed, forward the data to the destination
    char buffer[MAX_BUFFER_SIZE];
    while (recv(connection_socket, buffer, sizeof(buffer), 0) > 0) {
        send(connection_socket, buffer, sizeof(buffer), 0);
    }

    // Close the connection
    close(connection_socket);
}

// The main firewall loop
void firewall_loop() {
    // Create a new socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket");
        exit(1);
    }

    // Bind the socket to the loopback address and port 8080
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    server_addr.sin_port = htons(8080);
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    // Listen for new connections
    if (listen(server_socket, MAX_CONNECTIONS) < 0) {
        perror("listen");
        exit(1);
    }

    // Accept new connections and handle them in a separate process
    while (1) {
        // Accept a new connection
        int connection_socket = accept(server_socket, NULL, NULL);
        if (connection_socket < 0) {
            perror("accept");
            continue;
        }

        // Fork a new process to handle the connection
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            close(connection_socket);
            continue;
        }

        if (pid == 0) {
            // Child process
            close(server_socket);
            handle_connection(connection_socket);
            exit(0);
        } else {
            // Parent process
            close(connection_socket);
        }
    }

    // Close the server socket
    close(server_socket);
}