//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10

typedef struct {
    int client_socket;
    struct sockaddr_in client_addr;
} ClientData;

void *monitor_traffic(void *arg);
void log_event(const char *event);
int check_for_intrusion(const char *data);
void handle_client(int client_socket);

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    pthread_t traffic_monitor_thread;

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    listen(server_socket, MAX_CLIENTS);
    printf("Server listening on port %d...\n", PORT);

    // Start the traffic monitoring thread
    pthread_create(&traffic_monitor_thread, NULL, monitor_traffic, NULL);

    // Accept connections and handle clients
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
        if (client_socket < 0) {
            perror("Client acceptance failed");
            continue;
        }
        printf("Client connected: %s\n", inet_ntoa(client_addr.sin_addr));
        handle_client(client_socket);
    }

    // Cleanup
    close(server_socket);
    return 0;
}

void *monitor_traffic(void *arg) {
    char buffer[BUFFER_SIZE];
    time_t current_time;
    struct tm *tm_info;

    while (1) {
        sleep(5); // Monitor traffic every 5 seconds
        // Log placeholder for monitoring data
        time(&current_time);
        tm_info = localtime(&current_time);
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info);
        printf("Monitoring traffic at: %s\n", buffer);
    }
    return NULL;
}

void log_event(const char *event) {
    FILE *log_file = fopen("intrusion_log.txt", "a");
    if (log_file) {
        fprintf(log_file, "%s\n", event);
        fclose(log_file);
    }
}

int check_for_intrusion(const char *data) {
    // Simplified intrusion detection logic
    if (strstr(data, "DROP TABLE") || strstr(data, "SELECT * FROM users") ||
        strstr(data, "UNION SELECT")) {
        log_event("Intrusion detected!");
        return 1; // Intrusion detected
    }
    return 0; // No intrusion
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    // Reading data from client
    while ((bytes_read = recv(client_socket, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_read] = '\0'; // Null terminate the buffer
        printf("Received from client: %s\n", buffer);

        // Check for intrusion
        if (check_for_intrusion(buffer)) {
            printf("Intrusion attempt identified, disconnecting client.\n");
            break;
        }
    }

    if (bytes_read == 0) {
        printf("Client disconnected.\n");
    } else if (bytes_read < 0) {
        perror("Receive failed");
    }

    close(client_socket);
}