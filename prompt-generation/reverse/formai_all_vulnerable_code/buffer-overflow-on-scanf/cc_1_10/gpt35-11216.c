//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAXWORD 100
#define MAXWORDS 5000

struct wordFreq {
    char* word;
    int frequency;
};

char* getNextWord(FILE* fp);
void addWord(struct wordFreq* dict, char* word);
void sortDict(struct wordFreq* dict, int numWords);

int main() {
    printf("Welcome to the C Word Frequency Counter!\n");
    printf("Please enter the path to the text file you wish to analyze: ");

    char filename[100];
    scanf("%s", filename);

    FILE* fp;
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: File not found.\n");
        printf("Please check the path and try again.\n");
        return 1;
    }

    printf("\nAnalysis in progress...\n");

    struct wordFreq dict[MAXWORDS];
    int numWords = 0;

    char* word = getNextWord(fp);

    if (word == NULL) {
        printf("\nError: File is empty.\n");
        return 1;
    }

    addWord(dict, word);

    while ((word = getNextWord(fp)) != NULL) {
        addWord(dict, word);
    }

    sortDict(dict, numWords);

    printf("\nWord frequency analysis:\n\n");

    for (int i = 0; i < numWords; i++) {
        printf("%s\t\t%d\n", dict[i].word, dict[i].frequency);
    }

    printf("\nAnalysis complete!\n");

    fclose(fp);

    return 0;
}

char* getNextWord(FILE* fp) {
    char* word = (char*)malloc(MAXWORD * sizeof(char));
    char c;
    int index = 0;

    while ((c = fgetc(fp)) != EOF) {
        if (isalpha(c)) {
            word[index++] = tolower(c);
        } else {
            word[index] = '\0';
            return word;
        }
    }

    if (index == 0) {
        return NULL;
    }

    word[index] = '\0';
    return word;
}

void addWord(struct wordFreq* dict, char* word) {
    for (int i = 0; i < MAXWORDS; i++) {
        if (dict[i].word == NULL) {
            char* newWord = (char*)malloc(strlen(word) * sizeof(char));
            strcpy(newWord, word);

            dict[i].word = newWord;
            dict[i].frequency = 1;
            return;
        } else if (strcmp(dict[i].word, word) == 0) {
            dict[i].frequency++;
            return;
        }
    }
}

void sortDict(struct wordFreq* dict, int numWords) {
    struct wordFreq temp;

    for (int i = 0; i < numWords - 1; i++) {
        for (int j = i + 1; j < numWords; j++) {
            if (dict[j].frequency > dict[i].frequency) {
                temp = dict[i];
                dict[i] = dict[j];
                dict[j] = temp;
            }
        }
    }
}