//FormAI DATASET v1.0 Category: Spell checking ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CHARS 100
#define MAX_WORDS 10
#define DICTIONARY_SIZE 100

char dictionary[DICTIONARY_SIZE][MAX_CHARS]; // Assuming the maximum word length as 100 characters

bool isWordPresent(char* word) {
    for(int i=0; i<DICTIONARY_SIZE; i++) {
        if(strcmp(dictionary[i], word) == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    char input[MAX_WORDS][MAX_CHARS]; // Assuming the maximum input length as 10 words with each word having 100 characters
    char delimiters[] = " ,.?!"; // Assuming these as delimiters to separate words in input
    int wordCount = 0;

    // Reading dictionary file and storing it in our data structure
    FILE *dictFile = fopen("dictionary.txt", "r");
    int dictIndex = 0;
    char dictWord[MAX_CHARS];
    while(fscanf(dictFile, "%s", dictWord) != EOF) {
        strcpy(dictionary[dictIndex], dictWord);
        dictIndex++;
    }
    fclose(dictFile);

    // Reading input from user and checking spellings
    printf("Enter your text:\n");
    char inputLine[MAX_CHARS];
    fgets(inputLine, MAX_CHARS, stdin);
    char* token = strtok(inputLine, delimiters);
    while(token != NULL && wordCount < MAX_WORDS) {
        strcpy(input[wordCount], token);
        if(!isWordPresent(token)) {
            printf("'%s' is misspelled\n", token);
        }
        token = strtok(NULL, delimiters);
        wordCount++;
    }

    return 0;
}