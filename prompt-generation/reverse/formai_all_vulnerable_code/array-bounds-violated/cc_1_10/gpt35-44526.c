//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: protected
// C Alien Language Translator
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_SIZE 50 
#define MAX_DICTIONARY_SIZE 10000 

char **alienWords;
char **englishWords;
int numWords;

void getDictionary() {
    char line[100];
    FILE *fp = fopen("dictionary.txt", "r");
    if(fp == NULL) {
        printf("Dictionary file not found.\n");
        return;
    }

    int i = 0;

    while(fgets(line, sizeof(line), fp) != NULL) {
        if(line[strlen(line)-1] == '\n') line[strlen(line)-1] = '\0';

        char *ptr = strtok(line, "-");
        alienWords[i] = strdup(ptr);

        ptr = strtok(NULL, "-");
        englishWords[i] = strdup(ptr);

        i++;
    }

    numWords = i;

    fclose(fp);
}

void translate(char *input) {
    int flag = 0; // flag to determine if the word is found in dictionary
    for(int i = 0; i < numWords; i++) {
        if(strcmp(input, alienWords[i]) == 0) {
            printf("%s ", englishWords[i]);
            flag = 1;
            break;
        }
    }

    if(flag == 0) printf("%s ", input);
}

int main() {
    alienWords = (char**) malloc(sizeof(char*) * MAX_DICTIONARY_SIZE);
    englishWords = (char**) malloc(sizeof(char*) * MAX_DICTIONARY_SIZE);

    getDictionary();

    char inputString[MAX_WORD_SIZE * MAX_DICTIONARY_SIZE];
    char *ptr = strtok(inputString, " ");

    while(ptr != NULL) {
        translate(ptr);
        ptr = strtok(NULL, " ");
    }

    printf("\n");

    for(int i = 0; i < numWords; i++) {
        free(alienWords[i]);
        free(englishWords[i]);
    }

    free(alienWords);
    free(englishWords);

    return 0;
}