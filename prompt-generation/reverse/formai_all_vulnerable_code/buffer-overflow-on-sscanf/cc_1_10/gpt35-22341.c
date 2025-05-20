//FormAI DATASET v1.0 Category: Spell checking ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Functions */
int loadDictionary(const char*);
int checkSpelling(const char*);

/* Constants */
#define MAX_WORD_LENGTH 45
#define DICT_LENGTH 99171

/* Global Variables */
char dictionary[DICT_LENGTH][MAX_WORD_LENGTH];
int dictLength = 0;

/* Main Function */
int main(int argc, char* argv[]) {
    /* Check for arguments */
    if (argc != 2) {
        printf("Usage: ./spellcheck <text file>\n");
        return 1;
    }

    /* Load dictionary */
    char* dictFile = "dictionary.txt";
    if (loadDictionary(dictFile) == 1) {
        printf("Could not load dictionary file.\n");
        return 1;
    }

    /* Check spelling of file */
    if (checkSpelling(argv[1]) == 1) {
        printf("There were spelling errors in the file.\n");
        return 1;
    }

    printf("File has no spelling errors.\n");
    return 0;
}

/* Function to load dictionary file */
int loadDictionary(const char* dictFile) {
    /* Open File */
    FILE* fp = fopen(dictFile, "r");
    if (fp == NULL) {
        return 1;
    }

    /* Read in words */
    char word[MAX_WORD_LENGTH];
    while (fgets(word, sizeof(word), fp)) {
        sscanf(word, "%s", dictionary[dictLength]);
        dictLength++;
    }

    /* Close File */
    fclose(fp);

    return 0;
}

/* Function to check spelling of file */
int checkSpelling(const char* filename) {
    /* Open File */
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return 1;
    }

    /* Read in file */
    char line[MAX_WORD_LENGTH*100];
    while (fgets(line, sizeof(line), fp)) {
        char word[MAX_WORD_LENGTH];
        int i = 0, j = 0, wordLength = 0, lineLength = strlen(line) - 1;
        while (i < lineLength) {
            /* Check if character is alphabetical */
            if (isalpha(line[i])) {
                /* Add character to word */
                word[j] = line[i];
                j++;
            }
            else {
                /* Check if word is in dictionary */
                if (wordLength > 0) {
                    word[j] = '\0';
                    int found = 0;
                    for (int k = 0; k < dictLength; k++) {
                        if (strcmp(dictionary[k], word) == 0) {
                            found = 1;
                            break;
                        }
                    }
                    if (found == 0) {

                        printf("O Romeo! Dr. Spell hath found offense in thy words:\n");
                        printf("Thou didst write: %s\n", word);
                        printf("But in my dictionary, I cannot find it there.\n");
                    
                    }
                }

                /* Reset word */
                memset(word, 0, sizeof(word));
                j = 0;
                wordLength = 0;
            }
            i++;
            wordLength++;
        }
    }

    /* Close File */
    fclose(fp);

    return 0;
}