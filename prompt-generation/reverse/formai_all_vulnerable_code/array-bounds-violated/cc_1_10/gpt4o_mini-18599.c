//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void log_request(const char *client_ip, const char *request) {
    FILE *logfile = fopen("firewall.log", "a");
    if (logfile == NULL) {
        perror("Could not open log file");
        return;
    }
    fprintf(logfile, "Client IP: %s | Request: %s\n", client_ip, request);
    fclose(logfile);
}

int is_ip_blocked(const char *ip_address) {
    const char *blocked_ips[] = {
        "192.168.1.100",
        "10.0.0.5",
        "172.16.0.15"
    };
    int blocked_count = sizeof(blocked_ips) / sizeof(blocked_ips[0]);

    for (int i = 0; i < blocked_count; i++) {
        if (strcmp(ip_address, blocked_ips[i]) == 0) {
            return 1; // IP is blocked
        }
    }
    return 0; // IP is not blocked
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    char client_ip[INET_ADDRSTRLEN];
    
    struct sockaddr_in client_addr;
    socklen_t addr_len = sizeof(client_addr);
    
    if (getpeername(client_socket, (struct sockaddr*)&client_addr, &addr_len) == -1) {
        perror("Error getting client address");
        close(client_socket);
        return;
    }
    
    inet_ntop(AF_INET, &(client_addr.sin_addr), client_ip, INET_ADDRSTRLEN);
    
    if (is_ip_blocked(client_ip)) {
        printf("Blocked IP attempt detected: %s\n", client_ip);
        close(client_socket);
        return;
    }

    ssize_t received_bytes = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);
    if (received_bytes <= 0) {
        perror("Failed to receive data");
        close(client_socket);
        return;
    }
    
    buffer[received_bytes] = '\0'; // Null-terminate the buffer
    printf("Received request from %s: %s\n", client_ip, buffer);
    log_request(client_ip, buffer);

    const char *response = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nHello from the firewall!";
    send(client_socket, response, strlen(response), 0);
    
    close(client_socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 5) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Firewall is running on port %d\n", PORT);
    
    while (1) {
        socklen_t addr_len = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addr_len);
        if (client_socket < 0) {
            perror("Accept failed");
            continue; // move on to the next client
        }
        handle_client(client_socket);
    }

    close(server_socket);
    return 0;
}