//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

struct word {
    char word[MAX_WORD_LENGTH];
    int count;
};

void load_words(struct word words[], int count) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words.\n");
        exit(1);
    }

    int i = 0;
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        strcpy(words[i].word, word);
        words[i].count = 0;
        i++;
        if (i >= count) {
            break;
        }
    }

    fclose(file);
}

int compare_words(const void *a, const void *b) {
    struct word *word1 = (struct word *)a;
    struct word *word2 = (struct word *)b;

    return strcmp(word1->word, word2->word);
}

void spell_check(char *text, struct word words[], int count) {
    int i, j;
    char word[MAX_WORD_LENGTH];

    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            word[0] = tolower(text[i]);
            word[1] = '\0';

            qsort(words, count, sizeof(struct word), compare_words);

            for (j = 0; j < count; j++) {
                if (strcmp(word, words[j].word) == 0) {
                    words[j].count++;
                    break;
                }
            }

            if (j == count) {
                printf("%s is not a valid word.\n", word);
            }
        }
    }
}

int main() {
    struct word words[MAX_WORDS];
    int count = 0;

    load_words(words, MAX_WORDS);
    char text[1000];

    printf("Enter text to spell check:\n");
    fgets(text, sizeof(text), stdin);

    spell_check(text, words, count);

    return 0;
}