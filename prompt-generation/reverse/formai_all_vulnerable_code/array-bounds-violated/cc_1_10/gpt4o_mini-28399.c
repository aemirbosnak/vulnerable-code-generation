//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>
#include <time.h>

#define PORT 8080
#define MAX_CLIENTS 100
#define BUFFER_SIZE 1024
#define TIMEOUT 5

struct Client {
    int socket;
    struct sockaddr_in address;
    time_t last_active_time;
};

struct Client clients[MAX_CLIENTS];
int client_count = 0;

void sigint_handler(int signum) {
    printf("\nRestoration abandoned. Shutting down firewall guardian...\n");
    exit(0);
}

void log_event(const char *event) {
    time_t now = time(NULL);
    FILE *log_file = fopen("firewall.log", "a");
    if (log_file) {
        fprintf(log_file, "[%s] %s\n", ctime(&now), event);
        fclose(log_file);
    }
}

void block_ip(char *ip_address) {
    printf("Blocking IP: %s\n", ip_address);
    char command[128];
    snprintf(command, sizeof(command), "iptables -A INPUT -s %s -j DROP", ip_address);
    system(command);
    log_event("Blocked IP: ");
    log_event(ip_address);
}

void check_clients() {
    time_t current_time = time(NULL);
    for (int i = 0; i < client_count; i++) {
        if (clients[i].socket > 0 && 
            difftime(current_time, clients[i].last_active_time) > TIMEOUT) {
            printf("Client %s has been inactive. Blocking...\n", 
                   inet_ntoa(clients[i].address.sin_addr));
            block_ip(inet_ntoa(clients[i].address.sin_addr));
            close(clients[i].socket);
            clients[i].socket = 0; // Mark for cleanup
        }
    }
}

void accept_client(int server_socket) {
    struct sockaddr_in address;
    socklen_t addr_len = sizeof(address);
    int new_socket = accept(server_socket, (struct sockaddr *)&address, &addr_len);
    
    if (new_socket < 0) {
        perror("Accept failed");
        return;
    }

    char *ip_address = inet_ntoa(address.sin_addr);
    printf("New client connected: %s\n", ip_address);
    clients[client_count].socket = new_socket;
    clients[client_count].address = address;
    clients[client_count].last_active_time = time(NULL);
    client_count++;

    log_event("Client connected: ");
    log_event(ip_address);
}

void handle_client_message(int index) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(clients[index].socket, buffer, sizeof(buffer), 0);
    
    if (bytes_received <= 0) {
        printf("Client %s disconnected.\n", 
               inet_ntoa(clients[index].address.sin_addr));
        close(clients[index].socket);
        clients[index].socket = 0; // Mark for cleanup
        return;
    }

    buffer[bytes_received] = '\0';
    printf("Received from %s: %s\n", inet_ntoa(clients[index].address.sin_addr), buffer);
    
    // Update last active time
    clients[index].last_active_time = time(NULL);

    // Respond back
    send(clients[index].socket, buffer, bytes_received, 0);
    log_event("Message received from client: ");
    log_event(buffer);
}

void cleanup_clients() {
    for (int i = 0; i < client_count; i++) {
        if (clients[i].socket == 0) {
            for (int j = i; j < client_count - 1; j++) {
                clients[j] = clients[j + 1];
            }
            client_count--;
            i--;
        }
    }
}

int main() {
    signal(SIGINT, sigint_handler);

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        return -1;
    }

    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        return -1;
    }

    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        return -1;
    }

    printf("Post-Apocalyptic Firewall Guardian running on port %d...\n", PORT);
    
    while (1) {
        // Accept new clients
        if (client_count < MAX_CLIENTS) {
            accept_client(server_socket);
        }

        // Handle each client message
        for (int i = 0; i < client_count; i++) {
            if (clients[i].socket > 0) {
                handle_client_message(i);
            }
        }

        // Check client timeouts
        check_clients();

        // Cleanup disconnected clients
        cleanup_clients();

        sleep(1);
    }

    close(server_socket);
    return 0;
}