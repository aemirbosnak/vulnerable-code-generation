//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_SIZE 10000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

Word dictionary[MAX_DICTIONARY_SIZE];
int dictionarySize = 0;

void insertWord(char *word) {
    int i;
    for (i = 0; i < dictionarySize; i++) {
        if (strcmp(dictionary[i].word, word) == 0) {
            dictionary[i].count++;
            return;
        }
    }
    if (dictionarySize < MAX_DICTIONARY_SIZE) {
        strcpy(dictionary[dictionarySize].word, word);
        dictionary[dictionarySize].count = 1;
        dictionarySize++;
    }
}

int findWord(char *word) {
    int i;
    for (i = 0; i < dictionarySize; i++) {
        if (strcmp(dictionary[i].word, word) == 0) {
            return dictionary[i].count;
        }
    }
    return 0;
}

int main() {
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    file = fopen("dictionary.txt", "r");
    if (file == NULL) {
        perror("Error opening dictionary file");
        return EXIT_FAILURE;
    }

    while ((read = getline(&line, &len, file)) != -1) {
        char *word = strtok(line, " \n");
        while (word != NULL) {
            insertWord(word);
            word = strtok(NULL, " \n");
        }
    }

    fclose(file);

    char input[MAX_WORD_LENGTH];
    while (1) {
        printf("Enter a word to check: ");
        scanf("%s", input);
        int count = findWord(input);
        if (count == 0) {
            printf("The word \"%s\" is not in the dictionary.\n", input);
        } else {
            printf("The word \"%s\" appears %d times in the dictionary.\n", input, count);
        }
    }

    return EXIT_SUCCESS;
}