//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void initWords(char *filename, WordCount words[]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    int numWords = 0;
    char word[MAX_WORD_LEN];
    while (fscanf(file, "%s", word)!= EOF) {
        if (numWords >= MAX_WORDS) {
            printf("Error: too many words in file\n");
            exit(1);
        }
        strcpy(words[numWords].word, word);
        words[numWords].count = 0;
        numWords++;
    }

    fclose(file);
}

void countWords(char *text, WordCount words[]) {
    int numWords = 0;

    char *wordStart = text;
    while (numWords < MAX_WORDS && *wordStart!= '\0') {
        if (isalpha(*wordStart)) {
            char *wordEnd = wordStart;
            while (isalnum(*(wordEnd + 1))) {
                wordEnd++;
            }
            int wordLen = wordEnd - wordStart;
            if (wordLen >= MAX_WORD_LEN) {
                printf("Error: word too long\n");
                exit(1);
            }
            strncpy(words[numWords].word, wordStart, wordLen);
            words[numWords].word[wordLen] = '\0';
            numWords++;
        } else {
            wordStart++;
        }
    }
}

void printWords(WordCount words[], int numWords) {
    for (int i = 0; i < numWords; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    WordCount words[MAX_WORDS];
    initWords(filename, words);

    char text[1000];
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    countWords(text, words);

    printWords(words, MAX_WORDS);

    return 0;
}