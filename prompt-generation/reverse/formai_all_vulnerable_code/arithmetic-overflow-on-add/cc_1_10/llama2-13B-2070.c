//LLAMA2-13B DATASET v1.0 Category: Word Count Tool ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORD_LENGTH 20
#define MAX_WORDS 100

// Structure to store word count data
typedef struct {
    int word_count[MAX_WORDS];
} word_count_t;

// Function to count words in a given string
void word_count(const char *str, word_count_t *word_counts) {
    char *word = strtok(str, " ");
    int i = 0;

    while (word != NULL) {
        // Check if word is too long
        if (strlen(word) > MAX_WORD_LENGTH) {
            word_counts->word_count[i]++;
            word = strtok(NULL, " ");
        } else {
            word_counts->word_count[0]++;
            word = NULL;
        }
        i++;
    }
}

int main() {
    // Create a word count structure
    word_count_t word_counts;

    // Read a file or input a string
    char str[100];
    printf("Enter a string or file name: ");
    fgets(str, 100, stdin);

    // Count words in the input
    word_count(str, &word_counts);

    // Print the word count
    printf("Word Count:\n");
    for (int i = 0; i < MAX_WORDS; i++) {
        printf("%d: %s\n", i, word_counts.word_count[i] > 0 ? "Word" : "Empty");
    }

    return 0;
}