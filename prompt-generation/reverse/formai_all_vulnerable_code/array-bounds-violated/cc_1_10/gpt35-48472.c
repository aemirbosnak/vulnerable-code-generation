//FormAI DATASET v1.0 Category: Spell checking ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_LENGTH 30

int main() {
    char word[WORD_LENGTH];
    char dictionary[WORD_LENGTH];
    FILE *dict_file;
    int found;

    // Open the dictionary file
    dict_file = fopen("dictionary.txt", "r");
    if (dict_file == NULL) {
        printf("Error opening dictionary file");
        exit(1);
    }

    // Prompt the user to enter a word
    printf("Please enter a word: ");
    scanf("%s", word);

    // Remove any newline characters from the input
    int len = strlen(word);
    if (word[len-1] == '\n') {
        word[len-1] = '\0';
    }

    // Check if the word is in the dictionary
    found = 0;
    while (fgets(dictionary, WORD_LENGTH, dict_file) != NULL) {
        if (strcmp(dictionary, word) == 0) {
            found = 1;
            break;
        }
    }

    // Report the result
    if (found) {
        printf("The word '%s' is spelled correctly.\n", word);
    } else {
        printf("The word '%s' is misspelled.\n", word);
    }

    // Close the dictionary file
    fclose(dict_file);

    return 0;
}