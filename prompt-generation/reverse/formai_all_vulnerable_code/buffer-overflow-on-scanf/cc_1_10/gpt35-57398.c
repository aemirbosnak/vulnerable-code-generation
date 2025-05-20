//FormAI DATASET v1.0 Category: Spell checking ; Style: funny
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void print_header() {
    printf("\n----------------------------------------------------");
    printf("\n        Welcome to the Spell Checker Program!");
    printf("\n----------------------------------------------------\n");
}

int main() {
    // Start by printing a header to welcome the user
    print_header();

    // Ask the user for a word to spell check
    char word[25];
    printf("\nEnter a word to check its spelling: ");
    scanf("%s", word);

    int i, j;
    int word_length = strlen(word);

    // Convert the word to lowercase
    for (i = 0; i < word_length; i++) {
        word[i] = tolower(word[i]);
    }

    // Define some sample words for spell checking
    char dictionary[10][25] = {"cat", "dog", "pig", "bird", "elephant", "monkey", "giraffe", "zebra", "lion", "tiger"};

    // Check if the word is in the dictionary
    int found_word = 0;
    for (i = 0; i < 10; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            printf("The word '%s' is spelled correctly!\n", word);
            found_word = 1;
            break;
        }
    }

    // If the word was not found, try to find some close matches
    if (found_word == 0) {
        printf("\nOops! It looks like the word '%s' is spelled incorrectly!\n", word);
        printf("Here are some suggested words:\n");

        // Check for words with one letter difference
        for (i = 0; i < 10; i++) {
            int word_distance = 0;
            int dictionary_length = strlen(dictionary[i]);

            if (word_length != dictionary_length) {
                continue;
            }
            
            for (j = 0; j < word_length; j++) {
                if (word[j] != dictionary[i][j]) {
                    word_distance++;
                }
            }

            if (word_distance == 1) {
                printf("- %s\n", dictionary[i]);
            }
        }

        // Check for words with two letter differences
        for (i = 0; i < 10; i++) {
            int word_distance = 0;
            int dictionary_length = strlen(dictionary[i]);

            if (word_length != dictionary_length) {
                continue;
            }
            
            for (j = 0; j < word_length; j++) {
                if (word[j] != dictionary[i][j]) {
                    word_distance++;
                }
            }

            if (word_distance == 2) {
                printf("- %s\n", dictionary[i]);
            }
        }

        // If no match was found, suggest a funny option
        if (found_word == 0) {
            printf("\nWe couldn't find any close matches...\n");
            printf("Maybe try spelling it backwards? Here's an example - %s = ", word);

            // Print the word spelled backwards
            for (i = word_length-1; i >= 0; i--) {
                printf("%c", word[i]);
            }
            printf("\n");
        }
    }

    // Finish with a closing message
    printf("\nThanks for using the Spell Checker Program. Have a nice day!\n");

    return 0;
}