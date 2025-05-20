//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

struct Word{
    char word[MAX_WORD_LENGTH];
    int count;
};

void removePunctuations(char* str){
    int i,j;
    for(i=0,j=0;str[i]!='\0';i++){
        if(!isspace(str[i]) &&!ispunct(str[i])){
            str[j++] = tolower(str[i]);
        }
    }
    str[j] = '\0';
}

int compareWords(const void* a, const void* b){
    struct Word* word1 = (struct Word*)a;
    struct Word* word2 = (struct Word*)b;
    return word2->count - word1->count;
}

void printTopWords(struct Word* words, int numWords){
    qsort(words, numWords, sizeof(struct Word), compareWords);
    printf("Top %d words:\n", numWords);
    for(int i=0;i<numWords;i++){
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(){
    FILE* file;
    char line[1000];
    struct Word* words = (struct Word*)malloc(MAX_WORDS*sizeof(struct Word));
    int numWords = 0;
    file = fopen("input.txt", "r");
    if(file == NULL){
        printf("Error: Could not open file.\n");
        exit(1);
    }
    while(fgets(line, 1000, file)!= NULL){
        char* token = strtok(line, ",.?!;:");
        while(token!= NULL){
            removePunctuations(token);
            int wordIndex = -1;
            for(int i=0;i<numWords;i++){
                if(strcmp(words[i].word, token) == 0){
                    wordIndex = i;
                    break;
                }
            }
            if(wordIndex == -1){
                if(numWords >= MAX_WORDS){
                    printf("Warning: Maximum number of words reached.\n");
                    break;
                }
                strcpy(words[numWords].word, token);
                words[numWords].count = 1;
                numWords++;
            }else{
                words[wordIndex].count++;
            }
            token = strtok(NULL, ",.?!;:");
        }
    }
    fclose(file);
    printTopWords(words, numWords);
    free(words);
    return 0;
}