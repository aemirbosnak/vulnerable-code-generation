//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000

// Define a structure to keep track of each unique word
struct word {
    char text[MAX_WORD_LENGTH];
    int count;
};

// Define a function to compare words for sorting
int compare_words(const void *a, const void *b) {
    struct word *wordA = (struct word *)a;
    struct word *wordB = (struct word *)b;

    return strcmp(wordA->text, wordB->text);
}

int main(void) {
    char input[MAX_WORD_LENGTH];
    int word_count = 0;

    struct word words[MAX_WORDS];

    // Get text input from user
    printf("Enter your text here: ");
    while (scanf("%s", input) == 1 && word_count < MAX_WORDS) {
        int len = strlen(input);

        // Strip non-alphabetical characters from input
        for (int i = 0; i < len; i++) {
            input[i] = tolower(input[i]);
            if (!isalpha(input[i])) {
                for (int j = i; j < len; j++) {
                    input[j] = input[j+1];
                }
                len--;
                i--;
            }
        }

        // Check if word already exists in words array, increment count
        int found = 0;
        for (int i = 0; i < word_count; i++) {
            if (strcmp(words[i].text, input) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }

        // If word not found in words array, add it
        if (!found) {
            strcpy(words[word_count].text, input);
            words[word_count].count = 1;
            word_count++;
        }
    }

    // Sort words array alphabetically
    qsort(words, word_count, sizeof(struct word), compare_words);

    // Print out word frequency count
    printf("\nHere are the unique words in your text and their frequency:\n");
    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", words[i].text, words[i].count);
    }

    return 0;
}