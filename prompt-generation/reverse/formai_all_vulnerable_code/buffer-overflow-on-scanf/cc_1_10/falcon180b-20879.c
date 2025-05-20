//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

typedef struct {
    char word[100];
    int freq;
} Word;

typedef struct {
    Word words[10000];
    int size;
} Dictionary;

void initDictionary(Dictionary* dict) {
    dict->size = 0;
}

void insertWord(Dictionary* dict, char* word) {
    for(int i=0; i<dict->size; i++) {
        if(strcmp(dict->words[i].word, word) == 0) {
            dict->words[i].freq++;
            return;
        }
    }
    if(dict->size >= 10000) {
        printf("Dictionary is full!\n");
        return;
    }
    strcpy(dict->words[dict->size].word, word);
    dict->words[dict->size].freq = 1;
    dict->size++;
}

bool searchWord(Dictionary dict, char* word) {
    for(int i=0; i<dict.size; i++) {
        if(strcmp(dict.words[i].word, word) == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    FILE* fp;
    char ch;
    char word[100];
    int len = 0;
    Dictionary dict;
    initDictionary(&dict);
    printf("Enter the name of the file to be checked:\n");
    scanf("%s", word);
    fp = fopen(word, "r");
    if(fp == NULL) {
        printf("File not found!\n");
        return 0;
    }
    while((ch = fgetc(fp))!= EOF) {
        if(isalpha(ch)) {
            word[len++] = toupper(ch);
        } else if(len > 0) {
            word[len] = '\0';
            if(!searchWord(dict, word)) {
                insertWord(&dict, word);
            }
            len = 0;
        }
    }
    if(len > 0) {
        word[len] = '\0';
        if(!searchWord(dict, word)) {
            insertWord(&dict, word);
        }
    }
    fclose(fp);
    printf("Spell checking complete!\n");
    return 0;
}