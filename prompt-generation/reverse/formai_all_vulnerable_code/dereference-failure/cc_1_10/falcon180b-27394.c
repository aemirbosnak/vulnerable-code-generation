//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define DICTIONARY_FILE "dictionary.txt"

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
} WordInfo;

void loadDictionary(WordInfo words[], FILE *file) {
    char line[MAX_WORD_LENGTH+1];
    while (fgets(line, MAX_WORD_LENGTH+1, file)!= NULL) {
        int len = strlen(line);
        if (line[len-1] == '\n') {
            line[--len] = '\0';
        }
        strcpy(words[len].word, line);
        words[len].is_correct = true;
    }
}

void spellCheck(char text[], WordInfo words[], int numWords) {
    char word[MAX_WORD_LENGTH];
    int i = 0;
    while ((i = strspn(text, ".!?"))!= strlen(text)) {
        strncpy(word, text, i);
        word[i] = '\0';
        int j;
        for (j = 0; j < numWords; j++) {
            if (strcmp(word, words[j].word) == 0) {
                words[j].is_correct = true;
                break;
            }
        }
        if (j == numWords) {
            printf("Possible spelling mistake: %s\n", word);
        }
        text += i;
    }
}

int main() {
    FILE *file;
    file = fopen(DICTIONARY_FILE, "r");
    if (file == NULL) {
        printf("Error: could not open dictionary file.\n");
        return 1;
    }
    WordInfo words[100000];
    loadDictionary(words, file);
    fclose(file);
    char text[100000];
    printf("Enter text to spell check:\n");
    fgets(text, 100000, stdin);
    spellCheck(text, words, 100000);
    return 0;
}