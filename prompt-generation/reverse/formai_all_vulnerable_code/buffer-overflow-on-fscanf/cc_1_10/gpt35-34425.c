//FormAI DATASET v1.0 Category: Spam Detection System ; Style: brave
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_SPAM_WORDS 100 // maximum number of spam words
#define MAX_SPAM_CONTENT_SIZE 2000 // maximum spam content size

char spamWords[MAX_SPAM_WORDS][50]; // array to store spam words
int numSpamWords = 0; // number of spam words in the array

void loadSpamWords(char *fileName); // function to load spam words from file

int main() 
{
    printf("Welcome to the Spam Detection System!\n");
    printf("Please enter the name of the file containing spam words: ");
    
    char fileName[50];
    scanf("%s", fileName);
    loadSpamWords(fileName);
    
    char spamContent[MAX_SPAM_CONTENT_SIZE];
    printf("Please enter the spam content: ");
    scanf("%[^\n]s", spamContent);
    
    char *token = strtok(spamContent, " ");
    int numSpamWordsFound = 0;
    
    while(token != NULL) {
        for(int i = 0; i < numSpamWords; i++) {
            if(strcmp(token, spamWords[i]) == 0) {
                numSpamWordsFound++;
                break;
            }
        }
        token = strtok(NULL, " ");
    }
    
    if(numSpamWordsFound > 0) {
        printf("Warning: This content may contain spam!\n");
        printf("%d spam words found in the content.\n", numSpamWordsFound);
    } else {
        printf("This content is spam-free.\n");
    }
    
    return 0;
}

void loadSpamWords(char *fileName) {
    FILE *fp = fopen(fileName, "r");
    
    if(fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    
    char word[50];
    
    while(fscanf(fp, "%s", word) != EOF) {
        strcpy(spamWords[numSpamWords], word);
        numSpamWords++;
    }
    
    fclose(fp);
}