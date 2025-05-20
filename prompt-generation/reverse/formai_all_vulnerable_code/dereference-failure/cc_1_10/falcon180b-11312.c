//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORD_COUNT 1000
#define MAX_FILE_SIZE 1000000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

bool isWord(char *word) {
    int i = 0;
    while(word[i]) {
        if(!isalpha(word[i])) {
            return false;
        }
        i++;
    }
    return true;
}

void readWords(char *filename, WordFrequency *wordFrequencies, int *wordCount) {
    FILE *file;
    char word[MAX_WORD_LENGTH];
    int i = 0;
    file = fopen(filename, "r");
    if(file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }
    while(fscanf(file, "%s", word)!= EOF) {
        if(isWord(word)) {
            strcpy(wordFrequencies[i].word, word);
            wordFrequencies[i].count = 1;
            i++;
        }
    }
    fclose(file);
}

void writeWords(WordFrequency *wordFrequencies, int wordCount) {
    int i;
    for(i = 0; i < wordCount; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].count);
    }
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    char filename[MAX_FILE_SIZE];
    strcpy(filename, argv[1]);
    WordFrequency wordFrequencies[MAX_WORD_COUNT];
    int wordCount = 0;
    readWords(filename, wordFrequencies, &wordCount);
    writeWords(wordFrequencies, wordCount);
    return 0;
}