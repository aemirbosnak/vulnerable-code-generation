//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void readFile(FILE *file, char *word, int *wordLength) {
    char ch;
    int i = 0;

    while((ch = fgetc(file))!= EOF) {
        if(isalpha(ch)) {
            word[i++] = tolower(ch);
        } else {
            word[i] = '\0';
            *wordLength = i;
            break;
        }
    }
}

void countFrequency(WordFrequency *words, int numWords, char *word, int frequency) {
    int i;

    for(i = 0; i < numWords; i++) {
        if(strcmp(words[i].word, word) == 0) {
            words[i].frequency += frequency;
            break;
        }
    }
}

void sortWords(WordFrequency *words, int numWords) {
    int i, j;
    WordFrequency temp;

    for(i = 0; i < numWords - 1; i++) {
        for(j = i + 1; j < numWords; j++) {
            if(words[i].frequency < words[j].frequency) {
                temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

void printWords(WordFrequency *words, int numWords) {
    int i;

    for(i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main() {
    FILE *file;
    char word[MAX_WORD_LENGTH];
    int wordLength, numWords = 0;
    WordFrequency words[MAX_WORDS];

    file = fopen("input.txt", "r");

    if(file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while(fscanf(file, "%s", word)!= EOF) {
        readFile(file, word, &wordLength);
        word[wordLength] = '\0';
        countFrequency(words, numWords, word, 1);
        numWords++;
    }

    fclose(file);

    sortWords(words, numWords);
    printWords(words, numWords);

    return 0;
}