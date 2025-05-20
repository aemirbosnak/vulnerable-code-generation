//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    int count;
} WordFrequency;

void ReadWordsFromFile(FILE *file, WordFrequency words[MAX_WORDS]) {
    char word[MAX_WORD_LENGTH + 1];
    int count = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (count >= MAX_WORDS) {
            printf("Error: Maximum number of words exceeded.\n");
            exit(1);
        }

        strcpy(words[count].word, word);
        words[count].count = 1;
        count++;
    }
}

void SpellCheck(char *word, WordFrequency words[MAX_WORDS]) {
    char *corrected_word;
    int i, j, k, n, len;

    len = strlen(word);

    for (i = 0; i < len; i++) {
        if (isalpha(word[i])) {
            word[i] = tolower(word[i]);
        }
    }

    corrected_word = (char *)malloc(len + 1);
    strcpy(corrected_word, word);

    for (i = 0; i < len; i++) {
        if (isalpha(corrected_word[i])) {
            for (j = 0; j < MAX_WORD_LENGTH; j++) {
                if (strcmp(words[j].word, corrected_word) == 0) {
                    free(corrected_word);
                    return;
                }
            }

            for (k = 0; k < i; k++) {
                n = k + 1;
                while (n < len) {
                    if (strcmp(corrected_word + k, corrected_word + n) == 0) {
                        strcpy(corrected_word + k, "");
                        break;
                    }
                    n++;
                }
            }
        }
    }

    printf("Did you mean: %s?\n", corrected_word);
    free(corrected_word);
}

int main(int argc, char *argv[]) {
    FILE *file;
    WordFrequency words[MAX_WORDS];

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    ReadWordsFromFile(file, words);
    fclose(file);

    while (1) {
        char word[MAX_WORD_LENGTH + 1];

        printf("Enter a word to spell check or type 'exit' to quit: ");
        scanf("%s", word);

        if (strcmp(word, "exit") == 0) {
            break;
        }

        SpellCheck(word, words);
    }

    return 0;
}