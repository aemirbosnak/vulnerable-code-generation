//LLAMA2-13B DATASET v1.0 Category: Word Count Tool ; Style: careful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 20
#define MAX_WORDS 100

struct word {
    char *word;
    int count;
};

int main() {
    char input[100];
    struct word words[MAX_WORDS];
    int i, j, word_count = 0;

    // Ask user for input text
    printf("Enter text: ");
    fgets(input, 100, stdin);

    // Tokenize input text into words
    for (i = 0; input[i] != '\0'; i++) {
        if (isspace(input[i])) {
            // Check if current character is a space
            if (word_count > 0) {
                // If current character is a space and there are words in the buffer,
                // then process the current word
                words[word_count].word = input + j;
                words[word_count].count = i - j;
                j = i + 1;
                word_count++;
            }
        }
    }

    // Process remaining words
    for (; j < i; j++) {
        if (!isspace(input[j])) {
            words[word_count].word = input + j;
            words[word_count].count = i - j;
            word_count++;
        }
    }

    // Print word count and words
    printf("Word count: %d\n", word_count);
    for (i = 0; i < word_count; i++) {
        printf("%d: %s\n", i + 1, words[i].word);
    }

    return 0;
}