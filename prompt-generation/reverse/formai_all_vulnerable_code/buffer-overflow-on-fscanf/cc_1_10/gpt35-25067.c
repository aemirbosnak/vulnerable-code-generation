//FormAI DATASET v1.0 Category: Database Indexing System ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
#define MAX_WORDS 1000

struct Word {
    char word[MAX];
    int lineNum[MAX_WORDS];
    int count;
};

struct Word words[MAX_WORDS];
int wordCount;

void addWord(char word[], int lineNum) {
    int i, j;
    for(i=0; i<wordCount; i++) {
        if(strcmp(words[i].word, word)==0) {
            words[i].lineNum[words[i].count] = lineNum;
            words[i].count++;
            return;
        }
    }
    strcpy(words[wordCount].word, word);
    words[wordCount].lineNum[0] = lineNum;
    words[wordCount].count = 1;
    wordCount++;
}

void display() {
    int i, j;
    for(i=0; i<wordCount; i++) {
        printf("%s : ", words[i].word);
        for(j=0; j<words[i].count-1; j++) {
            printf("%d, ", words[i].lineNum[j]);
        }
        printf("%d\n", words[i].lineNum[j]);
    }
}

int main() {
    char fileName[MAX], word[MAX];
    int lineNum = 0, i;
    FILE *file;

    printf("Enter the name of file: ");
    scanf("%s", fileName);
    file = fopen(fileName, "r");

    if(file) {
        while(fscanf(file, "%s", word)==1) {
            if(strchr(word, '.')!=NULL || strchr(word, ',')!=NULL || strchr(word, ':')!=NULL || strchr(word, ';')!=NULL) {
                for(i=0; i<strlen(word); i++) {
                    if(word[i]=='.' || word[i]==',' || word[i]==':' || word[i]==';') {
                        word[i] = '\0';
                    }
                }
            }
            addWord(word, lineNum+1);
        }
    }

    display();
    return 0;
}