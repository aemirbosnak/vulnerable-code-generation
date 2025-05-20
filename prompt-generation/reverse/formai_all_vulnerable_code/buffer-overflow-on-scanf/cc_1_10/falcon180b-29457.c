//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readWords(FILE *file, WordCount words[]) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            if (!isalpha(word[i])) {
                word[i] = '\0';
            }
        }
        strcpy(words[i].word, word);
        words[i].count++;
    }
}

void printWords(WordCount words[], int numWords) {
    int i;
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    FILE *file;
    char filename[MAX_WORD_LENGTH];
    int i;
    printf("Enter filename: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }
    WordCount words[MAX_WORDS];
    readWords(file, words);
    fclose(file);
    int numWords = 0;
    for (i = 0; i < MAX_WORDS; i++) {
        if (strlen(words[i].word) > 0) {
            numWords++;
        }
    }
    printf("Total words: %d\n", numWords);
    printWords(words, numWords);
    return 0;
}