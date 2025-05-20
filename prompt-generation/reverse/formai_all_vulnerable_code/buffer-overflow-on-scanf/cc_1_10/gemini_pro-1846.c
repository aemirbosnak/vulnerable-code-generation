//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_WORD_LENGTH 20

typedef struct {
    char name[MAX_WORD_LENGTH];
    int score;
} player_t;

int main() {
    // Initialize the players
    player_t players[MAX_PLAYERS];
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }

    // Get the target word
    char target_word[MAX_WORD_LENGTH];
    printf("Enter the target word: ");
    scanf("%s", target_word);

    // Main game loop
    while (1) {
        // Get each player's guess
        for (int i = 0; i < MAX_PLAYERS; i++) {
            char guess[MAX_WORD_LENGTH];
            printf("%s's guess: ", players[i].name);
            scanf("%s", guess);

            // Calculate the Levenshtein distance between the guess and the target word
            int distance = levenshtein(guess, target_word);

            // Update the player's score
            players[i].score += distance;
        }

        // Check if any player has reached the winning score
        int winning_score = strlen(target_word);
        for (int i = 0; i < MAX_PLAYERS; i++) {
            if (players[i].score >= winning_score) {
                printf("%s wins!\n", players[i].name);
                return 0;
            }
        }

        // Print the current standings
        printf("Current standings:\n");
        for (int i = 0; i < MAX_PLAYERS; i++) {
            printf("%s: %d\n", players[i].name, players[i].score);
        }
    }

    return 0;
}

// Levenshtein distance function
int levenshtein(const char *s1, const char *s2) {
    const size_t len1 = strlen(s1);
    const size_t len2 = strlen(s2);

    int matrix[len1 + 1][len2 + 1];

    // Initialize the first row and column of the matrix
    for (size_t i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (size_t j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    // Fill out the rest of the matrix
    for (size_t i = 1; i <= len1; i++) {
        for (size_t j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            matrix[i][j] = min(matrix[i - 1][j] + 1, min(matrix[i][j - 1] + 1, matrix[i - 1][j - 1] + cost));
        }
    }

    // Return the value in the bottom-right corner of the matrix
    return matrix[len1][len2];
}

// Min function
int min(int a, int b) {
    return (a < b) ? a : b;
}