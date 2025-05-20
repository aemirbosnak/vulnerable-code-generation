//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LEN 50
#define NUM_WORDS 1000

bool is_valid_word(char *word, char *dictionary[]) {
    for (int i = 0; i < NUM_WORDS; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    char dictionary[NUM_WORDS][MAX_WORD_LEN];
    char input[100][MAX_WORD_LEN];
    int num_words = 0;
    char word[MAX_WORD_LEN];

    FILE *fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error opening dictionary file.\n");
        return 1;
    }

    while (fscanf(fp, "%s", dictionary[num_words]) != EOF) {
        num_words++;
    }

    fclose(fp);

    int num_misspelled = 0;
    printf("Enter text: \n");

    for (int i = 0; i < 100; i++) {
        fgets(input[i], sizeof(input[i]), stdin);
        sscanf(input[i], "%s", word);

        if (strlen(word) > MAX_WORD_LEN) {
            continue;
        }

        bool valid = is_valid_word(word, dictionary);

        if (!valid) {
            printf("Misspelled word: %s\n", word);
            num_misspelled++;
        }
    }

    printf("Number of misspelled words: %d\n", num_misspelled);

    return 0;
}