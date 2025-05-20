//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int isWord(char c) {
    return (isalnum(c) || c == '\'' || c == '-');
}

void addWord(WordCount *words, int *numWords, const char *newWord) {
    for (int i = 0; i < *numWords; i++) {
        if (strcmp(words[i].word, newWord) == 0) {
            words[i].count++;
            return;
        }
    }
    if (*numWords < MAX_WORDS) {
        strcpy(words[*numWords].word, newWord);
        words[*numWords].count = 1;
        (*numWords)++;
    }
}

void wordFrequencyCounter(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Doomed! Cannot open file: %s\n", filename);
        return;
    }

    WordCount words[MAX_WORDS];
    int numWords = 0;
    char buffer[MAX_WORD_LENGTH];

    while (fscanf(file, "%s", buffer) != EOF) {
        char currentWord[MAX_WORD_LENGTH];
        int index = 0;

        for (int i = 0; buffer[i]; i++) {
            if (isWord(buffer[i])) {
                currentWord[index++] = buffer[i];
            } else {
                if (index > 0) {
                    currentWord[index] = '\0';
                    toLowerCase(currentWord);
                    addWord(words, &numWords, currentWord);
                    index = 0; // Reset index for next word
                }
            }
        }

        // If there's a word at the end of the buffer
        if (index > 0) {
            currentWord[index] = '\0';
            toLowerCase(currentWord);
            addWord(words, &numWords, currentWord);
        }
    }

    fclose(file);

    printf("In the wasteland of words, the frequencies are counted:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "The world has gone silent; provide a file name to count words.\n");
        return 1;
    }

    wordFrequencyCounter(argv[1]);

    return 0;
}