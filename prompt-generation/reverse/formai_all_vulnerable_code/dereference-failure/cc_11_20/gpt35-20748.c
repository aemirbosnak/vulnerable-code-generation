//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: authentic
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 2000
#define MAX_WORD_LENGTH 20

int get_word(char *word);

int main(int argc, const char *argv[]) {
    int i, j, counter;
    char *words[MAX_WORDS], word[MAX_WORD_LENGTH];
    int frequency[MAX_WORDS] = { 0 };

    // Get all words from input
    printf("Please enter text: \n");
    i = 0;
    while (get_word(word) != EOF) {
        if (strlen(word) > 1) {
            words[i] = strdup(word);
            i++;
        }

        if (i >= MAX_WORDS) {
            printf("Maximum words reached. No more counting.\n");
            break;
        }
    }

    // Do the frequency counting
    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i] == NULL) {
            break;
        }

        // Look for words with same string
        counter = 1;
        for (j = i + 1; j < MAX_WORDS; j++) {
            if (words[j] != NULL && strcmp(words[i], words[j]) == 0) {
                free(words[j]);   // Release memory of duplicate word
                words[j] = NULL;  // Remove from consideration
                counter++;
            }
        }

        frequency[i] = counter;
    }

    // Print out the frequency table
    printf("\nWord frequency table:\n");
    printf("======================\n");

    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i] == NULL) {
            break;
        }

        printf("%-20s%d\n", words[i], frequency[i]);
        free(words[i]);
    }

    return 0;
}

int get_word(char *word) {
    int c, i;

    // Read past any non-alphabetic characters
    while ((c = getchar()) != EOF && !isalpha(c))
        ;

    if (c == EOF) {
        return EOF;
    }

    // Build the word character by character
    i = 0;
    do {
        word[i] = tolower(c);
        i++;
    } while ((c = getchar()) != EOF && isalpha(c) && i < MAX_WORD_LENGTH);

    // Terminate the word string
    word[i] = '\0';

    // If the word is too long, read past the rest of it
    if (c != EOF && isalpha(c)) {
        while ((c = getchar()) != EOF && isalpha(c))
            ;
    }

    return word[0];
}