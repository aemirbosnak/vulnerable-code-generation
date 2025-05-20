//FormAI DATASET v1.0 Category: Spell checking ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50

void toLower(char *word) {
    int len = strlen(word);

    for (int i = 0; i < len; i++) {
        word[i] = tolower(word[i]);
    }
}

int binarySearch(char **dictionary, int left, int right, char *word) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (strcmp(dictionary[mid], word) == 0) {
            return 1;
        }
        else if (strcmp(dictionary[mid], word) < 0) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return 0;
}

int main() {
    char **dictionary;
    char word[MAX_WORD_LEN];
    int dictSize = 0;
    FILE *inputFile, *misspelledFile;

    // Open the dictionary file and read all the words into an array
    FILE *dictFile = fopen("dictionary.txt", "r");

    if (dictFile == NULL) {
        printf("Error: Failed to open dictionary file.\n");
        return 1;
    }

    while (fscanf(dictFile, "%s", word) != EOF) {
        toLower(word);
        dictSize++;
    }

    dictionary = (char**)malloc(dictSize * sizeof(char*));
    fseek(dictFile, 0, SEEK_SET);

    for (int i = 0; i < dictSize; i++) {
        fscanf(dictFile, "%s", word);
        toLower(word);
        dictionary[i] = strdup(word);
    }

    fclose(dictFile);

    // Open the input file and start reading each word
    inputFile = fopen("input.txt", "r");
    misspelledFile = fopen("misspelled.txt", "w");

    if (inputFile == NULL) {
        printf("Error: Failed to open input file.\n");
        return 1;
    }

    while (fscanf(inputFile, "%s", word) != EOF) {
        // Remove special characters from the word
        int len = strlen(word);
        int j = 0;

        for (int i = 0; i < len; i++) {
            if (isalpha(word[i])) {
                word[j] = tolower(word[i]);
                j++;
            }
        }

        word[j] = '\0';

        if (!binarySearch(dictionary, 0, dictSize - 1, word)) {
            fprintf(misspelledFile, "%s\n", word);
        }
    }

    fclose(inputFile);
    fclose(misspelledFile);

    // Display misspelled words
    misspelledFile = fopen("misspelled.txt", "r");

    printf("Misspelled words:\n");
    while (fscanf(misspelledFile, "%s", word) != EOF) {
        printf("%s\n", word);
    }

    fclose(misspelledFile);

    // Free memory used for dictionary
    for (int i = 0; i < dictSize; i++) {
        free(dictionary[i]);
    }

    free(dictionary);

    return 0;
}