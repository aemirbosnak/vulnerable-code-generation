//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int compare(const void *a, const void *b) {
    return (*(WordCount *)b).count - (*(WordCount *)a).count;
}

int is_new_word(const char *word, WordCount wordList[], int wordCount) {
    for (int i = 0; i < wordCount; i++)
        if (strcmp(word, wordList[i].word) == 0)
            return i; // Return index if the word already exists

    return -1; // Return -1 if the word is new
}

void normalize_word(char *word) {
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        word[i] = tolower(word[i]);
    }
}

void print_word_counts(WordCount wordList[], int wordCount) {
    printf("Word Frequency Count:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", wordList[i].word, wordList[i].count);
    }
}

int main() {
    FILE *file;
    char filename[100];
    char ch;
    char currentWord[MAX_WORD_LEN];
    int wordListSize = 0;
    WordCount wordList[MAX_WORDS];

    printf("Enter the filename to analyze: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    int wordIndex = 0;
    while ((ch = fgetc(file)) != EOF) {
        if (isalnum(ch)) {
            currentWord[wordIndex++] = ch; // Constructing a word
        } else {
            if (wordIndex > 0) {
                currentWord[wordIndex] = '\0'; // Null-terminate the current word
                normalize_word(currentWord);

                int index = is_new_word(currentWord, wordList, wordListSize);
                if (index >= 0) {
                    wordList[index].count++;
                } else {
                    if (wordListSize < MAX_WORDS) {
                        strcpy(wordList[wordListSize].word, currentWord);
                        wordList[wordListSize].count = 1;
                        wordListSize++;
                    }
                }
                wordIndex = 0; // Reset for the next word
            }
        }
    }

    // Handle the last word if the file didn't end with a non-word character
    if (wordIndex > 0) {
        currentWord[wordIndex] = '\0';
        normalize_word(currentWord);

        int index = is_new_word(currentWord, wordList, wordListSize);
        if (index >= 0) {
            wordList[index].count++;
        } else {
            if (wordListSize < MAX_WORDS) {
                strcpy(wordList[wordListSize].word, currentWord);
                wordList[wordListSize].count = 1;
                wordListSize++;
            }
        }
    }

    fclose(file);

    // Sort word counts in descending order
    qsort(wordList, wordListSize, sizeof(WordCount), compare);
    
    // Print sorted word counts
    print_word_counts(wordList, wordListSize);

    return EXIT_SUCCESS;
}