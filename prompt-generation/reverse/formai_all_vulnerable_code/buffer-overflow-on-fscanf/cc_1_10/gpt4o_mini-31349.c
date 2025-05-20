//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define INITIAL_WORD_COUNT 10

typedef struct {
    char **words;
    int *frequencies;
    int size;
    int capacity;
} WordFrequency;

// Function to create a WordFrequency object
WordFrequency* createWordFrequency() {
    WordFrequency* wf = (WordFrequency*)malloc(sizeof(WordFrequency));
    wf->capacity = INITIAL_WORD_COUNT;
    wf->size = 0;
    wf->words = (char**)malloc(wf->capacity * sizeof(char*));
    wf->frequencies = (int*)malloc(wf->capacity * sizeof(int));
    return wf;
}

// Function to free the WordFrequency object
void freeWordFrequency(WordFrequency* wf) {
    for (int i = 0; i < wf->size; i++) {
        free(wf->words[i]);
    }
    free(wf->words);
    free(wf->frequencies);
    free(wf);
}

// Function to add or update a word frequency
void addWord(WordFrequency* wf, const char* word) {
    for (int i = 0; i < wf->size; i++) {
        if (strcmp(wf->words[i], word) == 0) {
            wf->frequencies[i]++;
            return;
        }
    }
    if (wf->size >= wf->capacity) {
        wf->capacity *= 2;
        wf->words = (char**)realloc(wf->words, wf->capacity * sizeof(char*));
        wf->frequencies = (int*)realloc(wf->frequencies, wf->capacity * sizeof(int));
    }
    wf->words[wf->size] = strdup(word);
    wf->frequencies[wf->size] = 1;
    wf->size++;
}

// Function to count letters in a file
int countLetters(FILE* file) {
    int count = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (isalpha(ch)) {
            count++;
        }
    }
    rewind(file); 
    return count;
}

// Function to count words and create a word frequency list
WordFrequency* processText(FILE* file) {
    char word[MAX_WORD_LENGTH];
    WordFrequency* wf = createWordFrequency();
    while (fscanf(file, "%s", word) == 1) {
        // Convert word to lowercase for consistency
        for (int i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }
        addWord(wf, word);
    }
    return wf;
}

// Function to output word frequencies
void outputWordFrequencies(WordFrequency* wf) {
    printf("Word Frequencies:\n");
    for (int i = 0; i < wf->size; i++) {
        printf("%s: %d\n", wf->words[i], wf->frequencies[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }
  
    FILE* file = fopen(argv[1], "r");
    if (!file) {
        perror("Could not open file");
        return EXIT_FAILURE;
    }

    // Count letters
    int letterCount = countLetters(file);
    printf("Total Letters: %d\n", letterCount);

    // Process text to get word frequencies
    WordFrequency* wf = processText(file);
    outputWordFrequencies(wf);

    // Clean up
    freeWordFrequency(wf);
    fclose(file);
    
    return EXIT_SUCCESS;
}