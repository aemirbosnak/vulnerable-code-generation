//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool isCorrect;
} Word;

void loadDictionary(Word *dict) {
    FILE *file = fopen("dictionary.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open dictionary file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s", dict[count].word)!= EOF) {
        dict[count].isCorrect = true;
        count++;
        if (count >= MAX_WORDS) {
            break;
        }
    }

    fclose(file);
}

void checkSpelling(char *text, Word *dict) {
    int len = strlen(text);
    int pos = 0;
    while (pos < len) {
        int wordLen = 0;
        while (isalpha(text[pos]) && wordLen < MAX_WORD_LENGTH - 1) {
            text[pos] = tolower(text[pos]);
            pos++;
            wordLen++;
        }
        text[pos] = '\0';

        bool found = false;
        for (int i = 0; i < MAX_WORDS; i++) {
            if (strcmp(dict[i].word, text) == 0) {
                found = true;
                break;
            }
        }

        if (!found) {
            printf("[%d] Misspelled word: %s\n", pos + 1, text);
        } else {
            printf("[%d] Correct word: %s\n", pos + 1, text);
        }

        pos += wordLen;
        while (pos < len &&!isalpha(text[pos])) {
            pos++;
        }
    }
}

int main() {
    Word dict[MAX_WORDS];
    loadDictionary(dict);

    char text[MAX_WORD_LENGTH];
    printf("Enter text to check spelling: ");
    fgets(text, sizeof(text), stdin);
    checkSpelling(text, dict);

    return 0;
}