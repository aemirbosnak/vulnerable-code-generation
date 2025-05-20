//Code Llama-13B DATASET v1.0 Category: Spell checking ; Style: shocked
// A unique C spell checking example program in a shocked style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A function to check if a word is spelled correctly
int check_spelling(char *word) {
    // A list of correct words
    char *words[] = { "hello", "world", "computer", "science", "coding", "programming", "artificial", "intelligence" };
    int num_words = sizeof(words) / sizeof(char *);

    // Loop through the list of correct words and check if the input word matches any of them
    for (int i = 0; i < num_words; i++) {
        if (strcmp(word, words[i]) == 0) {
            return 1;
        }
    }

    // If the input word does not match any of the correct words, it is not spelled correctly
    return 0;
}

// A function to suggest corrections for a misspelled word
void suggest_corrections(char *word) {
    // A list of correct words
    char *words[] = { "hello", "world", "computer", "science", "coding", "programming", "artificial", "intelligence" };
    int num_words = sizeof(words) / sizeof(char *);

    // Loop through the list of correct words and check if any of them are similar to the input word
    for (int i = 0; i < num_words; i++) {
        if (strcmp(word, words[i]) != 0) {
            // If the input word is similar to a correct word, suggest the correct word as a correction
            printf("%s is a misspelling of %s\n", word, words[i]);
        }
    }
}

int main() {
    // Ask the user for input
    printf("Enter a word: ");
    char word[100];
    scanf("%s", word);

    // Check if the input word is spelled correctly
    if (check_spelling(word)) {
        printf("Correct spelling\n");
    } else {
        // If the input word is not spelled correctly, suggest corrections
        suggest_corrections(word);
    }

    return 0;
}