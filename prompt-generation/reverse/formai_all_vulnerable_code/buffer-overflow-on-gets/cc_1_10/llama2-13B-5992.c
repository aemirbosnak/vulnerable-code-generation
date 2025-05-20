//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 1024

void process_text(char *text) {
    char *word, *next_word;
    int i, j, k;
    size_t len = strlen(text);

    // Step 1: Tokenize the text
    for (i = 0; i < len; i++) {
        word = text + i;
        if (*word == ' ' || *word == '\t') {
            // Found a word boundary
            if (i > 0 && word[-1] != ' ') {
                // Last character of the previous word was not a space,
                // so we have a word boundary
                next_word = word + 1;
                while (*next_word == ' ' || *next_word == '\t') {
                    next_word++;
                }
                // Add the current word to the list
                if (i > 0) {
                    printf("Current word: %s\n", word);
                }
                // Skip to the next word
                i = next_word - text;
            }
        }
    }

    // Step 2: Shuffle the words
    for (i = 0; i < len; i++) {
        word = text + i;
        j = rand() % (i + 1);
        k = word[j];
        word[j] = word[i];
        word[i] = k;
    }

    // Step 3: Reconstruct the text
    for (i = 0; i < len; i++) {
        word = text + i;
        printf("%c", word[0]);
    }
}

int main() {
    char text[MAX_LENGTH];
    gets(text); // Read in the text from the user
    process_text(text);
    return 0;
}