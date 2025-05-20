//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <time.h>
#include <signal.h>

#define PORT 8080
#define IP_ADDRESS "127.0.0.1"
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10

void *handle_client(void *client_socket);
void log_activity(const char *msg);
void cleanup_and_exit(int signum);

volatile sig_atomic_t running = 1;

int main() {
    signal(SIGINT, cleanup_and_exit);
    signal(SIGTERM, cleanup_and_exit);

    int server_socket, new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    pthread_t tid[MAX_CLIENTS];

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed in the neon-lit sky");
        exit(EXIT_FAILURE);
    }
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(IP_ADDRESS);
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed, the city is relentless");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listening failed, silence the cannons");
        exit(EXIT_FAILURE);
    }

    log_activity("Server initialized, waiting for connections in the underbelly of the net...");

    while (running) {
        new_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
        if (new_socket < 0) {
            perror("Accept failed, the shadows are watching");
            continue;
        }
        
        log_activity("A new signal has entered the void.");
        
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (tid[i] == 0) {
                if (pthread_create(&tid[i], NULL, handle_client, (void *)&new_socket) != 0) {
                    perror("Failed to create thread; the code is glitching");
                }
                break;
            }
        }
    }

    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (tid[i] != 0) {
            pthread_join(tid[i], NULL);
        }
    }

    close(server_socket);
    log_activity("Server shutting down, fading into oblivion...");
    return 0;
}

void *handle_client(void *client_socket) {
    int sock = *((int *)client_socket);
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = recv(sock, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate the string
        log_activity("Data received from a wanderer in cyberspace: ");
        printf("Client says: %s\n", buffer);
        
        // Process the incoming message
        // Sending a response back
        char response[BUFFER_SIZE];
        snprintf(response, sizeof(response), "Echo: %s", buffer);
        send(sock, response, strlen(response), 0);
    }
    
    if (bytes_read == 0) {
        log_activity("A client disconnected into the void...");
    } else {
        perror("Error reading from client socket; glitched data stream");
    }
    
    close(sock);
    return NULL;
}

void log_activity(const char *msg) {
    time_t raw_time;
    struct tm *time_info;
    char time_str[20];

    time(&raw_time);
    time_info = localtime(&raw_time);
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", time_info);
    
    printf("[%s] %s\n", time_str, msg);
}

void cleanup_and_exit(int signum) {
    log_activity("Emergency shutdown initiated, cutting connections...");
    running = 0;
}