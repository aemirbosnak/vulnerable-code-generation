//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define PORT 8080
#define MAX_PLAYERS 5
#define GRID_SIZE 5

typedef struct {
    int x;
    int y;
    int found;
} Treasure;

typedef struct {
    int player_id;
    int score;
} Player;

Treasure treasure;
Player players[MAX_PLAYERS];
int player_count = 0;

void init_game() {
    treasure.x = rand() % GRID_SIZE;
    treasure.y = rand() % GRID_SIZE;
    treasure.found = 0;
    for (int i = 0; i < MAX_PLAYERS; ++i) {
        players[i].player_id = -1;
        players[i].score = 0;
    }
}

void handle_client(int new_socket) {
    int player_id;
    recv(new_socket, &player_id, sizeof(player_id), 0);
    if (player_count < MAX_PLAYERS) {
        players[player_count].player_id = player_id;
        player_count++;
        printf("Player %d joined the game.\n", player_id);
    }
    while (1) {
        int guess[2];
        recv(new_socket, &guess, sizeof(guess), 0);
        if (treasure.found) {
            send(new_socket, "Treasure has already been found!", sizeof("Treasure has already been found!"), 0);
            break;
        }
        if (guess[0] == treasure.x && guess[1] == treasure.y) {
            treasure.found = 1;
            players[player_id].score += 1;
            char msg[50];
            snprintf(msg, sizeof(msg), "Player %d found the treasure! Score: %d", player_id, players[player_id].score);
            send(new_socket, msg, sizeof(msg), 0);
            printf("Treasure found by Player %d!\n", player_id);
        } else {
            send(new_socket, "Missed! Try again!", sizeof("Missed! Try again!"), 0);
        }
    }
    close(new_socket);
}

int main() {
    srand(time(NULL));
    init_game();
    
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Waiting for players to join...\n");
    
    while ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) >= 0) {
        if (fork() == 0) {
            close(server_fd);
            handle_client(new_socket);
            exit(0);
        }
        close(new_socket);
    }
    
    return 0;
}