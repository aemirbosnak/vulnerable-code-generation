//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 5000

struct WordFrequency {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

int isDelimiter(char c);
void toLower(char *str);
void printWordFreq(struct WordFrequency *wordFreq, int nWords);

int main() {
    char fileName[256];
    printf("Enter file name: ");
    scanf("%s", fileName);

    FILE *fp = fopen(fileName, "r");

    if(fp == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }

    char word[MAX_WORD_LENGTH];
    int nWords = 0;
    struct WordFrequency wordFreq[MAX_WORDS];

    while(fscanf(fp, "%s", word) != EOF) {
        toLower(word);

        if(strlen(word) == 0)
            continue;

        int isInArray = 0;
        int i;
        for(i = 0; i < nWords; i++) {
            if(strcmp(wordFreq[i].word, word) == 0) {
                isInArray = 1;
                wordFreq[i].frequency++;
                break;
            }
        }

        if(!isInArray) {
            struct WordFrequency newWordFreq;
            strcpy(newWordFreq.word, word);
            newWordFreq.frequency = 1;
            wordFreq[nWords++] = newWordFreq;
        }

        if(nWords >= MAX_WORDS) {
            printf("Max words limit exceeded.\n");
            break;
        }
    }

    printWordFreq(wordFreq, nWords);

    fclose(fp);
    return 0;
}

int isDelimiter(char c) {
    return c == ' ' || c == '\n' || c == ',' || c == '.' || c == '\t';
}

void toLower(char *str) {
    int i;
    for(i = 0; str[i]; i++)
        str[i] = tolower(str[i]);
}

void printWordFreq(struct WordFrequency *wordFreq, int nWords) {
    int i;
    for(i = 0; i < nWords; i++)
        printf("%s: %d\n", wordFreq[i].word, wordFreq[i].frequency);
}