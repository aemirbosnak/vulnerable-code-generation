//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define DICTIONARY_SIZE 1000

typedef struct Word {
    char word[MAX_WORD_LENGTH + 1];
    struct Word *next;
} Word;

Word *dictionary = NULL;

void add_word(char *word) {
    Word *new_word = (Word *)malloc(sizeof(Word));
    strcpy(new_word->word, word);
    new_word->next = dictionary;
    dictionary = new_word;
}

void load_dictionary() {
    FILE *file;
    char filename[] = "dictionary.txt";
    char word[MAX_WORD_LENGTH + 1];

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Unable to open dictionary file.\n");
        exit(1);
    }

    while (fscanf(file, "%s", word) != EOF) {
        add_word(word);
    }

    fclose(file);
}

int is_word_in_dictionary(char *word) {
    Word *current = dictionary;

    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

void check_spelling(char *text) {
    char *token = strtok(text, " .,\n\t");
    int is_valid_word;

    while (token != NULL) {
        int word_length = strlen(token);

        if (word_length < 2) {
            printf("Warning: Ignoring empty or single-character words.\n");
            token = strtok(NULL, " .,\n\t");
            continue;
        }

        for (int i = 0; i < word_length; i++) {
            token[i] = tolower(token[i]);
        }

        is_valid_word = is_word_in_dictionary(token);

        if (!is_valid_word) {
            printf("Error: '%s' is not a valid word. Did you mean:\n", token);
            // Implement suggestion feature here
            printf("1. apple\n");
            printf("2. ape\n");
            printf("3. apele\n");
            printf("Enter the number of the suggested word: ");
            int suggestion;
            scanf("%d", &suggestion);

            switch (suggestion) {
                case 1:
                    strcpy(token, "apple");
                    break;
                case 2:
                    strcpy(token, "ape");
                    break;
                case 3:
                    strcpy(token, "apele");
                    break;
                default:
                    printf("Invalid suggestion. Re-enter the misspelled word: ");
                    scanf("%s", token);
                    check_spelling(text); // Recursive call to check the corrected word
                    return;
            }
        }

        token = strtok(NULL, " .,\n\t");
    }
}

int main() {
    load_dictionary();

    char text[1000] = "Ths is a test text for speel cheking.";

    check_spelling(text);

    return 0;
}