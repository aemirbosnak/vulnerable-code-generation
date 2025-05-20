//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 50
#define NUM_WORDS 1000

char words[NUM_WORDS][MAX_WORD_LENGTH];
bool dictionary[NUM_WORDS];

void load_dictionary() {
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open dictionary file.\n");
        exit(1);
    }

    int i = 0;
    char word[MAX_WORD_LENGTH];

    while (fscanf(fp, "%s", word) != EOF) {
        strcpy(words[i], word);
        dictionary[i] = true;
        i++;
    }

    fclose(fp);
}

bool is_word(char *word) {
    for (int i = 0; i < NUM_WORDS; i++) {
        if (strcmp(words[i], word) == 0 && dictionary[i]) {
            return true;
        }
    }

    return false;
}

int main() {
    load_dictionary();

    char sentence[100];
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = '\0';

    char *token = strtok(sentence, " ");
    while (token != NULL) {
        if (!is_word(token)) {
            printf("Error: Misspelled word: %s\n", token);
        }
        token = strtok(NULL, " ");
    }

    printf("Sentence checked for misspelled words.\n");

    return 0;
}