//MISTRAL-7B DATASET v1.0 Category: Table Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 2
#define MIN_DICE_SIDE 1
#define MAX_DICE_SIDE 6
#define MIN_TARGET_SCORE 10
#define MAX_TARGET_SCORE 30

// Function to generate random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Struct to represent a player
typedef struct {
    int number;
    int total_points;
} Player;

int main() {
    srand(time(NULL));
    Player players[MAX_PLAYERS];
    int target_score, current_player = 0;

    // Initialize players
    for (int i = 0; i < MAX_PLAYERS; i++) {
        players[i].total_points = 0;
    }

    // Get target score from user
    do {
        printf("Enter target score (minimum %d, maximum %d): ", MIN_TARGET_SCORE, MAX_TARGET_SCORE);
        scanf("%d", &target_score);
    } while (target_score < MIN_TARGET_SCORE || target_score > MAX_TARGET_SCORE);

    // Game loop
    while (1) {
        Player *current_player_ptr = &players[current_player];
        int dice1, dice2;

        // Roll two dice
        dice1 = rand_num(MIN_DICE_SIDE, MAX_DICE_SIDE);
        dice2 = rand_num(MIN_DICE_SIDE, MAX_DICE_SIDE);

        // Add points to current player
        current_player_ptr->total_points += dice1 + dice2;

        // Check if current player has reached or exceeded target score
        if (current_player_ptr->total_points >= target_score) {
            printf("\nPlayer %d has reached or exceeded the target score of %d with a total of %d points.\n", current_player + 1, target_score, current_player_ptr->total_points);
            break;
        }

        // Switch to next player
        current_player = (current_player + 1) % MAX_PLAYERS;
    }

    return 0;
}