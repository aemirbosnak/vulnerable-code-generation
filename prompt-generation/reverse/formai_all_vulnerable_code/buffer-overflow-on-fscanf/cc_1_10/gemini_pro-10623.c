//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: statistical
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// Structure to store word and its frequency
typedef struct {
    char *word;
    int frequency;
} Word;

// Comparison function for sorting words by frequency
int compareWords(const void *a, const void *b) {
    const Word *w1 = (const Word *)a;
    const Word *w2 = (const Word *)b;
    return w2->frequency - w1->frequency;
}

// Function to free memory allocated for words
void freeWords(Word *words, int n) {
    for (int i = 0; i < n; i++) {
        free(words[i].word);
    }
    free(words);
}

// Function to count word frequencies in a text file
Word *countWordFrequencies(const char *filename, int *n) {
    // Open file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Count words
    int wordCount = 0;
    int maxWordLength = 100;
    char *word = malloc(maxWordLength + 1);
    while (fscanf(file, "%s", word) != EOF) {
        wordCount++;
    }
    fclose(file);
    
    // Read file again and store word frequencies
    Word *words = malloc(wordCount * sizeof(Word));
    int i = 0;
    file = fopen(filename, "r");
    while (fscanf(file, "%s", word) != EOF) {
        // Convert word to lowercase
        for (int j = 0; j < strlen(word); j++) {
            word[j] = tolower(word[j]);
        }
        
        // Check if word already exists in array
        int found = 0;
        for (int k = 0; k < i; k++) {
            if (strcmp(words[k].word, word) == 0) {
                words[k].frequency++;
                found = 1;
                break;
            }
        }
        
        // If word not found, add it to array
        if (!found) {
            words[i].word = malloc(maxWordLength + 1);
            strcpy(words[i].word, word);
            words[i].frequency = 1;
            i++;
        }
    }
    *n = i;
    fclose(file);
    
    // Sort words by frequency
    qsort(words, i, sizeof(Word), compareWords);
    
    return words;
}

// Print word frequencies
void printWordFrequencies(const Word *words, int n) {
    printf("Word frequencies:\n");
    for (int i = 0; i < n; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return EXIT_FAILURE;
    }

    int n;
    Word *words = countWordFrequencies(argv[1], &n);
    if (words == NULL) {
        return EXIT_FAILURE;
    }

    printWordFrequencies(words, n);
    freeWords(words, n);

    return EXIT_SUCCESS;
}