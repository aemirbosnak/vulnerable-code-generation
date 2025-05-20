//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

typedef struct {
    char name[20];
    int score;
    int index;
} player;

typedef struct {
    char word[MAX_WORD_LEN];
    int correct;
} word;

int main() {
    srand(time(NULL));

    // Initialize players
    player players[MAX_PLAYERS];
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
        players[i].index = 0;
    }

    // Initialize dictionary
    word dictionary[MAX_WORDS];
    FILE *file = fopen("dictionary.txt", "r");
    if (file == NULL) {
        printf("Error opening dictionary file.\n");
        return 1;
    }
    int num_words = 0;
    while (fscanf(file, "%s", dictionary[num_words].word) != EOF) {
        dictionary[num_words].correct = 1;
        num_words++;
    }
    fclose(file);

    // Game loop
    while (1) {
        // Select a random word
        int word_index = rand() % num_words;
        char word[MAX_WORD_LEN];
        strcpy(word, dictionary[word_index].word);

        // Scramble the word
        for (int i = 0; i < strlen(word); i++) {
            int j = rand() % strlen(word);
            char temp = word[i];
            word[i] = word[j];
            word[j] = temp;
        }

        // Display the scrambled word
        printf("Scrambled word: %s\n", word);

        // Get guesses from players
        for (int i = 0; i < MAX_PLAYERS; i++) {
            printf("%s's turn: ", players[i].name);
            char guess[MAX_WORD_LEN];
            scanf("%s", guess);

            // Check if the guess is correct
            int correct = strcmp(guess, dictionary[word_index].word) == 0;

            // Update player's score
            if (correct) {
                players[i].score++;
            }

            // Update player's index
            players[i].index++;

            // Display the player's guess and score
            printf("%s guessed: %s\n", players[i].name, guess);
            printf("%s's score: %d\n", players[i].name, players[i].score);
        }

        // Check if the game is over
        int game_over = 1;
        for (int i = 0; i < MAX_PLAYERS; i++) {
            if (players[i].index < num_words) {
                game_over = 0;
            }
        }

        if (game_over) {
            break;
        }
    }

    // Print the final scores
    printf("Final scores:\n");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }

    return 0;
}