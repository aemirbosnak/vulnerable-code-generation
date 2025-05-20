//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_MESSAGE_LENGTH 256
#define ASCII_ART_WIDTH 80
#define ASCII_ART_HEIGHT 25

typedef struct {
    char name[20];
    int score;
} Player;

Player players[MAX_PLAYERS];
int num_players;

void init_players() {
    srand(time(NULL));
    num_players = rand() % MAX_PLAYERS + 2;
    for (int i = 0; i < num_players; i++) {
        strcpy(players[i].name, "Player ");
        char num_str[10];
        sprintf(num_str, "%d", i + 1);
        strcat(players[i].name, num_str);
    }
}

void print_ascii_art() {
    for (int i = 0; i < ASCII_ART_HEIGHT; i++) {
        for (int j = 0; j < ASCII_ART_WIDTH; j++) {
            printf(" ");
        }
        printf("\n");
    }
}

void print_player_info(Player player) {
    printf("Name: %s\n", player.name);
    printf("Score: %d\n", player.score);
}

int main() {
    init_players();
    int game_over = 0;
    while (!game_over) {
        print_ascii_art();
        printf("Player Scores:\n");
        for (int i = 0; i < num_players; i++) {
            print_player_info(players[i]);
        }
        printf("\nPress enter to continue...\n");
        getchar();
    }
    return 0;
}