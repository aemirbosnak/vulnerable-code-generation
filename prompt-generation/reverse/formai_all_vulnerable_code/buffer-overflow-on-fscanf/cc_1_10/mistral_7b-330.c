//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50

typedef struct Word {
    char word[WORD_LENGTH];
    int is_valid;
} Word;

void load_dictionary(FILE *dict_file, Word words[MAX_WORDS]) {
    int index = 0;
    char word[WORD_LENGTH];

    while (fscanf(dict_file, "%s", word) != EOF) {
        strcpy(words[index].word, word);
        words[index].is_valid = 1;
        index++;
    }
}

int is_valid_word(Word words[MAX_WORDS], char *word) {
    int i;

    for (i = 0; i < MAX_WORDS; i++) {
        if (strcasecmp(words[i].word, word) == 0) {
            if (words[i].is_valid) {
                return 1;
            }
            else {
                return 0;
            }
        }
    }

    return 0;
}

void check_spelling(char *input, Word words[MAX_WORDS]) {
    char *token = strtok(input, " ");
    int i;

    while (token != NULL) {
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcasecmp(words[i].word, token) == 0) {
                printf("%s is spelled correctly.\n", token);
                token = strtok(NULL, " ");
                break;
            }
        }

        if (i == MAX_WORDS) {
            printf("%s is not in the dictionary.\n", token);
        }

        token = strtok(NULL, " ");
    }
}

int main() {
    FILE *dict_file;
    Word words[MAX_WORDS];
    char input[1024];

    dict_file = fopen("dictionary.txt", "r");

    if (dict_file == NULL) {
        printf("Error: Unable to open the dictionary file.\n");
        return 1;
    }

    load_dictionary(dict_file, words);
    fclose(dict_file);

    printf("Enter a sentence to check the spelling: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    check_spelling(input, words);

    return 0;
}