//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1000
#define MAX_FILE_NAME_LENGTH 100
#define MAX_NUM_OF_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *wc1 = (WordCount *)a;
    WordCount *wc2 = (WordCount *)b;
    return strcmp(wc1->word, wc2->word);
}

void readWordsFromFile(const char *filename, WordCount *words, int *numOfWords) {
    char line[MAX_LINE_LENGTH];
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s.\n", filename);
        exit(1);
    }
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        int len = strlen(line);
        if (line[len - 1] == '\n') {
            line[len - 1] = '\0';
            len--;
        }
        char *token = strtok(line, ",.!?;:\"'");
        while (token!= NULL) {
            if (*token!= '\0') {
                int wordLen = strlen(token);
                if (wordLen > MAX_WORD_LENGTH) {
                    printf("Warning: word %s is too long and will be truncated.\n", token);
                    wordLen = MAX_WORD_LENGTH - 1;
                }
                strncpy(words[*numOfWords].word, token, wordLen);
                words[*numOfWords].word[wordLen] = '\0';
                (*numOfWords)++;
            }
            token = strtok(NULL, ",.!?;:\"'");
        }
    }
    fclose(file);
}

void printWordCounts(WordCount *words, int numOfWords) {
    qsort(words, numOfWords, sizeof(WordCount), compareWords);
    for (int i = 0; i < numOfWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    char filename[MAX_FILE_NAME_LENGTH];
    strncpy(filename, argv[1], MAX_FILE_NAME_LENGTH - 1);
    filename[MAX_FILE_NAME_LENGTH - 1] = '\0';
    WordCount words[MAX_NUM_OF_WORDS];
    int numOfWords = 0;
    readWordsFromFile(filename, words, &numOfWords);
    printWordCounts(words, numOfWords);
    return 0;
}