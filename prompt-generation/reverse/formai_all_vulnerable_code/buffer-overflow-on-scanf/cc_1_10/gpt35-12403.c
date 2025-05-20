//FormAI DATASET v1.0 Category: Spell checking ; Style: post-apocalyptic
// Post-apocalyptic Spell Checker

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compare two strings
int strCompare(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] == str2[i]) {
        if (str1[i] == '\0' || str2[i] == '\0')
            break;
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0')
        return 1;
    else
        return 0;
}

// Function to check if the given word is in the dictionary
int checkDictionary(char word[], FILE *dict) {
    char temp[100];
    while (fgets(temp, 100, dict) != NULL) {
        strtok(temp, "\n"); // Remove newline character from the end of the word
        if (strCompare(word, temp)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char word[100];
    printf("Enter a word to check: ");
    scanf("%s", word);
    FILE *dict;
    dict = fopen("dictionary.txt", "r");
    if (dict == NULL) {
        printf("ERROR: Dictionary file not found!");
        exit(1);
    }
    if (checkDictionary(word, dict)) {
        printf("The word is spelled correctly.\n");
    } else {
        printf("The word is misspelled.\n");
    }
    fclose(dict);
    return 0;
}