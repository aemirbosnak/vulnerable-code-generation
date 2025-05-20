//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_WORD_LEN 50
#define NUM_WORDS 10000

bool is_valid_word(char *word) {
    FILE *fp = fopen("dictionary.txt", "r");
    char dict_word[MAX_WORD_LEN];
    bool found = false;

    while (!found && fscanf(fp, "%s", dict_word) != EOF) {
        if (strcmp(word, dict_word) == 0) {
            found = true;
        } else {
            int i, j;
            for (i = 0; word[i] != '\0'; i++) {
                word[i] = tolower(word[i]);
                dict_word[i] = tolower(dict_word[i]);
            }
            if (strchr(dict_word, word[0]) && strcmp(word + 1, dict_word + 1 + strlen(dict_word) - strlen(word) + 1) == 0) {
                found = true;
            }
        }
    }

    fclose(fp);
    return found;
}

int main() {
    char input[100][MAX_WORD_LEN];
    int i, j, num_invalid_words = 0;

    for (i = 0; i < 100; i++) {
        printf("Enter word %d: ", i + 1);
        scanf("%s", input[i]);
        j = strlen(input[i]);
        if (j > MAX_WORD_LEN) {
            printf("Word too long. Max length is %d.\n", MAX_WORD_LEN);
            continue;
        }
        if (!is_valid_word(input[i])) {
            printf("%s is not a valid word.\n", input[i]);
            num_invalid_words++;
        }
    }

    printf("\n%d invalid words found.\n", num_invalid_words);

    return 0;
}