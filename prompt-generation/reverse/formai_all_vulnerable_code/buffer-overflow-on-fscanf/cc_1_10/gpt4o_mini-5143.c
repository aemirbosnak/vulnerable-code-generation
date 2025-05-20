//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: shape shifting
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

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int addOrUpdateWord(WordFrequency *wordList, int *wordCount, const char *word) {
    for (int i = 0; i < *wordCount; i++) {
        if (strcmp(wordList[i].word, word) == 0) {
            wordList[i].count++;
            return *wordCount;
        }
    }
    
    strcpy(wordList[*wordCount].word, word);
    wordList[*wordCount].count = 1;
    (*wordCount)++;
    return *wordCount;
}

void printWordFrequencies(WordFrequency *wordList, int wordCount) {
    int maxCount = 0;
    for (int i = 0; i < wordCount; i++) {
        if (wordList[i].count > maxCount) {
            maxCount = wordList[i].count;
        }
    }

    // Shape-shifting display
    printf("\nWord Frequencies:\n");
    for (int i = 0; i < wordCount; i++) {
        int barLength = (wordList[i].count * 50) / maxCount;  // scaling for display
        
        // Display the word
        printf("%s: ", wordList[i].word);
        for (int j = 0; j < barLength; j++) {
            if (j % 2 == 0) {
                printf("*");  // even character display
            } else {
                printf("-");  // odd character display
            }
        }
        printf(" (%d)\n", wordList[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    WordFrequency wordList[MAX_WORDS];
    int wordCount = 0;
    char buffer[MAX_WORD_LENGTH];

    while (fscanf(file, "%s", buffer) != EOF) {
        // Clean the word by removing punctuation
        char cleanWord[MAX_WORD_LENGTH] = "";
        int k = 0;
        
        for (int i = 0; buffer[i] != '\0'; i++) {
            if (isalpha(buffer[i])) {
                cleanWord[k++] = buffer[i];
            }
        }
        
        cleanWord[k] = '\0'; // null terminate the string

        // Convert to lower case
        toLowerCase(cleanWord);
        
        if (strlen(cleanWord) > 0) {
            addOrUpdateWord(wordList, &wordCount, cleanWord);
        }
    }

    fclose(file);
    
    printWordFrequencies(wordList, wordCount);
    
    return 0;
}