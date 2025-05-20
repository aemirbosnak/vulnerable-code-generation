//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: curious
// C Spell Checking Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

struct word {
    char word[MAX_WORD_LEN];
    int count;
};

void load_words(struct word words[MAX_WORDS], int count) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words file.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(file, "%s", words[i].word)!= EOF) {
        i++;
        if (i >= MAX_WORDS) {
            printf("Too many words in file.\n");
            exit(1);
        }
    }

    fclose(file);
    count = i;
}

void spell_check(char *text, struct word words[MAX_WORDS], int count) {
    int i, j;
    char word[MAX_WORD_LEN];

    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            word[0] = tolower(text[i]);
            for (j = 1; j < MAX_WORD_LEN && isalpha(text[i + j]); j++) {
                word[j] = tolower(text[i + j]);
            }
            word[j] = '\0';

            int found = 0;
            for (int k = 0; k < count; k++) {
                if (strcmp(word, words[k].word) == 0) {
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Possible spelling error: %s\n", word);
            }
        }
    }
}

int main() {
    struct word words[MAX_WORDS];
    int count = 0;

    load_words(words, count);

    char text[1000];
    printf("Enter text to spell check: ");
    fgets(text, sizeof(text), stdin);

    spell_check(text, words, count);

    return 0;
}