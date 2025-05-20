//FormAI DATASET v1.0 Category: Spell checking ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 50
#define MAX_DICT_SIZE 50000

char dictionary[MAX_DICT_SIZE][MAX_WORD_SIZE];
int dictSize = 0;

void readFile(char filename[]) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }
    char word[MAX_WORD_SIZE];
    while (!feof(fp)) {
        fscanf(fp, "%s", word);
        strcpy(dictionary[dictSize], word);
        dictSize++;
    }
    fclose(fp);
}

int binarySearch(char word[], int left, int right) {
    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = strcmp(dictionary[mid], word);
        if (cmp == 0) {
            return 1;
        }
        if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return 0;
}

void toLowerCase(char word[]) {
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        word[i] = tolower(word[i]);
    }
}

int main() {
    char dictFilename[] = "dictionary.txt";
    char inputFilename[] = "input.txt";
    readFile(dictFilename);

    FILE* fp = fopen(inputFilename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    char word[MAX_WORD_SIZE];
    int lineNumber = 1;
    while (!feof(fp)) {
        fscanf(fp, "%s", word);
        toLowerCase(word);
        if (!binarySearch(word, 0, dictSize - 1)) {
            printf("Line %d: %s is not in the dictionary\n", lineNumber, word);
        }
        char c = fgetc(fp); // consume whitespace
        if (c == '\n') {
            lineNumber++;
        }
    }
    fclose(fp);

    return 0;
}