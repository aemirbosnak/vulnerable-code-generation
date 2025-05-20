//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_LENGTH 100

typedef struct {
    char word[MAX_LENGTH];
    int count;
} WordCount;

// Function to convert a string to lowercase
void toLowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char) str[i]);
    }
}

// Function to check if a word is already in the array
int findWord(WordCount *wordCounts, int uniqueCount, char *word) {
    for (int i = 0; i < uniqueCount; i++) {
        if (strcmp(wordCounts[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to sort words based on frequency
void sortWords(WordCount *wordCounts, int uniqueCount) {
    for (int i = 0; i < uniqueCount - 1; i++) {
        for (int j = 0; j < uniqueCount - i - 1; j++) {
            if (wordCounts[j].count < wordCounts[j + 1].count) {
                WordCount temp = wordCounts[j];
                wordCounts[j] = wordCounts[j + 1];
                wordCounts[j + 1] = temp;
            }
        }
    }
}

// Main function to count word frequencies
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    WordCount wordCounts[MAX_WORDS];
    int uniqueCount = 0;

    char buffer[MAX_LENGTH];

    while (fscanf(file, "%s", buffer) == 1) {
        toLowercase(buffer);
        
        // Strip punctuation from the word
        char *end = buffer + strlen(buffer) - 1;
        while (end >= buffer && ispunct(*end)) { 
            *end = '\0'; 
            end--;
        }

        int index = findWord(wordCounts, uniqueCount, buffer);
        if (index != -1) {
            wordCounts[index].count++;
        } else {
            strncpy(wordCounts[uniqueCount].word, buffer, MAX_LENGTH);
            wordCounts[uniqueCount].count = 1;
            uniqueCount++;
        }
    }

    fclose(file);

    // Sort based on frequency
    sortWords(wordCounts, uniqueCount);

    // Display the results
    printf("Word Frequency:\n");
    for (int i = 0; i < uniqueCount; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    return EXIT_SUCCESS;
}