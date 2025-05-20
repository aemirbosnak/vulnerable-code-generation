//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold the player's information
typedef struct {
    char name[20];
    int score;
} Player;

// Function to calculate the Levenshtein distance between two strings
int levenshtein_distance(char *s1, char *s2) {
    int m = strlen(s1);
    int n = strlen(s2);

    // Create a matrix to store the Levenshtein distance between the prefixes of s1 and s2
    int matrix[m + 1][n + 1];

    // Initialize the first row and column of the matrix
    for (int i = 0; i <= m; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        matrix[0][j] = j;
    }

    // Calculate the Levenshtein distance for each prefix of s1 and s2
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = 1 + fmin(matrix[i - 1][j], fmin(matrix[i][j - 1], matrix[i - 1][j - 1]));
            }
        }
    }

    // Return the Levenshtein distance between the two strings
    return matrix[m][n];
}

// Function to play a round of the game
void play_round(Player *players, int num_players) {
    // Get the input strings from the players
    char s1[20], s2[20];
    printf("Player 1, enter your string: ");
    scanf("%s", s1);
    printf("Player 2, enter your string: ");
    scanf("%s", s2);

    // Calculate the Levenshtein distance between the two strings
    int distance = levenshtein_distance(s1, s2);

    // Update the players' scores
    if (distance == 0) {
        players[0].score++;
        players[1].score++;
    } else {
        if (distance < 3) {
            players[0].score += 2;
            players[1].score += 1;
        } else {
            players[0].score += 1;
            players[1].score += 2;
        }
    }
}

// Function to play the game
void play_game(Player *players, int num_players) {
    // Play a number of rounds
    int num_rounds = 5;
    for (int i = 0; i < num_rounds; i++) {
        play_round(players, num_players);
    }

    // Print the final scores
    printf("Player 1: %d\n", players[0].score);
    printf("Player 2: %d\n", players[1].score);
}

// Main function
int main() {
    // Create an array of players
    Player players[2];

    // Get the players' names
    printf("Player 1, enter your name: ");
    scanf("%s", players[0].name);
    printf("Player 2, enter your name: ");
    scanf("%s", players[1].name);

    // Set the players' scores to 0
    players[0].score = 0;
    players[1].score = 0;

    // Play the game
    play_game(players, 2);

    return 0;
}