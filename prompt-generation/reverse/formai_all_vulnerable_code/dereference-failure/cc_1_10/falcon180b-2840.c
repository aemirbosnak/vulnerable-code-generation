//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: intelligent
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 20

// Function to check if a string is a palindrome
bool isPalindrome(char* word) {
    int length = strlen(word);
    for (int i = 0; i < length / 2; i++) {
        if (tolower(word[i])!= tolower(word[length - i - 1])) {
            return false;
        }
    }
    return true;
}

// Function to remove non-alphabetic characters from a string
void removeNonAlphabetic(char* word) {
    int length = strlen(word);
    for (int i = 0; i < length; i++) {
        if (!isalpha(word[i])) {
            word[i] = '\0';
        }
    }
}

// Function to check if a word is in the dictionary
bool isInDictionary(char* word) {
    FILE* dictionary = fopen("dictionary.txt", "r");
    if (dictionary == NULL) {
        return false;
    }
    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, dictionary)!= NULL) {
        removeNonAlphabetic(line);
        if (strcmp(word, line) == 0) {
            fclose(dictionary);
            return true;
        }
    }
    fclose(dictionary);
    return false;
}

// Function to suggest corrections for a misspelled word
void suggestCorrections(char* word) {
    char* temp = malloc(MAX_WORD_LENGTH * sizeof(char));
    strcpy(temp, word);
    removeNonAlphabetic(temp);
    if (isPalindrome(temp)) {
        printf("Did you mean: %s\n", temp);
    } else if (isInDictionary(temp)) {
        printf("Did you mean: %s\n", temp);
    } else {
        printf("No suggestions found.\n");
    }
    free(temp);
}

int main() {
    char word[MAX_WORD_LENGTH];
    printf("Enter a word to check: ");
    scanf("%s", word);
    if (isInDictionary(word)) {
        printf("%s is spelled correctly.\n", word);
    } else {
        suggestCorrections(word);
    }
    return 0;
}