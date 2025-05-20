//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN+1];
    int count;
} WordCount;

WordCount words[MAX_WORDS];
int numWords = 0;

void addWord(char* word) {
    int i;
    for(i=0; i<numWords; i++) {
        if(strcmp(words[i].word, word) == 0) {
            words[i].count++;
            return;
        }
    }
    if(numWords == MAX_WORDS) {
        printf("Error: Maximum number of words reached.\n");
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
    char word[MAX_WORD_LEN+1];
    FILE* fp;
    char ch;
    int i;

    printf("Enter filename: ");
    scanf("%s", word);

    fp = fopen(word, "r");
    if(fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    while((ch = fgetc(fp))!= EOF) {
        if(isalpha(ch)) {
            ungetc(ch, fp);
            fscanf(fp, "%s", word);
            addWord(word);
        }
    }

    fclose(fp);

    printWords();

    return 0;
}