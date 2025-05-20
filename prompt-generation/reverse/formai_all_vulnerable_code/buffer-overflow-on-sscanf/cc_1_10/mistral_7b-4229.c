//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 50
#define MAX_DICTIONARY_SIZE 10000

struct Dictionary {
    char word[MAX_WORD_LENGTH];
};

bool isWordInDictionary(struct Dictionary dictionary[], int size, char *word) {
    for (int i = 0; i < size; i++) {
        if (strcasecmp(dictionary[i].word, word) == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    FILE *dictionaryFile = fopen("dictionary.txt", "r");
    if (dictionaryFile == NULL) {
        printf("Error: Could not open dictionary file.\n");
        return 1;
    }

    struct Dictionary dictionary[MAX_DICTIONARY_SIZE];
    int dictionarySize = 0;

    char line[MAX_WORD_LENGTH];
    while (fgets(line, sizeof(line), dictionaryFile) != NULL) {
        sscanf(line, "%s", dictionary[dictionarySize].word);
        dictionarySize++;
    }

    fclose(dictionaryFile);

    int numWords;
    printf("Enter number of words to check: ");
    scanf("%d", &numWords);

    char inputWord[MAX_WORD_LENGTH];

    for (int i = 0; i < numWords; i++) {
        printf("Enter word %d: ", i + 1);
        scanf("%s", inputWord);

        if (!isWordInDictionary(dictionary, dictionarySize, inputWord)) {
            printf("Misspelled word: %s\n", inputWord);
        }
    }

    return 0;
}