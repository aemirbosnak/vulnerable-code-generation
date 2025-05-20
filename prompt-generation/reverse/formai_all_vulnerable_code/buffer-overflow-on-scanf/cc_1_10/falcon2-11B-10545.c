//Falcon2-11B DATASET v1.0 Category: Spell checking ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    char correction[MAX_WORD_LENGTH + 1];
} DictionaryEntry;

DictionaryEntry dictionary[10000];

int main() {
    int num_words;
    printf("Enter number of words to check: ");
    scanf("%d", &num_words);

    if (num_words > 0) {
        for (int i = 0; i < num_words; i++) {
            char word[MAX_WORD_LENGTH + 1];
            printf("Enter word %d: ", i + 1);
            fgets(word, MAX_WORD_LENGTH + 1, stdin);
            word[strcspn(word, "\n")] = '\0';
            int j;
            for (j = 0; j < i; j++) {
                if (strcmp(dictionary[j].word, word) == 0) {
                    printf("Word '%s' already exists. Please enter another word.\n", word);
                    break;
                }
            }
            if (j == i) {
                strcpy(dictionary[i].word, word);
                strcpy(dictionary[i].correction, word);
            }
        }
    } else {
        printf("No words entered. Exiting...\n");
    }

    char input[MAX_WORD_LENGTH + 1];
    printf("Enter word to check: ");
    fgets(input, MAX_WORD_LENGTH + 1, stdin);
    input[strcspn(input, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < num_words; i++) {
        if (strcmp(dictionary[i].word, input) == 0) {
            printf("Correct word: '%s'\n", dictionary[i].correction);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No correct word found. Please check spelling and try again.\n");
    }

    return 0;
}