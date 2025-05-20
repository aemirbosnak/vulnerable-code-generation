//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordFrequency;

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int addWord(WordFrequency *wordFreqs, int *totalWords, char *word) {
    for (int i = 0; i < *totalWords; i++) {
        if (strcmp(wordFreqs[i].word, word) == 0) {
            wordFreqs[i].count++;
            return 1;
        }
    }
    strcpy(wordFreqs[*totalWords].word, word);
    wordFreqs[*totalWords].count = 1;
    (*totalWords)++;
    return 0;
}

void sortWordFrequency(WordFrequency *wordFreqs, int totalWords) {
    for (int i = 0; i < totalWords - 1; i++) {
        for (int j = 0; j < totalWords - i - 1; j++) {
            if (wordFreqs[j].count < wordFreqs[j + 1].count) {
                WordFrequency temp = wordFreqs[j];
                wordFreqs[j] = wordFreqs[j + 1];
                wordFreqs[j + 1] = temp;
            }
        }
    }
}

void printWordFrequency(WordFrequency *wordFreqs, int totalWords) {
    printf("Word Frequency:\n");
    for (int i = 0; i < totalWords; i++) {
        printf("%s: %d\n", wordFreqs[i].word, wordFreqs[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    WordFrequency wordFreqs[MAX_WORDS];
    int totalWords = 0;
    char word[MAX_WORD_LEN];

    while (fscanf(file, "%s", word) != EOF) {
        toLowerCase(word); // Convert word to lowercase
        // Filter out punctuation
        char *cleanedWord = strtok(word, " ,.!?;");
        if (cleanedWord != NULL) {
            addWord(wordFreqs, &totalWords, cleanedWord);
        }
    }

    fclose(file);

    sortWordFrequency(wordFreqs, totalWords);
    printWordFrequency(wordFreqs, totalWords);

    return EXIT_SUCCESS;
}