//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000

int main(void) {
    char input[MAX_WORD_LENGTH];
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int freq[MAX_WORDS];
    int unique_words = 0;
    int total_words = 0;
    int i, j;

    do {
        printf("Enter a word (or 'q' to quit): ");
        scanf("%s", input);

        if (strcmp(input, "q") != 0) {
            /* Convert word to lowercase */
            for (i = 0; input[i]; i++) {
                input[i] = tolower(input[i]);
            }

            /* Check if word is already in words array */
            for (i = 0; i < unique_words; i++) {
                if (strcmp(input, words[i]) == 0) {
                    freq[i]++;
                    total_words++;
                    break;
                }
            }

            /* Add new word if it isn't already in words array */
            if (i == unique_words) {
                strcpy(words[unique_words], input);
                freq[unique_words] = 1;
                unique_words++;
                total_words++;
            }
        }
    } while (strcmp(input, "q") != 0);

    /* Print out word frequency table */
    printf("\nWord\t\tFrequency\n");
    printf("----\t\t---------\n");

    for (i = 0; i < unique_words; i++) {
        printf("%-15s%d\n", words[i], freq[i]);
    }

    /* Print out total words entered */
    printf("\nTotal words entered: %d\n", total_words);

    return 0;
}