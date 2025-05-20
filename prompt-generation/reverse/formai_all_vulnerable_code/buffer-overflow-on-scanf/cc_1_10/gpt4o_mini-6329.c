//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compare(const void *a, const void *b) {
    WordFrequency *wfA = (WordFrequency *)a;
    WordFrequency *wfB = (WordFrequency *)b;

    if (wfA->count < wfB->count) return 1;  // Descending order
    else if (wfA->count > wfB->count) return -1;
    else return 0;  
}

void toLowerCase(char *word) {
    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
}

int isValidCharacter(char ch) {
    return isalpha(ch) || ch == '\'';  // Allows for words with apostrophes
}

int main() {
    FILE *file;
    char filename[100];
    WordFrequency wordFreq[MAX_WORDS];
    int wordCount = 0;

    printf("Enter the name of the file to analyze: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file: %s\n", filename);
        return 1;
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) == 1) {
        // Process the word
        char processedWord[MAX_WORD_LENGTH];
        int j = 0;

        for (int i = 0; word[i]; i++) {
            if (isValidCharacter(word[i])) {
                processedWord[j++] = word[i];
            }
        }
        processedWord[j] = '\0';  // Null-terminate the string

        toLowerCase(processedWord);  // Convert to lower case

        // Check if the word already exists in the array
        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(wordFreq[i].word, processedWord) == 0) {
                wordFreq[i].count++;
                found = 1;
                break;
            }
        }

        // If word is new, add it to the frequency list
        if (!found && wordCount < MAX_WORDS) {
            strcpy(wordFreq[wordCount].word, processedWord);
            wordFreq[wordCount].count = 1;
            wordCount++;
        }
    }

    fclose(file);

    // Sort the words based on frequency
    qsort(wordFreq, wordCount, sizeof(WordFrequency), compare);

    // Display the result
    printf("\nWord Frequency:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", wordFreq[i].word, wordFreq[i].count);
    }

    return 0;
}