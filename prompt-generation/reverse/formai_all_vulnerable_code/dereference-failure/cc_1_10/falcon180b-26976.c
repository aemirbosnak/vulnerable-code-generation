//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_FILE_SIZE 1000000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void* a, const void* b) {
    const WordCount* w1 = a;
    const WordCount* w2 = b;
    return strcmp(w1->word, w2->word);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", argv[1]);
        exit(2);
    }

    WordCount* wordCounts = NULL;
    int numWords = 0;
    char word[MAX_WORD_LENGTH];
    int wordLength = 0;
    int inWord = 0;
    int i;

    while (fgets(word, MAX_WORD_LENGTH, file)!= NULL) {
        for (i = 0; i < strlen(word); i++) {
            if (isalnum(word[i])) {
                if (!inWord) {
                    inWord = 1;
                    word[wordLength++] = tolower(word[i]);
                }
            } else {
                inWord = 0;
                if (wordLength > 0) {
                    word[wordLength] = '\0';
                    if (numWords >= MAX_FILE_SIZE) {
                        printf("Error: too many words in file\n");
                        exit(3);
                    }
                    wordCounts = realloc(wordCounts, (numWords + 1) * sizeof(WordCount));
                    strcpy(wordCounts[numWords].word, word);
                    wordCounts[numWords].count = 1;
                    numWords++;
                }
                wordLength = 0;
            }
        }
    }

    if (inWord) {
        if (numWords >= MAX_FILE_SIZE) {
            printf("Error: too many words in file\n");
            exit(3);
        }
        word[wordLength] = '\0';
        wordCounts = realloc(wordCounts, (numWords + 1) * sizeof(WordCount));
        strcpy(wordCounts[numWords].word, word);
        wordCounts[numWords].count = 1;
        numWords++;
    }

    if (wordCounts == NULL) {
        printf("No words found in file\n");
    } else {
        qsort(wordCounts, numWords, sizeof(WordCount), compareWords);
        for (i = 0; i < numWords; i++) {
            printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
        }
    }

    fclose(file);
    free(wordCounts);
    return 0;
}