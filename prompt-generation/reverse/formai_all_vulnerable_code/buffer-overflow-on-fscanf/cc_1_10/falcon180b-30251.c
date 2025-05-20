//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 5000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

bool loadWords(const char* filename, Word* words, int maxWords) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error loading words file: %s\n", filename);
        return false;
    }

    int numWords = 0;
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (numWords >= maxWords) {
            printf("Too many words in file\n");
            break;
        }
        strcpy(words[numWords].word, word);
        words[numWords].count = 0;
        numWords++;
    }

    fclose(file);
    return true;
}

bool isWord(const char* input, int* index, int len) {
    while (*index < len && isalnum(input[*index])) {
        (*index)++;
    }
    return *index > 0 && *index < len;
}

void checkSpelling(const char* input, Word* words, int numWords) {
    int index = 0;
    while (index < strlen(input)) {
        if (isWord(input, &index, strlen(input))) {
            int i = 0;
            while (i < numWords) {
                if (strcmp(words[i].word, input) == 0) {
                    words[i].count++;
                    break;
                }
                i++;
            }
        }
    }
}

void printWords(Word* words, int numWords) {
    printf("Word\tCount\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }
}

int main() {
    Word words[MAX_WORDS];
    int numWords = 0;

    if (!loadWords("words.txt", words, MAX_WORDS)) {
        return 1;
    }

    char input[MAX_WORD_LENGTH];
    while (fgets(input, MAX_WORD_LENGTH, stdin)!= NULL) {
        checkSpelling(input, words, numWords);
    }

    printWords(words, numWords);

    return 0;
}