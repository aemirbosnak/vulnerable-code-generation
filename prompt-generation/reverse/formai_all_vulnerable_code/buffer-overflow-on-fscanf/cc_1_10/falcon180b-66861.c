//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

struct word {
    char word[MAX_WORD_LENGTH];
    int is_correct;
};

void load_words(struct word words[]) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open words.txt\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(file, "%s", words[i].word)!= EOF) {
        i++;
        if (i >= MAX_WORDS) {
            printf("Error: too many words in words.txt\n");
            exit(1);
        }
    }

    fclose(file);
}

void spell_check(char text[], struct word words[]) {
    int i, j, k;
    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            char word[MAX_WORD_LENGTH];
            int word_length = 0;

            for (j = i; j < strlen(text) && isalpha(text[j]); j++) {
                word[word_length++] = tolower(text[j]);
            }
            word[word_length] = '\0';

            for (k = 0; k < MAX_WORDS; k++) {
                if (strcmp(word, words[k].word) == 0) {
                    words[k].is_correct = 1;
                    break;
                }
            }
        }
    }
}

void print_results(struct word words[]) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].is_correct == 0) {
            printf("%s\n", words[i].word);
        }
    }
}

int main() {
    char text[1000];
    printf("Enter text to spell check: ");
    fgets(text, sizeof(text), stdin);

    struct word words[MAX_WORDS];
    load_words(words);

    spell_check(text, words);

    printf("\nSpell check complete.\n");
    print_results(words);

    return 0;
}