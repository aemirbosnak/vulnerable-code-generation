//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX_PLAYERS 10
#define BUFFER_SIZE 1024

typedef struct {
    int socket;
    struct sockaddr_in address;
    int addr_len;
    char name[20];
} Player;

Player players[MAX_PLAYERS];
int player_count = 0;

void handle_new_connection(int server_socket) {
    if (player_count >= MAX_PLAYERS) {
        printf("Maximum players reached. Connection rejected.\n");
        return;
    }
    
    Player new_player;
    new_player.addr_len = sizeof(new_player.address);
    new_player.socket = accept(server_socket, 
                                (struct sockaddr *)&new_player.address, 
                                (socklen_t*)&new_player.addr_len);

    if (new_player.socket < 0) {
        perror("Accept failed");
        return;
    }

    printf("New connection established with IP: %s\n", 
           inet_ntoa(new_player.address.sin_addr));
    
    // Get player name
    recv(new_player.socket, new_player.name, sizeof(new_player.name), 0);
    printf("Player '%s' has joined the game.\n", new_player.name);
    
    players[player_count++] = new_player;
}

void send_message_to_all(char *message, int sender_socket) {
    for (int i = 0; i < player_count; i++) {
        if (players[i].socket != sender_socket) {
            send(players[i].socket, message, strlen(message), 0);
        }
    }
}

void check_quality_of_service() {
    char buffer[BUFFER_SIZE];
    for (int i = 0; i < player_count; i++) {
        int bytes_received = recv(players[i].socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Player '%s' has disconnected.\n", players[i].name);
            close(players[i].socket);
            // Remove player from players list
            for (int j = i; j < player_count - 1; j++) {
                players[j] = players[j + 1];
            }
            player_count--;
            i--; // Adjust index due to removal
        } else {
            buffer[bytes_received] = '\0';
            printf("Received from player '%s': %s\n", players[i].name, buffer);
            send_message_to_all(buffer, players[i].socket);
        }
    }
}

int main() {
    int server_socket;
    struct sockaddr_in address;

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        return -1;
    }

    // Prepare the sockaddr_in structure
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_socket);
        return -1;
    }

    // Listen for client connections
    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        close(server_socket);
        return -1;
    }

    printf("Server is listening on port %d...\n", PORT);

    while (1) {
        handle_new_connection(server_socket);
        check_quality_of_service();
        sleep(1); // Simulate a delay for monitoring purposes
    }

    close(server_socket);
    return 0;
}