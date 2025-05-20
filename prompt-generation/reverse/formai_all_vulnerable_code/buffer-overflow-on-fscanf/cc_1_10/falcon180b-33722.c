//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

//Structure to hold word and its translation
typedef struct {
    char word[50];
    char translation[100];
} WordTranslation;

int main() {
    char input[100];
    char *token;
    FILE *dictFile;
    WordTranslation dict[MAX_WORDS];
    int numWords = 0;

    //Open dictionary file
    dictFile = fopen("dictionary.txt", "r");
    if (dictFile == NULL) {
        printf("Error opening dictionary file.\n");
        exit(1);
    }

    //Read words and translations from dictionary file
    while (fscanf(dictFile, "%s %s\n", dict[numWords].word, dict[numWords].translation)!= EOF) {
        numWords++;
    }
    fclose(dictFile);

    //Get user input
    printf("Enter a sentence to translate:\n");
    fgets(input, sizeof(input), stdin);

    //Tokenize input
    token = strtok(input, " ");
    while (token!= NULL) {
        //Search dictionary for word
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(dict[i].word, token) == 0) {
                //Found word in dictionary, print translation
                printf("%s ", dict[i].translation);
                break;
            }
        }
        //Word not found in dictionary, print untranslated word
        if (i == numWords) {
            printf("%s ", token);
        }
        token = strtok(NULL, " ");
    }

    printf("\n");

    return 0;
}