//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This program is a multiplayer Levenshtein Distance Calculator game.
 * Players take turns entering words, and the program calculates and displays
 * the minimum number of edits needed to transform the word into the previous word.
 * The player with the lowest total number of edits at the end of the game wins.
 *
 * Players may enter 'done' to end the game. The program will display the winner
 * along with their score.
 */

int levenshtein_distance(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int dp[len1+1][len2+1];

    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0) {  // base case
                dp[i][j] = j;
            } else if (j == 0) {  // base case
                dp[i][j] = i;
            } else if (s1[i-1] == s2[j-1]) {  // no edit needed
                dp[i][j] = dp[i-1][j-1];
            } else {  // calculate minimum edit
                dp[i][j] = 1 + min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
            }
        }
    }

    return dp[len1][len2];
}

int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

int main() {
    int player1_score = 0;
    int player2_score = 0;
    int current_player = 1;
    char current_word[100];
    char previous_word[100];

    printf("---- Welcome to Levenshtein Distance Calculator Game! ----");
    printf("\n\nPlayer 1, please enter a word: ");
    scanf("%s", current_word);
    printf("\nCurrent word: %s\n\n", current_word);

    while (strcmp(current_word, "done") != 0) {  // check if game is over
        if (current_player == 1) {  // player 1's turn
            if (strcmp(previous_word, "") != 0) {  // check if first turn
                int num_edits = levenshtein_distance(current_word, previous_word);
                printf("Player 1's Score: %d\n", num_edits);
                player1_score += num_edits;
            }
            printf("Player 2, please enter a word: ");
            scanf("%s", previous_word);
            printf("Previous word: %s\n\n", previous_word);
            current_player = 2;
        } else {  // player 2's turn
            if (strcmp(previous_word, "") != 0) {  // check if first turn
                int num_edits = levenshtein_distance(current_word, previous_word);
                printf("Player 2's Score: %d\n", num_edits);
                player2_score += num_edits;
            }
            printf("Player 1, please enter a word: ");
            scanf("%s", previous_word);
            printf("Previous word: %s\n\n", previous_word);
            current_player = 1;
        }
        printf("Current word: %s\n\n", previous_word);
    }

    // game over
    printf("---- Game Over! ----\n");
    printf("Player 1's score: %d\n", player1_score);
    printf("Player 2's score: %d\n", player2_score);
    if (player1_score < player2_score) {
        printf("Player 1 wins!\n\n");
    } else if (player2_score < player1_score) {
        printf("Player 2 wins!\n\n");
    } else {
        printf("It's a tie!\n\n");
    }

    return 0;
}