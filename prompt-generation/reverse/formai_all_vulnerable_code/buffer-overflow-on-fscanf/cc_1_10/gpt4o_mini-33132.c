//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_LENGTH 100

// Structure to store words and their counts
typedef struct {
    char word[MAX_LENGTH];
    int count;
} WordCount;

// Function to compare two words for qsort
int compareWords(const void *a, const void *b) {
    WordCount *wc1 = (WordCount *)a;
    WordCount *wc2 = (WordCount *)b;
    return wc1->count - wc2->count;
}

// Function to add a word to the list or update its count
void addWord(WordCount *wordCounts, int *wordCount, const char *word) {
    for (int i = 0; i < *wordCount; i++) {
        if (strcmp(wordCounts[i].word, word) == 0) {
            wordCounts[i].count++;
            return;
        }
    }
    // New word, add to the array
    strcpy(wordCounts[*wordCount].word, word);
    wordCounts[*wordCount].count = 1;
    (*wordCount)++;
}

void printWordCounts(WordCount *wordCounts, int wordCount) {
    printf("Word Count Results:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

void freeMemory(WordCount *wordCounts) {
    free(wordCounts);
}

int main() {
    printf("Welcome to the C Word Count Tool!\n");
    printf("This tool will read a text file and count the occurrences of each word.\n");
    
    char filename[MAX_LENGTH];
    printf("Please enter the filename (with extension) to analyze: ");
    scanf("%s", filename);
    
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    
    WordCount *wordCounts = (WordCount *)malloc(MAX_WORDS * sizeof(WordCount));
    if (wordCounts == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        return EXIT_FAILURE;
    }
    
    char buffer[MAX_LENGTH];
    int wordCount = 0;
    
    // Read words from the file
    while (fscanf(file, "%s", buffer) != EOF) {
        // Preprocessing: remove punctuation and convert to lowercase
        for (int i = 0; buffer[i]; i++) {
            if (ispunct(buffer[i])) {
                buffer[i] = ' ';
            }
            buffer[i] = tolower(buffer[i]);
        }

        // Add word to list
        addWord(wordCounts, &wordCount, buffer);
    }
    
    fclose(file);
    
    // Sort word counts in descending order
    qsort(wordCounts, wordCount, sizeof(WordCount), compareWords);

    // Print the word counts
    printWordCounts(wordCounts, wordCount);

    // Free allocated memory
    freeMemory(wordCounts);
    
    printf("Thank you for using the C Word Count Tool!\n");
    return EXIT_SUCCESS;
}