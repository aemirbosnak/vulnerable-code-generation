//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

// Struct to hold word statistics
typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordStat;

// Function to compare two WordStat structs (for qsort)
int compare(const void *a, const void *b) {
    WordStat *wordStatA = (WordStat *)a;
    WordStat *wordStatB = (WordStat *)b;
    return wordStatB->frequency - wordStatA->frequency; // Descending order
}

// Function to find a word in the list
int findWord(WordStat *wordStats, int count, const char *word) {
    for (int i = 0; i < count; i++) {
        if (strcmp(wordStats[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    WordStat wordStats[MAX_WORDS];
    int totalWords = 0;
    char input[MAX_WORD_LENGTH];
    int totalLength = 0;

    printf("Enter up to %d words (type 'exit' to finish):\n", MAX_WORDS);
    
    while (totalWords < MAX_WORDS) {
        printf("Word %d: ", totalWords + 1);
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            break; // Exit when the user types "exit"
        }

        int index = findWord(wordStats, totalWords, input);
        
        if (index != -1) {
            wordStats[index].frequency++;
        } else {
            // Add new word to the statistics
            strcpy(wordStats[totalWords].word, input);
            wordStats[totalWords].frequency = 1;
            totalWords++;
        }

        totalLength += strlen(input);
    }

    // Calculate average word length
    double averageLength = totalWords > 0 ? (double)totalLength / totalWords : 0.0;
    
    // Sort words by frequency
    qsort(wordStats, totalWords, sizeof(WordStat), compare);
    
    // Display results
    printf("\nStatistics:\n");
    printf("Total unique words: %d\n", totalWords);
    if(totalWords > 0) {
        printf("Average word length: %.2f\n", averageLength);
        printf("Most frequent words:\n");
        for (int i = 0; i < totalWords; i++) {
            printf("%s: %d\n", wordStats[i].word, wordStats[i].frequency);
        }
        // Find the longest word
        char longestWord[MAX_WORD_LENGTH] = "";
        for (int i = 0; i < totalWords; i++) {
            if (strlen(wordStats[i].word) > strlen(longestWord)){
                strcpy(longestWord, wordStats[i].word);
            }
        }
        printf("Longest word: %s\n", longestWord);
    } else {
        printf("No words were entered.\n");
    }

    return 0;
}