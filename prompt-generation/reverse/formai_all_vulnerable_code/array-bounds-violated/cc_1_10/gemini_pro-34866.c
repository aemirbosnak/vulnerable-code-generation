//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_PLAYERS 10
#define MAX_URL_LENGTH 256

struct player {
    int sockfd;
    char* name;
    char* url;
};

struct game {
    struct player players[MAX_PLAYERS];
    int num_players;
};

// Sanitizes a URL by removing any potentially malicious characters.
char* sanitize_url(char* url) {
    char* sanitized_url = malloc(strlen(url) + 1);
    int j = 0;
    for (int i = 0; i < strlen(url); i++) {
        if (url[i] >= 'a' && url[i] <= 'z') {
            sanitized_url[j++] = url[i];
        } else if (url[i] >= 'A' && url[i] <= 'Z') {
            sanitized_url[j++] = url[i];
        } else if (url[i] >= '0' && url[i] <= '9') {
            sanitized_url[j++] = url[i];
        } else if (url[i] == '.' || url[i] == '/' || url[i] == ':' || url[i] == '@') {
            sanitized_url[j++] = url[i];
        }
    }
    sanitized_url[j] = '\0';
    return sanitized_url;
}

// Creates a new game.
struct game* create_game() {
    struct game* game = malloc(sizeof(struct game));
    game->num_players = 0;
    return game;
}

// Adds a player to the game.
void add_player(struct game* game, int sockfd, char* name, char* url) {
    game->players[game->num_players].sockfd = sockfd;
    game->players[game->num_players].name = strdup(name);
    game->players[game->num_players].url = sanitize_url(url);
    game->num_players++;
}

// Removes a player from the game.
void remove_player(struct game* game, int sockfd) {
    for (int i = 0; i < game->num_players; i++) {
        if (game->players[i].sockfd == sockfd) {
            free(game->players[i].name);
            free(game->players[i].url);
            for (int j = i; j < game->num_players - 1; j++) {
                game->players[j] = game->players[j + 1];
            }
            game->num_players--;
            break;
        }
    }
}

// Sends a message to all players in the game.
void broadcast_message(struct game* game, char* message) {
    for (int i = 0; i < game->num_players; i++) {
        send(game->players[i].sockfd, message, strlen(message), 0);
    }
}

// Main game loop.
void game_loop(struct game* game) {
    while (1) {
        // Receive messages from players.
        for (int i = 0; i < game->num_players; i++) {
            char buffer[MAX_URL_LENGTH];
            int n = recv(game->players[i].sockfd, buffer, MAX_URL_LENGTH, 0);
            if (n <= 0) {
                remove_player(game, game->players[i].sockfd);
                continue;
            }
            buffer[n] = '\0';

            // Sanitize the URL.
            char* sanitized_url = sanitize_url(buffer);

            // Broadcast the sanitized URL to all players.
            char message[MAX_URL_LENGTH + 16];
            sprintf(message, "%s: %s", game->players[i].name, sanitized_url);
            broadcast_message(game, message);

            free(sanitized_url);
        }
    }
}

int main() {
    // Create a new game.
    struct game* game = create_game();

    // Create a server socket.
    int server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Bind the server socket to a port.
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(8080);
    if (bind(server_sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }

    // Listen for incoming connections.
    if (listen(server_sockfd, MAX_PLAYERS) == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }

    // Main loop.
    while (1) {
        // Accept a new connection.
        int client_sockfd = accept(server_sockfd, NULL, NULL);
        if (client_sockfd == -1) {
            perror("accept");
            continue;
        }

        // Receive the player's name and URL.
        char name[MAX_URL_LENGTH];
        char url[MAX_URL_LENGTH];
        int n = recv(client_sockfd, name, MAX_URL_LENGTH, 0);
        if (n <= 0) {
            close(client_sockfd);
            continue;
        }
        name[n] = '\0';
        n = recv(client_sockfd, url, MAX_URL_LENGTH, 0);
        if (n <= 0) {
            close(client_sockfd);
            continue;
        }
        url[n] = '\0';

        // Add the player to the game.
        add_player(game, client_sockfd, name, url);

        // Send a welcome message to the player.
        char message[MAX_URL_LENGTH + 16];
        sprintf(message, "Welcome to the game, %s!", name);
        send(client_sockfd, message, strlen(message), 0);

        // Broadcast the player's name and URL to all other players.
        char message2[MAX_URL_LENGTH + 16];
        sprintf(message2, "%s has joined the game: %s", name, url);
        broadcast_message(game, message2);
    }

    // Close the server socket.
    close(server_sockfd);

    // Free the game.
    for (int i = 0; i < game->num_players; i++) {
        free(game->players[i].name);
        free(game->players[i].url);
    }
    free(game);

    return EXIT_SUCCESS;
}