//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PLAYERS 4
#define MAX_WORDS 100

struct player {
    char name[20];
    int score;
};

struct word {
    char word[20];
    int length;
};

int main() {
    // Initialize the players and words
    struct player players[MAX_PLAYERS];
    struct word words[MAX_WORDS];

    // Read the players' names from the console
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", players[i].name);
    }

    // Read the words from the dictionary file
    FILE *file = fopen("dictionary.txt", "r");
    if (file == NULL) {
        printf("Error opening dictionary file!\n");
        return EXIT_FAILURE;
    }

    int num_words = 0;
    while (fscanf(file, "%s", words[num_words].word) != EOF) {
        words[num_words].length = strlen(words[num_words].word);
        num_words++;
    }

    fclose(file);

    // Start the game loop
    while (1) {
        // Display the current scores
        printf("\nScores:\n");
        for (int i = 0; i < MAX_PLAYERS; i++) {
            printf("%s: %d\n", players[i].name, players[i].score);
        }

        // Get the next word from the dictionary
        int word_index = rand() % num_words;
        char *word = words[word_index].word;

        // Display the word to the players
        printf("\nThe word is: %s\n", word);

        // Get the players' guesses
        char guesses[MAX_PLAYERS][20];
        for (int i = 0; i < MAX_PLAYERS; i++) {
            printf("Enter your guess, %s: ", players[i].name);
            scanf("%s", guesses[i]);
        }

        // Check the players' guesses
        for (int i = 0; i < MAX_PLAYERS; i++) {
            if (strcmp(guesses[i], word) == 0) {
                // The player guessed the word correctly
                players[i].score++;
                printf("%s guessed the word correctly!\n", players[i].name);
            } else {
                // The player guessed the word incorrectly
                printf("%s guessed the word incorrectly!\n", players[i].name);
            }
        }

        // Check if any player has reached the winning score
        for (int i = 0; i < MAX_PLAYERS; i++) {
            if (players[i].score >= 10) {
                // The player has reached the winning score
                printf("%s has won the game!\n", players[i].name);
                return EXIT_SUCCESS;
            }
        }
    }

    return EXIT_SUCCESS;
}