//FormAI DATASET v1.0 Category: String manipulation ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 50
#define MAX_PLAYERS 10

int main() {
    char word[MAX_WORD_LENGTH];
    printf("Enter a word for the game: ");
    scanf("%s", word);
    
    int len = strlen(word);
    char guessed_word[len];
    memset(guessed_word, '_', len); // fill the guessed word with underscores

    int players;
    printf("Enter the number of players: ");
    scanf("%d", &players);

    char player_names[MAX_PLAYERS][MAX_WORD_LENGTH];
    int scores[MAX_PLAYERS];
    memset(scores, 0, players * sizeof(int));

    for (int i = 0; i < players; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", player_names[i]);
    }

    int winner_idx;
    int max_score = -1;
    int round = 1;
    do {
        printf("\nRound %d\n", round++);
        for (int i = 0; i < players; i++) {
            printf("\nPlayer %s's turn...\n", player_names[i]);
            printf("Guessed word: %s\n", guessed_word);

            char guess;
            printf("Guess a character: ");
            scanf(" %c", &guess); // note the space before %c to consume the newline character

            int correct_guess = 0;
            for (int j = 0; j < len; j++) {
                if (word[j] == guess) {
                    guessed_word[j] = guess;
                    correct_guess = 1;
                }
            }

            if (correct_guess) {
                printf("Correct guess!\n");
                scores[i]++;
            } else {
                printf("Incorrect guess!\n");
            }
        }

        int all_guessed = 1;
        for (int i = 0; i < len; i++) {
            if (guessed_word[i] == '_') {
                all_guessed = 0;
                break;
            }
        }

        if (all_guessed) {
            printf("\nAll players have guessed the word!\nThe word was: %s\n", word);
            for (int i = 0; i < players; i++) {
                printf("%s's score is: %d\n", player_names[i], scores[i]);
                if (scores[i] > max_score) {
                    max_score = scores[i];
                    winner_idx = i;
                }
            }
            break;
        }
    } while (1);

    printf("\n\nGame over!\n\nThe winner is: %s\n", player_names[winner_idx]);
    return 0;
}