//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_LENGTH 100
#define THRESHOLD 3

typedef struct {
    char word[MAX_LENGTH];
    int count;
} WordCount;

int isWordChar(char c) {
    return isalpha(c) || c == '\'';
}

void toLowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int compare(const void *a, const void *b) {
    return ((WordCount *)b)->count - ((WordCount *)a)->count;
}

void summarizeText(const char *filename) {
    FILE *file;
    char word[MAX_LENGTH];
    WordCount words[MAX_WORDS];
    int uniqueWords = 0;

    // Initialize the word count array
    memset(words, 0, sizeof(words));

    // Open the input file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    // Read words from the file
    while (fscanf(file, "%s", word) == 1) {
        // Strip non-word characters
        char cleanWord[MAX_LENGTH];
        int j = 0;
        for (int i = 0; word[i]; i++) {
            if (isWordChar(word[i])) {
                cleanWord[j++] = word[i];
            }
        }
        cleanWord[j] = '\0';
        toLowercase(cleanWord);

        // Update word frequency
        int found = 0;
        for (int i = 0; i < uniqueWords; i++) {
            if (strcmp(words[i].word, cleanWord) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }

        // If the word is new, add it to the list
        if (!found && uniqueWords < MAX_WORDS) {
            strcpy(words[uniqueWords].word, cleanWord);
            words[uniqueWords].count = 1;
            uniqueWords++;
        }
    }
    fclose(file);

    // Sort words by frequency
    qsort(words, uniqueWords, sizeof(WordCount), compare);

    // Print the summary
    printf("Text Summary:\n");
    for (int i = 0; i < uniqueWords && words[i].count >= THRESHOLD; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    summarizeText(argv[1]);

    return 0;
}