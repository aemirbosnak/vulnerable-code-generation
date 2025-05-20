//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *word;
    int correct;
} Word;

typedef struct {
    char *name;
    int score;
    int num_words;
    Word *words;
} Player;

int main() {
    // Initialize the dictionary
    char *dictionary[] = {"apple", "banana", "cherry", "dog", "elephant", "fish", "grape", "house", "ice cream", "juice"};
    int num_words_in_dictionary = sizeof(dictionary) / sizeof(char *);

    // Initialize the players
    Player players[] = {
        {"Alice", 0, 0, NULL},
        {"Bob", 0, 0, NULL},
        {"Carol", 0, 0, NULL},
        {"Dave", 0, 0, NULL},
        {"Eve", 0, 0, NULL}
    };
    int num_players = sizeof(players) / sizeof(Player);

    // Initialize the game state
    int current_player_index = 0;
    int current_word_index = 0;

    // Game loop
    while (1) {
        // Get the current player's name
        char *current_player_name = players[current_player_index].name;

        // Get the current word
        char *current_word = dictionary[current_word_index];

        // Display the current word to the player
        printf("%s, it's your turn! Spell the word '%s': ", current_player_name, current_word);

        // Get the player's input
        char input[100];
        scanf("%s", input);

        // Check if the player's input is correct
        int correct = strcmp(input, current_word) == 0;

        // Update the player's score
        if (correct) {
            players[current_player_index].score++;
        }

        // Update the player's word list
        players[current_player_index].words = realloc(players[current_player_index].words, (players[current_player_index].num_words + 1) * sizeof(Word));
        players[current_player_index].words[players[current_player_index].num_words].word = strdup(current_word);
        players[current_player_index].words[players[current_player_index].num_words].correct = correct;
        players[current_player_index].num_words++;

        // Update the current word index
        current_word_index++;

        // Check if the game is over
        if (current_word_index == num_words_in_dictionary) {
            break;
        }

        // Update the current player index
        current_player_index++;
        if (current_player_index == num_players) {
            current_player_index = 0;
        }
    }

    // Display the final scores
    printf("Final scores:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }

    // Free the allocated memory
    for (int i = 0; i < num_players; i++) {
        for (int j = 0; j < players[i].num_words; j++) {
            free(players[i].words[j].word);
        }
        free(players[i].words);
    }

    return 0;
}