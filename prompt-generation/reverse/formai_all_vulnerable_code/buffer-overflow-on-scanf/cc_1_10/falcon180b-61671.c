//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: shocked
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000 // Maximum number of words that can be checked
#define MAX_WORD_LENGTH 20 // Maximum length of a word

// Function to check if a word is misspelled
int isMisspelled(char *word) {
    FILE *dictFile;
    char dictWord[MAX_WORD_LENGTH];
    dictFile = fopen("dictionary.txt", "r");
    if (dictFile == NULL) {
        printf("Error: Dictionary file not found.\n");
        return 1;
    }
    while (fscanf(dictFile, "%s", dictWord)!= EOF) {
        if (strcmp(word, dictWord) == 0) {
            fclose(dictFile);
            return 0;
        }
    }
    fclose(dictFile);
    return 1;
}

// Function to read words from a file and check if they are misspelled
void checkWords(FILE *file) {
    char word[MAX_WORD_LENGTH];
    int wordCount = 0;
    while (fscanf(file, "%s", word)!= EOF) {
        if (isMisspelled(word)) {
            printf("Misspelled word found: %s\n", word);
        }
        wordCount++;
        if (wordCount >= MAX_WORDS) {
            printf("Maximum number of words checked. Exiting...\n");
            break;
        }
    }
}

int main() {
    FILE *file;
    char filename[50];
    printf("Enter the name of the file to be checked: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }
    checkWords(file);
    fclose(file);
    return 0;
}