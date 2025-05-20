//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define NUM_WORDS 10000

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
} Word;

int main() {
    FILE *dictionary_file = fopen("dictionary.txt", "r");
    if (dictionary_file == NULL) {
        printf("Error: Could not open dictionary file.\n");
        return 1;
    }

    Word dictionary[NUM_WORDS];
    int num_words_in_dictionary = 0;

    char word[MAX_WORD_LENGTH];
    while (fscanf(dictionary_file, "%s", word)!= EOF) {
        if (num_words_in_dictionary >= NUM_WORDS) {
            printf("Error: Dictionary is full.\n");
            return 1;
        }

        dictionary[num_words_in_dictionary].word[0] = tolower(word[0]);
        strncpy(dictionary[num_words_in_dictionary].word + 1, word + 1, strlen(word) - 1);
        dictionary[num_words_in_dictionary].is_correct = true;
        num_words_in_dictionary++;
    }

    fclose(dictionary_file);

    char text[1000000];
    printf("Enter text to spell check: ");
    fgets(text, sizeof(text), stdin);

    char *token = strtok(text, ",.!?;:\"'");
    while (token!= NULL) {
        int i;
        for (i = 0; i < num_words_in_dictionary; i++) {
            if (strcmp(dictionary[i].word, token) == 0) {
                printf("%s is correct.\n", token);
                break;
            }
        }

        if (i == num_words_in_dictionary) {
            printf("%s is not found in dictionary.\n", token);
        }

        token = strtok(NULL, ",.!?;:\"'");
    }

    return 0;
}