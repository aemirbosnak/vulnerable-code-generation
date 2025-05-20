//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void loadWords(char* filename, WordFrequency* words) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error loading words file.\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        WordFrequency* w = &words[0];
        while (w->word[0]!= '\0' && strcmp(w->word, word)!= 0) {
            w++;
        }
        if (w->word[0] == '\0') {
            strcpy(w->word, word);
            w->count = 0;
        }
        w->count++;
    }

    fclose(file);
}

void spellCheck(char* filename, WordFrequency* words) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error loading file.\n");
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, sizeof(line), file)!= NULL) {
        char* token = strtok(line, ",.!?;:");
        while (token!= NULL) {
            int i;
            for (i = 0; i < strlen(token); i++) {
                token[i] = tolower(token[i]);
            }
            WordFrequency* w = &words[0];
            while (w->word[0]!= '\0' && strcmp(w->word, token)!= 0) {
                w++;
            }
            if (w->word[0] == '\0') {
                printf("Unknown word: %s\n", token);
            } else {
                w->count++;
            }
            token = strtok(NULL, ",.!?;:");
        }
    }

    fclose(file);
}

void printWordFrequencies(WordFrequency* words) {
    printf("Word frequencies:\n");
    WordFrequency* w = &words[0];
    while (w->word[0]!= '\0') {
        printf("%s: %d\n", w->word, w->count);
        w++;
    }
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        printf("Usage: %s <words_file> <text_file>\n", argv[0]);
        exit(1);
    }

    WordFrequency words[MAX_WORDS];
    loadWords(argv[1], words);

    spellCheck(argv[2], words);

    printWordFrequencies(words);

    return 0;
}