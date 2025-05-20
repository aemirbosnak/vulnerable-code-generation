//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_DICTIONARY_SIZE 1000000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} DictionaryEntry;

int main() {
    FILE *dictionaryFile;
    DictionaryEntry dictionary[MAX_DICTIONARY_SIZE];
    int dictionarySize = 0;
    int i, j, k;
    char word[MAX_WORD_LENGTH];
    char line[MAX_WORD_LENGTH];

    // Load dictionary file
    dictionaryFile = fopen("dictionary.txt", "r");
    if (dictionaryFile == NULL) {
        printf("Error: Could not open dictionary file.\n");
        exit(1);
    }

    while (fscanf(dictionaryFile, "%s %d", word, &dictionary[dictionarySize].frequency)!= EOF) {
        dictionarySize++;
    }

    fclose(dictionaryFile);

    // Read input file
    FILE *inputFile;
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, inputFile)!= NULL) {
        i = 0;
        j = 0;
        while (isalpha(line[i])) {
            // Convert to lowercase
            line[j] = tolower(line[i]);
            i++;
            j++;
        }
        line[j] = '\0';

        // Check for misspelled words
        k = 0;
        while (k < dictionarySize && strcmp(dictionary[k].word, line)!= 0) {
            k++;
        }
        if (k == dictionarySize) {
            printf("Possible misspelling: %s\n", line);
        }
    }

    fclose(inputFile);

    return 0;
}