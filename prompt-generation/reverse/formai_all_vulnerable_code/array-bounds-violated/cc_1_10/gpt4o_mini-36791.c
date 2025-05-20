//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>

#define PORT 8080 
#define BUFFER_SIZE 1024
#define MAX_BLOCKED_IPS 10

struct BlockedIP {
    char *ip_address;
};

// A simple structure to hold a list of blocked IPs
struct BlockedIP blocked_ips[MAX_BLOCKED_IPS];
int blocked_count = 0;

// Function to block an IP address using iptables command
void block_ip(const char *ip_address) {
    char command[128];
    snprintf(command, sizeof(command), "iptables -A INPUT -s %s -j DROP", ip_address);
    system(command);
}

// Function to check if an IP is blocked
int is_ip_blocked(const char *ip_address) {
    for (int i = 0; i < blocked_count; i++) {
        if (strcmp(blocked_ips[i].ip_address, ip_address) == 0) {
            return 1; 
        }
    }
    return 0; 
}

// Function to add an IP to the blocked list
void add_ip_to_blocked(const char *ip_address) {
    if (blocked_count < MAX_BLOCKED_IPS) {
        blocked_ips[blocked_count].ip_address = strdup(ip_address);
        blocked_count++;
        block_ip(ip_address);
    } else {
        printf("Block list is full, cannot block more IPs!\n");
    }
}

// Function to handle incoming connections
void handle_connection(int client_socket, struct sockaddr_in client_address) {
    char client_ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &client_address.sin_addr, client_ip, sizeof(client_ip));

    if (is_ip_blocked(client_ip)) {
        printf("Blocked connection from %s\n", client_ip);
        close(client_socket);
        return;
    }

    char buffer[BUFFER_SIZE];
    int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
    if (bytes_received < 0) {
        perror("recv");
        close(client_socket);
        return;
    }

    buffer[bytes_received] = '\0'; // Null-terminate the string
    printf("Received from %s: %s\n", client_ip, buffer);

    // Echo back the message to the sender
    send(client_socket, buffer, bytes_received, 0);
    close(client_socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_len = sizeof(client_address);
   
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("bind");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 5) < 0) {
        perror("listen");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Firewall running on port %d\n", PORT);
    printf("Waiting for connections...\n");

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);
        if (client_socket < 0) {
            perror("accept");
            continue;
        }
        handle_connection(client_socket, client_address);
    }

    close(server_socket);
    return 0;
}