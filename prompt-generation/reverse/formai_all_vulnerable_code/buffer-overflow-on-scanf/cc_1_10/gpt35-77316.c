//FormAI DATASET v1.0 Category: Spell checking ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to check if a character is an alphabet
int isAlphabet(char c){
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    return 0;
}

int main(){
    // Reading in the file to check
    FILE *fp;
    char fileName[20];
    printf("Enter the name of the file to spell check: ");
    scanf("%s", fileName);
    fp = fopen(fileName, "r");

    if(fp == NULL){
        printf("Error: Unable to open file!");
        exit(0);
    }

    // Reading in the dictionary file
    FILE *dict;
    char dictName[20];
    printf("\nEnter the name of the dictionary file: ");
    scanf("%s", dictName);
    dict = fopen(dictName, "r");
    if(dict == NULL){
        printf("Error: Unable to open file!");
        exit(0);
    }

    // Creating a hash table to store the dictionary words
    int SIZE = 26;
    char **hashTable = calloc(SIZE, sizeof(char *));

    // Populating the hash table
    char word[100];
    while(fscanf(dict, "%s", word) != EOF){
        int index = tolower(word[0]) - 'a';
        if(hashTable[index] == NULL)
            hashTable[index] = calloc(100, sizeof(char));
        int i;
        for(i = 0; word[i] != '\0'; i++)
            hashTable[index][i] = word[i];
        hashTable[index][i] = '\0';
    }

    // Spell checking the file
    char c;
    int lineCount = 1;
    int wordCount = 1;
    char currentWord[50] = "";
    while((c = fgetc(fp)) != EOF){
        if(c == '\n'){
            lineCount++;
            wordCount = 1;
            continue;
        }
        if(isAlphabet(c)){
            currentWord[strlen(currentWord)] = c;
            continue;
        }
        else{
            // Check if the current word is spelled correctly
            int index = tolower(currentWord[0]) - 'a';
            if(hashTable[index] == NULL || strcmp(currentWord, hashTable[index]) != 0){
                printf("\nLine #%d, Word #%d: '%s' is misspelled.", lineCount, wordCount, currentWord);
            }
            memset(currentWord, 0, sizeof(currentWord));
            wordCount++;
        }
    }
    printf("\nSpell checking complete!");
    return 0;
}