//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: curious
// A memory game with a twist

#include <stdio.h>
#include <stdlib.h>

#define MAX_WORDS 20

int main() {
    char **words = (char **)malloc(MAX_WORDS * sizeof(char *));
    for (int i = 0; i < MAX_WORDS; i++) {
        words[i] = (char *)malloc(20 * sizeof(char));
    }

    // Fill the words with random text
    for (int i = 0; i < MAX_WORDS; i++) {
        for (int j = 0; j < 20; j++) {
            words[i][j] = rand() % 26 + 97;
        }
    }

    // Create a hash table to store the words
    int hash_table[MAX_WORDS];
    for (int i = 0; i < MAX_WORDS; i++) {
        hash_table[i] = -1;
    }

    // Play the game
    int round = 0;
    while (round < 5) {
        // Get the word from the user
        char word[20];
        printf("Enter a word: ");
        scanf("%s", word);

        // Check if the word is in the hash table
        int found = 0;
        for (int i = 0; i < MAX_WORDS; i++) {
            if (strcmp(word, words[i]) == 0) {
                found = 1;
                break;
            }
        }

        // If the word is not found, add it to the table
        if (!found) {
            for (int i = 0; i < MAX_WORDS; i++) {
                if (hash_table[i] == -1) {
                    hash_table[i] = round;
                    words[i] = word;
                    break;
                }
            }
        }

        // Increment the round
        round++;
    }

    // Print the results
    printf("The words you entered in order are:\n");
    for (int i = 0; i < MAX_WORDS; i++) {
        if (hash_table[i] != -1) {
            printf("%s ", words[i]);
        }
    }

    // Free the memory
    for (int i = 0; i < MAX_WORDS; i++) {
        free(words[i]);
    }
    free(words);

    return 0;
}