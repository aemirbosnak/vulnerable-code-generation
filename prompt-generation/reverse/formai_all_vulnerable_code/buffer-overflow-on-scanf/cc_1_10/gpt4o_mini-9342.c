//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <ctype.h>

#define PORT 993 // Default IMAP over SSL port
#define BUFFER_SIZE 1024
#define MAX_PLAYERS 5

typedef struct {
    int sock;
    char username[50];
    char server[100];
} Player;

Player players[MAX_PLAYERS];
int player_count = 0;

// Function for handling incoming messages
void handle_message(Player *player, const char *message) {
    printf("%s: %s\n", player->username, message);
}

// Function for connecting to IMAP server
int connect_to_imap(const char *server) {
    struct sockaddr_in server_addr;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, server, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to IMAP server failed");
        close(sock);
        return -1;
    }

    return sock;
}

// Function to register a new player (user)
void register_player(const char *username, const char *server) {
    if (player_count >= MAX_PLAYERS) {
        printf("Player limit reached!\n");
        return;
    }
    players[player_count].sock = connect_to_imap(server);
    if (players[player_count].sock != -1) {
        strncpy(players[player_count].username, username, sizeof(players[player_count].username));
        strncpy(players[player_count].server, server, sizeof(players[player_count].server));
        player_count++;
        printf("Player %s has joined the game on server %s\n", username, server);
    }
}

// Function to send a message to all players
void broadcast_message(const char *message) {
    for (int i = 0; i < player_count; i++) {
        handle_message(&players[i], message);
    }
}

// Main function for IMAP client multiplayer example
int main() {
    char username[50];
    char server[100];
    char buffer[BUFFER_SIZE];

    printf("Welcome to the IMAP Multiplayer Client!\n");
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter the IMAP server (e.g., 192.168.1.1): ");
    scanf("%s", server);

    register_player(username, server);

    while (1) {
        printf("Type your message (or type 'exit' to quit): ");
        fgets(buffer, BUFFER_SIZE, stdin);
        
        // Remove newline character
        buffer[strcspn(buffer, "\n")] = 0; 

        if (strcasecmp(buffer, "exit") == 0) {
            printf("Goodbye %s!\n", username);
            break;
        }
        
        // Send message to all players
        broadcast_message(buffer);
    }

    // Clean up and close sockets
    for (int i = 0; i < player_count; i++) {
        close(players[i].sock);
    }

    return 0;
}