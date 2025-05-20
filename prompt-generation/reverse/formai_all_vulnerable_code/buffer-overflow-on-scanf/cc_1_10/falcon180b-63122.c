//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_STRING_LENGTH 100

// Function to remove all non-alphabetic characters from a string
void removeNonAlphabetic(char* str) {
    int i;
    for (i = 0; str[i]; i++) {
        if (!isalpha(str[i])) {
            str[i] = '\0';
        }
    }
}

// Function to convert a string to lowercase
void toLowerCase(char* str) {
    int i;
    for (i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to search for a word in a text file
bool searchWord(FILE* file, char* word) {
    char line[MAX_STRING_LENGTH];
    while (fgets(line, MAX_STRING_LENGTH, file)!= NULL) {
        removeNonAlphabetic(line);
        toLowerCase(line);
        if (strstr(line, word)!= NULL) {
            return true;
        }
    }
    return false;
}

int main() {
    char filename[MAX_STRING_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    char word[MAX_STRING_LENGTH];
    printf("Enter word to search for: ");
    scanf("%s", word);

    if (searchWord(file, word)) {
        printf("Word found in file.\n");
    } else {
        printf("Word not found in file.\n");
    }

    fclose(file);
    return 0;
}