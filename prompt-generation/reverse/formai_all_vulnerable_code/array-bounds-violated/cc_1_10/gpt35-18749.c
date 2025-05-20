//FormAI DATASET v1.0 Category: Spell checking ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if the word is a valid English word
int is_valid_word(char *word)
{
    /* This function can be replaced with any spell-checking API */

    // Let's assume all words are valid for our simplicity
    return 1;
}

// Function to correct the misspelled word
char* correct_word(char *word)
{
    /* This function can be replaced with any spell-checking API */

    // Let's assume no misspelled words for our simplicity
    return word;
}

int main()
{
    char input[1000];       // Input string
    char *word;             // Current word being processed
    int i, j = 0, len;      // Index variables
    int valid_flag;         // Flag indicating if the current word is valid
    char *corrected_word;   // Pointer to the corrected word

    printf("Enter a sentence: ");
    fgets(input, 1000, stdin);  // Take user input

    input[strlen(input)-1] = '\0';      // Removing the newline character

    // Loop through the entire input string
    for (i = 0; input[i] != '\0'; i++) {

        // If the character is not an alphabet, print it as is
        if (!isalpha(input[i])) {
            printf("%c", input[i]);
            continue;
        }

        // Extracting the word and converting it to lowercase
        for (j = i; isalpha(input[j]); j++)
            input[j] = tolower(input[j]);

        len = j-i;
        word = (char *) calloc(len+1, sizeof(char));

        // Copying the lowercase word to a new string
        strncpy(word, input+i, len);

        // Checking if the word is valid
        valid_flag = is_valid_word(word);

        // If not valid, correct it and print
        if (!valid_flag) {
            corrected_word = correct_word(word);
            printf("%s", corrected_word);
            free(corrected_word);
        }
        // If valid, print as is
        else {
            printf("%s", word);
        }

        i = j-1;
        free(word);
    }

    return 0;
}