//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void readWords(FILE *file, WordFrequency words[]) {
    char line[MAX_WORD_LENGTH];
    char *word;
    int i = 0;

    while (fgets(line, MAX_WORD_LENGTH, file)) {
        word = strtok(line, ",.?!;:");

        while (word!= NULL) {
            if (strlen(word) > 0 && isalpha(word[0])) {
                strcpy(words[i].word, word);
                words[i].count = 1;
                i++;
            }
            word = strtok(NULL, ",.?!;:");
        }
    }
}

void spellCheck(char word[], WordFrequency words[]) {
    int i, j;
    char *suggestion = NULL;
    int minDistance = MAX_WORD_LENGTH;

    for (i = 0; i < MAX_WORDS; i++) {
        if (strcasecmp(word, words[i].word) == 0) {
            return;
        }

        int distance = 0;
        for (j = 0; j < strlen(word) && j < strlen(words[i].word); j++) {
            if (tolower(word[j])!= tolower(words[i].word[j])) {
                distance++;
            }
        }

        if (distance < minDistance) {
            minDistance = distance;
            suggestion = words[i].word;
        }
    }

    if (suggestion!= NULL) {
        printf("Did you mean %s?\n", suggestion);
    } else {
        printf("No suggestions found.\n");
    }
}

int main() {
    FILE *file;
    char filename[MAX_WORD_LENGTH];
    WordFrequency words[MAX_WORDS];

    printf("Enter the name of the text file to read: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    readWords(file, words);
    fclose(file);

    char word[MAX_WORD_LENGTH];

    while (1) {
        printf("Enter a word to spell check: ");
        scanf("%s", word);

        spellCheck(word, words);
    }

    return 0;
}