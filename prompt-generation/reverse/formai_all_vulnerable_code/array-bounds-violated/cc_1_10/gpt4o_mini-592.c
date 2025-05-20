//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_CLIENTS 10
#define PORT 8888
#define BUFFER_SIZE 1024
#define TEST_DURATION 10

typedef struct {
    char client_ip[INET6_ADDRSTRLEN];
    int packet_count;
    double total_response_time;
} ClientStats;

void log_stats(ClientStats *stats, int client_count) {
    printf("\n--- Network Quality of Service Statistics ---\n");
    printf("Client IP\tPacket Count\tAverage Response Time (ms)\n");
    
    for (int i = 0; i < client_count; i++) {
        double avg_response_time = (stats[i].packet_count > 0) ? 
                                    (stats[i].total_response_time / stats[i].packet_count) 
                                    : 0;

        printf("%s\t%d\t\t%.2f\n", stats[i].client_ip, stats[i].packet_count, avg_response_time);
    }
    printf("---------------------------------------------\n");
}

void handle_client(int client_socket, ClientStats *client_stats, struct sockaddr_in *client_address) {
    char buffer[BUFFER_SIZE];
    ssize_t num_bytes;
    time_t start_time = time(NULL);
    
    while (time(NULL) - start_time < TEST_DURATION) {
        num_bytes = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (num_bytes > 0) {
            buffer[num_bytes] = '\0';
            double response_time = ((double)(rand() % 100) / 10.0); // Simulated response time
            client_stats->packet_count++;
            client_stats->total_response_time += response_time;
            printf("Received data from %s: %s | Response time: %.2f ms\n", 
                   inet_ntoa(client_address->sin_addr), buffer, response_time);
        }
        usleep(100000); // Sleep to simulate processing time
    }
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_length = sizeof(client_address);
    ClientStats client_stats[MAX_CLIENTS];
    int client_count = 0;

    srand(time(NULL));

    // Initialize server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setup server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind socket to the port
    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    
    printf("Waiting for clients to connect...\n");

    while (client_count < MAX_CLIENTS) {
        client_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_address_length);
        if (client_socket < 0) {
            perror("Accept failed");
            continue;
        }

        // Store client statistics
        inet_ntop(client_address.sin_family, &client_address.sin_addr, client_stats[client_count].client_ip, sizeof(client_stats[client_count].client_ip));
        client_stats[client_count].packet_count = 0;
        client_stats[client_count].total_response_time = 0;

        printf("Client connected: %s\n", client_stats[client_count].client_ip);

        // Handle client communication
        handle_client(client_socket, &client_stats[client_count], &client_address);
        
        client_count++;
        close(client_socket);
    }

    // Log statistics after all clients have been handled
    log_stats(client_stats, client_count);

    close(server_socket);
    return 0;
}