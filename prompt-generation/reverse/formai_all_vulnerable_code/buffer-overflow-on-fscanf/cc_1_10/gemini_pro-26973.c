//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct _word_count {
    char word[MAX_WORD_LENGTH];
    int count;
} word_count;

int compare_word_counts(const void *a, const void *b) {
    const word_count *wc1 = (const word_count *)a;
    const word_count *wc2 = (const word_count *)b;

    return strcmp(wc1->word, wc2->word);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror(argv[1]);
        return EXIT_FAILURE;
    }

    word_count word_counts[MAX_WORDS];
    int word_count_index = 0;

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF) {
        // Convert the word to lowercase
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        // Check if the word is already in the word_counts array
        int found = 0;
        for (int i = 0; i < word_count_index; i++) {
            if (strcmp(word_counts[i].word, word) == 0) {
                word_counts[i].count++;
                found = 1;
                break;
            }
        }

        // If the word is not in the word_counts array, add it
        if (!found) {
            strcpy(word_counts[word_count_index].word, word);
            word_counts[word_count_index].count = 1;
            word_count_index++;
        }
    }

    fclose(file);

    // Sort the word_counts array by word
    qsort(word_counts, word_count_index, sizeof(word_count), compare_word_counts);

    // Print the word_counts array
    for (int i = 0; i < word_count_index; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    return EXIT_SUCCESS;
}