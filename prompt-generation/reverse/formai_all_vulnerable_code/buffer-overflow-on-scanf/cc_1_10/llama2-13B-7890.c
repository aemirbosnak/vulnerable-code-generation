//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PLAYERS 4
#define MAX_GUESTS 10
#define GUEST_LIMIT 5

struct player {
    char name[50];
    int score;
};

struct guest {
    char name[50];
    int score;
    int join_time;
};

int main() {
    // Initialize players and guests
    struct player players[PLAYERS] = {
        {"Alice", 0},
        {"Bob", 0},
        {"Charlie", 0},
        {"David", 0}
    };

    struct guest guests[MAX_GUESTS];
    int num_guests = 0;

    // Game loop
    while (1) {
        // Print current state of the game
        printf("--- GAME STATE ---\n");
        for (int i = 0; i < PLAYERS; i++) {
            printf("Player %d: %s (score: %d)\n", i, players[i].name, players[i].score);
        }

        // Check for new guests
        for (int i = 0; i < MAX_GUESTS; i++) {
            if (guests[i].join_time == 0) {
                // New guest joined, add to list
                guests[i].join_time = clock();
                guests[i].score = 0;
                num_guests++;
                break;
            }
        }

        // Update player scores
        for (int i = 0; i < PLAYERS; i++) {
            players[i].score += get_score();
        }

        // Check for winners
        for (int i = 0; i < PLAYERS; i++) {
            if (players[i].score >= 100) {
                printf("Player %d wins! (score: %d)\n", i, players[i].score);
                break;
            }
        }

        // Print game over message if all players have won
        if (num_guests == 0) {
            printf("Game over! No more guests joined.\n");
        }
    }

    // Clean up
    for (int i = 0; i < MAX_GUESTS; i++) {
        free(guests[i].name);
    }
    free(guests);

    return 0;
}

// Helper function to get a score
int get_score() {
    int score = 0;
    char c;

    // Read input from the user
    printf("Enter a character (A-Z): ");
    scanf("%c", &c);

    // Check if the character is uppercase
    if (isupper(c)) {
        // Increase score by 10 for uppercase letters
        score += 10;
    }

    return score;
}