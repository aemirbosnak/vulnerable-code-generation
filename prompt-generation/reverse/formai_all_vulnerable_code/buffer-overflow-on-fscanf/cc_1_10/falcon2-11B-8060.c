//Falcon2-11B DATASET v1.0 Category: Spell checking ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 10000

void spellCheck(char* text, char* dictionary) {
    char words[MAX_WORDS][MAX_WORD_LENGTH + 1];
    int numWords = 0;
    int numErrors = 0;

    strcpy(words[numWords++], text);

    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL) {
        printf("Error opening dictionary file.\n");
        return;
    }

    char word[MAX_WORD_LENGTH + 1];
    while (fscanf(dict, "%s", word) == 1) {
        numWords++;
    }
    fclose(dict);

    char *temp;
    int i, j, k;

    for (i = 0; i < numWords; i++) {
        for (j = 0; j < strlen(words[i]); j++) {
            words[i][j] = tolower(words[i][j]);
        }

        for (k = 0; k < strlen(dictionary); k++) {
            if (strncmp(words[i], dictionary, strlen(dictionary)) == 0) {
                numErrors++;
                break;
            }
        }
    }

    printf("Number of errors: %d\n", numErrors);
}

int main() {
    char text[MAX_WORD_LENGTH + 1];
    char dictionary[MAX_WORD_LENGTH + 1];

    printf("Enter the text to be spell checked: ");
    fgets(text, MAX_WORD_LENGTH, stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Enter the dictionary file: ");
    fgets(dictionary, MAX_WORD_LENGTH, stdin);
    dictionary[strcspn(dictionary, "\n")] = '\0';

    spellCheck(text, dictionary);

    return 0;
}