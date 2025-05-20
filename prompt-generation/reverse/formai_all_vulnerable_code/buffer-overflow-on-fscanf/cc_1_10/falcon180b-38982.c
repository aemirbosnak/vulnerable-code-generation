//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct wordFrequency{
    char word[MAX_WORD_LENGTH];
    int frequency;
};

bool compareWords(const void* a, const void* b){
    struct wordFrequency* wordA = (struct wordFrequency*)a;
    struct wordFrequency* wordB = (struct wordFrequency*)b;
    if(wordA->frequency > wordB->frequency)
        return true;
    else if(wordA->frequency == wordB->frequency)
        return strcmp(wordA->word, wordB->word) > 0;
    else
        return false;
}

void readFile(FILE* file, char* buffer, int* bufferIndex){
    int ch;
    while((ch = fgetc(file))!= EOF){
        if(*bufferIndex >= MAX_WORD_LENGTH)
            break;
        buffer[*bufferIndex] = tolower(ch);
        if(isalpha(ch))
            (*bufferIndex)++;
        else{
            buffer[*bufferIndex] = '\0';
            (*bufferIndex) = 0;
        }
    }
}

int main(){
    FILE* file;
    char filename[100];
    printf("Enter the file name: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if(file == NULL){
        printf("Error opening file.\n");
        exit(1);
    }
    char buffer[MAX_WORD_LENGTH];
    int bufferIndex = 0;
    struct wordFrequency words[MAX_WORDS];
    int numWords = 0;
    while(fscanf(file, "%s", buffer)!= EOF){
        if(bufferIndex > 0){
            words[numWords].word[bufferIndex] = '\0';
            words[numWords].frequency = 1;
            numWords++;
            bufferIndex = 0;
        }
        readFile(file, buffer, &bufferIndex);
    }
    if(bufferIndex > 0){
        words[numWords].word[bufferIndex] = '\0';
        words[numWords].frequency = 1;
        numWords++;
    }
    fclose(file);
    qsort(words, numWords, sizeof(struct wordFrequency), compareWords);
    printf("The frequency of words in the file:\n");
    for(int i = 0; i < numWords; i++){
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
    return 0;
}