//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: retro
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

// Function to compare two strings (case insensitive)
int compareStrings(char* str1, char* str2) {
    while(*str1 && *str2) {
        if(tolower(*str1)!= tolower(*str2)) {
            return 0;
        }
        str1++;
        str2++;
    }
    return 1;
}

// Function to load dictionary into memory
void loadDictionary(char* dictionaryFile, char words[MAX_WORDS][MAX_WORD_LENGTH]) {
    FILE* fp = fopen(dictionaryFile, "r");
    if(fp == NULL) {
        printf("Error loading dictionary file.\n");
        exit(1);
    }

    int numWords = 0;
    while(fscanf(fp, "%s", words[numWords])!= EOF) {
        numWords++;
    }

    fclose(fp);
}

// Function to check spelling of a word
int checkSpelling(char* word, char* dictionary[MAX_WORDS][MAX_WORD_LENGTH]) {
    int i = 0;
    while(i < MAX_WORDS && strcmp(word, dictionary[i])!= 0) {
        i++;
    }
    return i;
}

// Main function
int main() {
    char inputText[10000];
    char dictionary[MAX_WORDS][MAX_WORD_LENGTH];

    // Load dictionary
    loadDictionary("dictionary.txt", dictionary);

    // Read input text
    printf("Enter text to check spelling:\n");
    fgets(inputText, 10000, stdin);

    // Convert input text to lowercase
    int i = 0;
    while(inputText[i]) {
        inputText[i] = tolower(inputText[i]);
        i++;
    }

    // Check spelling
    int numErrors = 0;
    char* word = strtok(inputText, " ");
    while(word!= NULL) {
        int index = checkSpelling(word, dictionary);
        if(index == MAX_WORDS) {
            printf("%s is not in the dictionary.\n", word);
            numErrors++;
        }
        word = strtok(NULL, " ");
    }

    if(numErrors == 0) {
        printf("No spelling errors found.\n");
    } else {
        printf("%d spelling error(s) found.\n", numErrors);
    }

    return 0;
}