//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compare(const void *a, const void *b) {
    return ((WordCount *)b)->count - ((WordCount *)a)->count;
}

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void processFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open file");
        return;
    }

    WordCount wordCounts[MAX_WORDS] = {0};
    int wordCountIndex = 0;

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF) {
        toLowerCase(word);

        // Check if the word is already in wordCounts
        int found = 0;
        for (int i = 0; i < wordCountIndex; i++) {
            if (strcmp(wordCounts[i].word, word) == 0) {
                wordCounts[i].count++;
                found = 1;
                break;
            }
        }

        // If it's a new word, add it
        if (!found && wordCountIndex < MAX_WORDS) {
            strcpy(wordCounts[wordCountIndex].word, word);
            wordCounts[wordCountIndex].count = 1;
            wordCountIndex++;
        }
    }

    fclose(file);

    // Sort the words based on their counts
    qsort(wordCounts, wordCountIndex, sizeof(WordCount), compare);

    // Display the results
    printf("Word Frequency:\n");
    for (int i = 0; i < wordCountIndex; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    processFile(argv[1]);

    return EXIT_SUCCESS;
}