//FormAI DATASET v1.0 Category: Spell checking ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 30
#define DICTIONARY_FILE "words.txt"

int main() {
    char word[MAX_WORD_LENGTH];
    char dict_word[MAX_WORD_LENGTH];
    int word_len, dict_word_len;
    int i, j, k;
    int found = 0;

    FILE *dict_file = fopen(DICTIONARY_FILE, "r");
    if (dict_file == NULL) {
        printf("Error: Unable to open dictionary file '%s'\n", DICTIONARY_FILE);
        exit(1);
    }

    while (fgets(dict_word, MAX_WORD_LENGTH, dict_file)) {
        dict_word_len = strlen(dict_word);

        if (dict_word[dict_word_len - 1] == '\n') {
            dict_word[dict_word_len - 1] = '\0';
            dict_word_len--;
        }

        printf("Checking Dictionary for '%s'... ", dict_word);

        for (i = 0; i < dict_word_len; i++)
            dict_word[i] = tolower(dict_word[i]);

        printf("Found!\n");
    }

    fclose(dict_file);

    printf("\nEnter word to check: ");
    scanf("%s", word);

    word_len = strlen(word);

    printf("\nChecking spelling for '%s'... ", word);

    for (i = 0; i < word_len; i++)
        word[i] = tolower(word[i]);

    for (i = 1; i <= word_len; i++) {
        for (j = 0; j < i; j++)
            found = 0;

        for (k = 0; k < dict_word_len; k++) {
            if (strlen(dict_word) == i) {
                if (strncmp(dict_word, word + j, i) == 0) {
                    found = 1;
                    break;
                }
            }
        }

        if (found)
            break;
    }

    if (found)
        printf("Correct!\n");
    else
        printf("Incorrect!\n");

    return 0;
}