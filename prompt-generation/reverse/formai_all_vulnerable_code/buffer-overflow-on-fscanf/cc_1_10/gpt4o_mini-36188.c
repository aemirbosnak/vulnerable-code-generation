//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void insertOrIncrement(WordCount *wordCounts, int *size, const char *word) {
    for (int i = 0; i < *size; i++) {
        if (strcmp(wordCounts[i].word, word) == 0) {
            wordCounts[i].count++;
            return;
        }
    }
    strcpy(wordCounts[*size].word, word);
    wordCounts[*size].count = 1;
    (*size)++;
}

void sortWordCounts(WordCount *wordCounts, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (wordCounts[i].count < wordCounts[j].count) {
                WordCount temp = wordCounts[i];
                wordCounts[i] = wordCounts[j];
                wordCounts[j] = temp;
            }
        }
    }
}

void printWordCounts(WordCount *wordCounts, int size) {
    printf("\nWord Frequency Analysis:\n");
    for (int i = 0; i < size; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

void freeResources(WordCount *wordCounts) {
    // Free allocated resources if any (not necessary in this case, but keeping for future-proofing)
    free(wordCounts);
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    WordCount *wordCounts = malloc(sizeof(WordCount) * MAX_WORDS);
    if (wordCounts == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        fclose(file);
        return 1;
    }
    
    char word[MAX_WORD_LENGTH];
    int size = 0;

    while (fscanf(file, "%s", word) != EOF) {
        // Clean the word by removing punctuation (if needed)
        for (int i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
            if (ispunct(word[i])) {
                word[i] = '\0';
                break;
            }
        }

        if (strlen(word) > 0) {
            insertOrIncrement(wordCounts, &size, word);
        }
    }

    fclose(file);
    
    sortWordCounts(wordCounts, size);

    printWordCounts(wordCounts, size);

    freeResources(wordCounts);
    
    return 0;
}