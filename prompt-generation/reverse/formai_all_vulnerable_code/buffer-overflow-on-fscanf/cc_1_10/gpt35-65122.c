//FormAI DATASET v1.0 Category: Spell checking ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 20
#define WORD_COUNT 10
#define DICTIONARY_FILE "dictionary.txt"

typedef struct{
    char word[MAX_WORD_LEN+1];
    int frequency;
} Word;

int compare(const void *a, const void *b){
    Word *wordA = (Word*)a;
    Word *wordB = (Word*)b;
    return strcmp(wordA->word, wordB->word);
}

int binarySearch(Word dictionary[], char word[]){
    int left = 0;
    int right = WORD_COUNT-1;
    while(left <= right){
        int mid = (left + right)/2;
        if(strcmp(dictionary[mid].word, word) == 0){
            return mid;
        } else if(strcmp(dictionary[mid].word, word) < 0){
            left = mid+1;
        } else{
            right = mid-1;
        }
    }
    return -1;
}

void spellCheck(char text[]){
    Word dictionary[WORD_COUNT];
    FILE *fp = fopen(DICTIONARY_FILE, "r");
    if(fp == NULL){
        printf("Dictionary file not found!");
        exit(0);
    }
    for(int i=0; i<WORD_COUNT; i++){
        fscanf(fp, "%s %d", dictionary[i].word, &dictionary[i].frequency);
    }
    fclose(fp);
    qsort(dictionary, WORD_COUNT, sizeof(Word), compare);
    char *wordPtr;
    char delimiters[] = ".,;:?!\n ";
    int lineNumber = 1;
    int wordNumber = 1;
    wordPtr = strtok(text, delimiters);
    while(wordPtr != NULL){
        int index = binarySearch(dictionary, wordPtr);
        if(index == -1){
            printf("Error at Line %d, Word %d: %s\n", lineNumber, wordNumber, wordPtr);
        }
        wordPtr = strtok(NULL, delimiters);
        ++wordNumber;
        if(wordPtr == NULL){
            ++lineNumber;
            wordNumber = 1;
            printf("\n");
        }
    }
}

int main(){
    char text[] = "This is an example program to test the spell checking functionality. It shold identify misspelings in the provided text. The dictionary file contains ten words: apple cat dog elephant eggplant fruit grapes hat igloo.\n";
    spellCheck(text);
    return 0;
}