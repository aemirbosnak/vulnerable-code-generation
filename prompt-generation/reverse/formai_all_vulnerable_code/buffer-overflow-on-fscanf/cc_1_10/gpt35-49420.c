//FormAI DATASET v1.0 Category: Spell checking ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 50
#define MAX_DICT_LEN 10000

/**
 * A struct to represent a single word with its frequency count
 */
typedef struct Word {
    char word[MAX_WORD_LEN];
    int frequency;
} Word;

int compareWords(const void *a, const void *b) {
    return strcmp(((Word *) a)->word, ((Word *) b)->word);
}

void removePunctuation(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (ispunct(str[i])) {
            for (int j = i; j < strlen(str); j++) {
                str[j] = str[j+1];
            }
            i--;
        }
    }
}

int main() {
    char dictFileName[50], inputFile[50];
    printf("Enter the dictionary file name: ");
    scanf("%s", dictFileName);
    printf("Enter the input file name: ");
    scanf("%s", inputFile);

    // Read dictionary into an array of Word structs
    FILE *dictFile = fopen(dictFileName, "r");
    Word dictionary[MAX_DICT_LEN];
    int dictSize = 0;
    char dictWord[MAX_WORD_LEN];
    while (fscanf(dictFile, "%s", dictWord) != EOF) {
        strcpy(dictionary[dictSize].word, dictWord);
        dictionary[dictSize].frequency = 0;
        dictSize++;
    }
    fclose(dictFile);

    // Sort dictionary array alphabetically for binary search
    qsort(dictionary, dictSize, sizeof(Word), compareWords);

    // Read input file and count frequencies of each word
    FILE *input = fopen(inputFile, "r");
    char currentWord[MAX_WORD_LEN];
    while (fscanf(input, "%s", currentWord) != EOF) {
        removePunctuation(currentWord);
        int index = bsearch(&currentWord, dictionary, dictSize, sizeof(Word), compareWords);
        if (index != -1) {
            dictionary[index].frequency++;
        }
    }
    fclose(input);

    // Print all misspelled words to output file
    FILE *output = fopen("misspelled.txt", "w");
    for (int i = 0; i < dictSize; i++) {
        if (dictionary[i].frequency == 0) {
            fprintf(output, "%s\n", dictionary[i].word);
        }
    }
    fclose(output);

    return 0;
}