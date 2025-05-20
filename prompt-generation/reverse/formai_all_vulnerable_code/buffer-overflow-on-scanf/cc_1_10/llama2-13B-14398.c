//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TABLE_SIZE 10
#define PLAYER_NAME_MAX_LENGTH 20

// Structure to represent a player
typedef struct {
    char name[PLAYER_NAME_MAX_LENGTH];
    int score;
} player_t;

// Function to get a player's name
void get_player_name(player_t *player) {
    printf("Enter your name: ");
    fgets(player->name, PLAYER_NAME_MAX_LENGTH, stdin);
}

// Function to play a game round
void play_round(player_t *player) {
    int choice;
    printf("Choose a number from 1 to 6: ");
    scanf("%d", &choice);

    // Determine the outcome of the choice
    if (choice == 1) {
        player->score += 10;
    } else if (choice == 2) {
        player->score -= 5;
    } else if (choice == 3) {
        player->score *= 2;
    } else if (choice == 4) {
        player->score /= 2;
    } else if (choice == 5) {
        player->score += 10 * (rand() % 2);
    } else if (choice == 6) {
        player->score -= 10 * (rand() % 2);
    }

    // Print the player's updated score
    printf("Your score is now: %d\n", player->score);
}

// Function to main game loop
void game_loop(player_t *player) {
    int choice;
    do {
        play_round(player);
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
}

int main() {
    player_t player;

    // Initialize the player's name and score
    get_player_name(&player);
    player.score = 0;

    // Game loop
    game_loop(&player);

    return 0;
}