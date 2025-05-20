//LLAMA2-13B DATASET v1.0 Category: Spell checking ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAGIC_WORD "SPELLCASTER"

void spell_check(char *word) {
    int i, j, k, l;
    char c, d, e, f;
    char misspell[10];

    // Initialize misspell array with all characters
    for (i = 0; i < 10; i++) {
        misspell[i] = 'a';
    }

    // Check each character of the word
    for (i = 0; word[i] != '\0'; i++) {
        c = word[i];

        // Check if the character is a letter
        if (isalpha(c)) {
            // Check if the character is in the correct position
            if (i < strlen(MAGIC_WORD) - 1 && MAGIC_WORD[i] == c) {
                // If the character is in the correct position, increment the corresponding position in the misspell array
                for (j = 0; j < i; j++) {
                    if (misspell[j] == MAGIC_WORD[i]) {
                        misspell[j]++;
                    }
                }
            } else {
                // If the character is not in the correct position, set the corresponding position in the misspell array to 0
                for (j = 0; j < i; j++) {
                    if (misspell[j] == MAGIC_WORD[i]) {
                        misspell[j] = 0;
                    }
                }
            }
        }
    }

    // Check if all characters in the word are in the correct position
    for (j = 0; j < 10; j++) {
        if (misspell[j] != 0) {
            break;
        }
    }

    // If all characters are in the correct position, print "Word is spelled correctly!"
    if (j == 10) {
        printf("Word is spelled correctly!\n");
    } else {
        // If all characters are not in the correct position, print "Word is misspelled!"
        printf("Word is misspelled!\n");
        for (j = 0; j < 10; j++) {
            if (misspell[j] != 0) {
                printf("Error at position %d: %c is not in the correct position\n", j, misspell[j]);
            }
        }
    }
}

int main() {
    char word[50];

    // Ask the user for a word to check
    printf("Enter a word to check: ");
    fgets(word, 50, stdin);

    // Check the word for spelling errors
    spell_check(word);

    return 0;
}