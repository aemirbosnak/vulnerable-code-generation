//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000 // Maximum number of unique words
#define MAX_WORD_LENGTH 100 // Maximum length of a word

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    return strcmp((char *)a, (char *)b);
}

void readFile(FILE *file, WordFrequency *words, int *numWords) {
    char line[1024];
    char *token;
    while (fgets(line, sizeof(line), file)!= NULL) {
        token = strtok(line, ",.?!;:\"'()[]{}<>");
        while (token!= NULL) {
            int wordLength = strlen(token);
            if (wordLength > 0 && wordLength <= MAX_WORD_LENGTH) {
                for (int i = 0; i < wordLength; i++) {
                    if (!isalpha(token[i])) {
                        token[i] = '\0';
                        wordLength = i;
                        break;
                    }
                }
                strcpy(words[*numWords].word, token);
                words[*numWords].count = 1;
                (*numWords)++;
            }
            token = strtok(NULL, ",.?!;:\"'()[]{}<>");
        }
    }
}

void sortWords(WordFrequency *words, int numWords) {
    qsort(words, numWords, sizeof(WordFrequency), compareWords);
}

void printTopWords(WordFrequency *words, int numWords, int numTopWords) {
    printf("Top %d most frequent words:\n", numTopWords);
    for (int i = 0; i < numTopWords && i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    FILE *file;
    char filename[256];
    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    printf("Enter the name of the text file: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    readFile(file, words, &numWords);
    fclose(file);

    sortWords(words, numWords);
    printTopWords(words, numWords, 10);

    return 0;
}