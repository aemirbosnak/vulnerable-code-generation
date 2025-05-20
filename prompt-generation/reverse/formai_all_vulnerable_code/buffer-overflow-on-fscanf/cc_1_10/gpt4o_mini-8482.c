//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compare(const void *a, const void *b) {
    WordFrequency *wf1 = (WordFrequency *)a;
    WordFrequency *wf2 = (WordFrequency *)b;
    return wf2->count - wf1->count; // Sort in descending order
}

void to_lowercase(char *str) {
    for (; *str; str++) {
        *str = tolower(*str);
    }
}

int main() {
    FILE *file;
    char filename[100], word[MAX_WORD_LENGTH];
    WordFrequency wordList[MAX_WORDS] = {0};
    int totalWords = 0, found;

    printf("Welcome to the Word Frequency Counter!\n");
    printf("Please enter the name of the text file (with .txt extension): ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    while (fscanf(file, "%s", word) != EOF) {
        to_lowercase(word);
        found = 0;

        // Check if the word is already in the list
        for (int i = 0; i < totalWords; i++) {
            if (strcmp(wordList[i].word, word) == 0) {
                wordList[i].count++;
                found = 1;
                break;
            }
        }

        // If the word was not found, add it to the list
        if (!found && totalWords < MAX_WORDS) {
            strcpy(wordList[totalWords].word, word);
            wordList[totalWords].count = 1;
            totalWords++;
        }
    }
    fclose(file);

    // Sort the word frequency list
    qsort(wordList, totalWords, sizeof(WordFrequency), compare);

    printf("\nWord Frequency Count:\n");
    printf("----------------------\n");

    // Display words and their frequencies
    for (int i = 0; i < totalWords; i++) {
        printf("%s: %d\n", wordList[i].word, wordList[i].count);
    }

    printf("----------------------\n");
    printf("Total unique words: %d\n", totalWords);
    printf("Thank you for using the Word Frequency Counter!\n");

    return 0;
}