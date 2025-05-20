//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>

#define PORT 8085
#define MAX_BUFFER 1024
#define BLOCKED_IPS_FILE "blocked_ips.txt"
#define MAX_BLOCKED 100

typedef struct {
    char blocked_ips[MAX_BLOCKED][INET_ADDRSTRLEN];
    int current_count;
    pthread_mutex_t lock;
} Firewall;

Firewall firewall;

void initialize_firewall() {
    firewall.current_count = 0;
    pthread_mutex_init(&firewall.lock, NULL);
}

void load_blocked_ips() {
    FILE *file = fopen(BLOCKED_IPS_FILE, "r");
    if (file == NULL) {
        perror("Failed to open blocked IPs file");
        return;
    }

    while (fgets(firewall.blocked_ips[firewall.current_count], INET_ADDRSTRLEN, file) != NULL) {
        strtok(firewall.blocked_ips[firewall.current_count], "\n"); // Remove trailing newline
        firewall.current_count++;
        if (firewall.current_count >= MAX_BLOCKED) break;
    }
    fclose(file);
}

int is_ip_blocked(const char *ip) {
    for (int i = 0; i < firewall.current_count; i++) {
        if (strcmp(firewall.blocked_ips[i], ip) == 0) {
            return 1; // IP is blocked
        }
    }
    return 0; // IP is not blocked
}

void block_ip(const char *ip) {
    pthread_mutex_lock(&firewall.lock);
    if (firewall.current_count < MAX_BLOCKED) {
        strcpy(firewall.blocked_ips[firewall.current_count], ip);
        firewall.current_count++;

        // Save blocked IP to file
        FILE *file = fopen(BLOCKED_IPS_FILE, "a");
        fprintf(file, "%s\n", ip);
        fclose(file);
    }
    pthread_mutex_unlock(&firewall.lock);
    printf("Blocked IP: %s\n", ip);
}

void handle_connection(int client_socket, struct sockaddr_in client_address) {
    char buffer[MAX_BUFFER];
    char client_ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(client_address.sin_addr), client_ip, INET_ADDRSTRLEN);

    printf("Incoming connection from %s\n", client_ip);
    
    if (is_ip_blocked(client_ip)) {
        printf("Connection from %s rejected! IP is blocked.\n", client_ip);
        close(client_socket);
        return;
    }

    int read_size = recv(client_socket, buffer, MAX_BUFFER, 0);
    if (read_size < 0) {
        perror("recv failed");
        close(client_socket);
        return;
    }

    buffer[read_size] = '\0';
    printf("Received: %s\n", buffer);

    // Simulating processing input to block specific IP
    if (strstr(buffer, "BLOCK") != NULL) {
        const char *ip_to_block = strtok(buffer, "BLOCK ");
        if (ip_to_block != NULL) {
            block_ip(ip_to_block);
        }
    }

    const char *response = "Data received.";
    send(client_socket, response, strlen(response), 0);
    close(client_socket);
}

void *server_thread(void *arg) {
    int server_socket = *(int *) arg;
    struct sockaddr_in client_address;
    socklen_t addr_size = sizeof(client_address);

    while (1) {
        int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &addr_size);
        if (client_socket < 0) {
            perror("accept failed");
            continue;
        }
        handle_connection(client_socket, client_address);
    }
}

int main() {
    initialize_firewall();
    load_blocked_ips();

    int server_socket;
    struct sockaddr_in server_address;

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        return -1;
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("bind failed");
        close(server_socket);
        return -1;
    }

    if (listen(server_socket, 5) < 0) {
        perror("listen failed");
        close(server_socket);
        return -1;
    }

    printf("Firewall server running on port %d. Monitoring for incoming connections...\n", PORT);

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, server_thread, (void *)&server_socket);
    pthread_join(thread_id, NULL);

    close(server_socket);
    pthread_mutex_destroy(&firewall.lock);
    return 0;
}