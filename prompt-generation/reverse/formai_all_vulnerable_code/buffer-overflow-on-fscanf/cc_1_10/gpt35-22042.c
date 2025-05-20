//FormAI DATASET v1.0 Category: Spell checking ; Style: puzzling
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* Puzzle: Can you figure out how to correctly spell check this program? */

#define DICTIONARY "dictionary.txt"
#define MAX_WORD_LENGTH 45

void tolowercase(char *word);

int main(void) {
    char word[MAX_WORD_LENGTH];
    char c;
    int i = 0;

    FILE *dict = fopen(DICTIONARY, "r");
    if (dict == NULL) {
        printf("Dictionary not found!\n");
        return 1;
    }

    printf("Enter a sentence to be spell checked:\n");

    while ((c = getchar()) != '\n') {
        if (isalpha(c)) {
            word[i++] = tolower(c);
        } else if (isspace(c)) {
            word[i] = '\0';
            i = 0;

            char dict_word[MAX_WORD_LENGTH];
            while (fscanf(dict, "%s", dict_word) != EOF) {
                if (strcmp(dict_word, word) == 0) {
                    break;
                }
            }
            rewind(dict);

            if (strlen(dict_word) == strlen(word)) {
                printf("%s ", word);
            } else {
                printf("<%s> ", word);
            }
        }
    }

    fclose(dict);
    return 0;
}

void tolowercase(char *word) {
    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
}