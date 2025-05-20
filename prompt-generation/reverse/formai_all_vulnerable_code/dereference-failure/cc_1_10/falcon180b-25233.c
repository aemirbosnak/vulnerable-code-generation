//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct {
    char english[50];
    char alien[50];
} Word;

int main() {
    FILE *inputFile, *outputFile;
    char line[100];
    Word words[MAX_WORDS];
    int numWords = 0;
    
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }
    
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }
    
    while (fgets(line, sizeof(line), inputFile)!= NULL) {
        if (numWords >= MAX_WORDS) {
            printf("Maximum number of words exceeded.\n");
            break;
        }
        
        char *token = strtok(line, " ");
        while (token!= NULL) {
            strcpy(words[numWords].english, token);
            strcpy(words[numWords].alien, "");
            numWords++;
            
            if (numWords >= MAX_WORDS) {
                printf("Maximum number of words exceeded.\n");
                break;
            }
            
            token = strtok(NULL, " ");
        }
    }
    
    fclose(inputFile);
    
    for (int i = 0; i < numWords; i++) {
        printf("Enter the translation for '%s': ", words[i].english);
        scanf("%s", words[i].alien);
    }
    
    fprintf(outputFile, "Alien Language Translator\n\n");
    
    for (int i = 0; i < numWords; i++) {
        fprintf(outputFile, "%s -> %s\n", words[i].english, words[i].alien);
    }
    
    fclose(outputFile);
    
    printf("Translation complete.\n");
    
    return 0;
}