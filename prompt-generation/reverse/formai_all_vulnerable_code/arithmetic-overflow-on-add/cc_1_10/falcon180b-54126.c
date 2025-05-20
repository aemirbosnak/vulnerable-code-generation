//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void readFile(const char* filename, char* buffer) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    if (fileSize >= MAX_NUM_WORDS * MAX_WORD_LENGTH) {
        printf("Error: file is too large\n");
        fclose(file);
        exit(1);
    }

    fread(buffer, 1, fileSize, file);
    fclose(file);
}

void tokenize(char* buffer, WordFrequency* words) {
    char* wordStart = buffer;
    char* wordEnd = strtok(buffer, ",.?!;:-\"'");

    while (wordEnd!= NULL && words->frequency < MAX_NUM_WORDS) {
        strncpy(words->word, wordStart, MAX_WORD_LENGTH - 1);
        words->word[MAX_WORD_LENGTH - 1] = '\0';
        words->frequency++;

        wordStart = wordEnd + 1;
        wordEnd = strtok(NULL, ",.?!;:-\"'");
    }
}

void countFrequencies(WordFrequency* words, int numWords) {
    for (int i = 0; i < numWords; i++) {
        for (int j = i + 1; j < numWords; j++) {
            if (strcmp(words[i].word, words[j].word) == 0) {
                words[i].frequency += words[j].frequency;
                words[j].frequency = 0;
            }
        }
    }
}

void printFrequencies(WordFrequency* words, int numWords) {
    for (int i = 0; i < numWords; i++) {
        if (words[i].frequency > 0) {
            printf("%s: %d\n", words[i].word, words[i].frequency);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char buffer[MAX_NUM_WORDS * MAX_WORD_LENGTH];
    readFile(argv[1], buffer);

    WordFrequency words[MAX_NUM_WORDS];
    tokenize(buffer, words);

    countFrequencies(words, MAX_NUM_WORDS);
    printFrequencies(words, MAX_NUM_WORDS);

    return 0;
}