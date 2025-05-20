//Falcon-180B DATASET v1.0 Category: Educational ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readWords(char* filename, WordCount words[]) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        int index = 0;
        while (index < MAX_WORDS && words[index].word[0]!= '\0') {
            index++;
        }
        if (index < MAX_WORDS) {
            strcpy(words[index].word, word);
            words[index].count = 1;
        } else {
            printf("Maximum number of words reached\n");
        }
    }

    fclose(file);
}

void printWords(WordCount words[], int numWords) {
    for (int i = 0; i < numWords; i++) {
        if (words[i].word[0]!= '\0') {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    char filename[MAX_WORD_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);

    WordCount words[MAX_WORDS];
    readWords(filename, words);

    int numWords = 0;
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].word[0]!= '\0') {
            numWords++;
        }
    }

    printf("Total number of words: %d\n", numWords);
    printWords(words, numWords);

    return 0;
}