//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

Word words[MAX_WORDS];
int numWords = 0;

void addWord(char* word) {
    int i;
    for(i=0; i<numWords; i++) {
        if(strcmp(word, words[i].word) == 0) {
            words[i].count++;
            return;
        }
    }
    if(numWords == MAX_WORDS) {
        printf("Error: Too many unique words.\n");
        exit(1);
    }
    strcpy(words[numWords].word, word);
    words[numWords].count = 1;
    numWords++;
}

void printWords() {
    int i;
    for(i=0; i<numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    char filename[100];
    printf("Enter the name of the file: ");
    scanf("%s", filename);
    FILE* fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }
    char word[MAX_WORD_LENGTH];
    char line[100];
    while(fgets(line, sizeof(line), fp)!= NULL) {
        int i;
        for(i=0; line[i]!= '\0'; i++) {
            if(isalpha(line[i])) {
                strcpy(word, "");
                int j;
                for(j=i; j<strlen(line); j++) {
                    if(!isalpha(line[j])) {
                        break;
                    }
                    strcat(word, line[j]);
                }
                addWord(word);
            }
        }
    }
    fclose(fp);
    printWords();
    return 0;
}