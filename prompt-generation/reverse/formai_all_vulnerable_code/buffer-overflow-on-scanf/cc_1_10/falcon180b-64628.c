//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: mathematical
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#define MAX_SIZE 100000
#define MAX_WORD_SIZE 50

typedef struct {
    char word[MAX_WORD_SIZE];
    int count;
} WordCount;

int cmp(const void* a, const void* b) {
    WordCount* c = (WordCount*)a;
    WordCount* d = (WordCount*)b;
    return strcmp(c->word, d->word);
}

int main() {
    char filename[MAX_SIZE];
    printf("Enter the name of the file: ");
    scanf("%s", filename);
    FILE* fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("File not found.\n");
        return 0;
    }
    char ch;
    int count = 0;
    char word[MAX_WORD_SIZE];
    WordCount words[MAX_SIZE];
    int numWords = 0;
    while((ch = fgetc(fp))!= EOF) {
        if(isalpha(ch)) {
            if(count == MAX_WORD_SIZE - 1) {
                word[count] = '\0';
                strcpy(words[numWords].word, word);
                words[numWords].count = 1;
                numWords++;
                count = 0;
            }
            else {
                word[count++] = ch;
            }
        }
        else {
            if(count > 0) {
                word[count] = '\0';
                strcpy(words[numWords].word, word);
                words[numWords].count = 1;
                numWords++;
                count = 0;
            }
        }
    }
    if(count > 0) {
        word[count] = '\0';
        strcpy(words[numWords].word, word);
        words[numWords].count = 1;
        numWords++;
    }
    qsort(words, numWords, sizeof(WordCount), cmp);
    printf("Word\tCount\n");
    for(int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }
    fclose(fp);
    return 0;
}