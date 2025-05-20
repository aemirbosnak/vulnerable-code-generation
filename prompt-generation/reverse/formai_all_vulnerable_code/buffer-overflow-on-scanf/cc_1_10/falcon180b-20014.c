//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_WORDS 5000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordFrequency;

void readFile(FILE* fp, char* filename, WordFrequency* wordFrequencies) {
    char ch;
    int i = 0;
    while((ch = fgetc(fp))!= EOF) {
        if(isalpha(ch)) {
            if(i >= MAX_WORDS) {
                printf("Error: Too many words in file.\n");
                exit(1);
            }
            strcpy(wordFrequencies[i].word, "");
            while(isalpha(ch)) {
                strcat(wordFrequencies[i].word, tolower(ch));
                ch = fgetc(fp);
            }
            wordFrequencies[i].count = 1;
            i++;
        }
    }
    fclose(fp);
}

void displayWordFrequencies(WordFrequency* wordFrequencies, int numWords) {
    printf("\nWord frequencies:\n");
    for(int i = 0; i < numWords; i++) {
        if(wordFrequencies[i].count > 0) {
            printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].count);
        }
    }
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE* fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    WordFrequency wordFrequencies[MAX_WORDS];
    readFile(fp, filename, wordFrequencies);

    int numWords = 0;
    for(int i = 0; i < MAX_WORDS; i++) {
        if(wordFrequencies[i].count > 0) {
            numWords++;
        }
    }

    displayWordFrequencies(wordFrequencies, numWords);

    return 0;
}