//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

struct firewall_rule {
    char ip[INET_ADDRSTRLEN];
    int allow; // 1 for allow, 0 for deny
};

struct firewall_rule rules[10]; // Simple rule storage
int rule_count = 0;

void add_rule(const char *ip, int allow) {
    if (rule_count < 10) {
        strncpy(rules[rule_count].ip, ip, INET_ADDRSTRLEN);
        rules[rule_count].allow = allow;
        rule_count++;
        printf("Rule added: %s %s\n", ip, allow ? "ALLOW" : "DENY");
    } else {
        printf("Max rules reached. Can't add more.\n");
    }
}

int check_rule(const char *ip) {
    for (int i = 0; i < rule_count; i++) {
        if (strcmp(rules[i].ip, ip) == 0) {
            return rules[i].allow; // Return allow or deny
        }
    }
    return 1; // Default allow if no rules match
}

void handle_client(int new_socket) {
    char buffer[BUFFER_SIZE];
    char client_ip[INET_ADDRSTRLEN];
    struct sockaddr_in addr;
    socklen_t addr_len = sizeof(addr);

    // Get client address
    getpeername(new_socket, (struct sockaddr *)&addr, &addr_len);
    inet_ntop(AF_INET, &addr.sin_addr, client_ip, INET_ADDRSTRLEN);

    printf("Connection from %s\n", client_ip);

    int decision = check_rule(client_ip);
    if (!decision) {
        printf("Connection denied from %s\n", client_ip);
        close(new_socket);
        return;
    }

    // Receive data from client
    int bytes_received = recv(new_socket, buffer, BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        perror("recv");
        close(new_socket);
        return;
    }

    buffer[bytes_received] = '\0'; // Null-terminate the buffer
    printf("Received from %s: %s\n", client_ip, buffer);
    
    // Echo back the received message
    send(new_socket, buffer, bytes_received, 0);
    printf("Echoed back to %s\n", client_ip);

    close(new_socket);
}

int main() {
    add_rule("192.168.1.1", 1); // Allow this IP
    add_rule("192.168.1.2", 0); // Deny this IP
    add_rule("10.0.0.3", 1);    // Allow this IP
    
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);
    
    while (1) {
        // Accept a new connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            continue; // Not fatal, continue accepting
        }

        handle_client(new_socket);
    }

    return 0;
}