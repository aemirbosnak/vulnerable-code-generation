//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_SIZE 100000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} DictionaryEntry;

int dictionarySize = 0;
DictionaryEntry dictionary[MAX_DICTIONARY_SIZE];

void loadDictionary(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error loading dictionary file.\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < dictionarySize; i++) {
            if (strcmp(dictionary[i].word, word) == 0) {
                dictionary[i].count++;
                break;
            }
        }
        if (i == dictionarySize) {
            dictionary[dictionarySize].word[0] = tolower(word[0]);
            strcpy(dictionary[dictionarySize].word + 1, word + 1);
            dictionary[dictionarySize].count = 1;
            dictionarySize++;
        }
    }

    fclose(file);
}

int isWord(char* word) {
    int i;
    for (i = 0; i < dictionarySize; i++) {
        if (strcmp(dictionary[i].word, word) == 0) {
            return 1;
        }
    }
    return 0;
}

void spellCheck(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char line[1000];
    while (fgets(line, sizeof(line), file)!= NULL) {
        char word[MAX_WORD_LENGTH];
        char* token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            int i;
            for (i = 0; i < strlen(token); i++) {
                if (!isalpha(token[i])) {
                    token[i] = '\0';
                }
            }
            if (isWord(token)) {
                printf("%s\n", token);
            } else {
                printf("%s\n", token);
            }
            token = strtok(NULL, ",.?!;:");
        }
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s dictionary_file input_file\n", argv[0]);
        exit(1);
    }

    loadDictionary(argv[1]);
    spellCheck(argv[2]);

    return 0;
}