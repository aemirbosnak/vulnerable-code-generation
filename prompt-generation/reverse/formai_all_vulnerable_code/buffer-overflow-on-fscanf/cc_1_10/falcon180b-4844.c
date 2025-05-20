//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: medieval
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

void read_words(struct word words[], int *num_words) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open words.txt\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(file, "%s", words[i].word)!= EOF) {
        i++;
        if (i == MAX_WORDS) {
            printf("Error: Too many words in words.txt\n");
            exit(1);
        }
    }

    *num_words = i;
    fclose(file);
}

int compare(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void sort_words(struct word words[], int num_words) {
    qsort(words, num_words, sizeof(struct word), compare);
}

void spell_check(char *text, int text_length, struct word words[], int num_words) {
    int i, j;
    char word[MAX_WORD_LENGTH];

    for (i = 0; i < text_length; i++) {
        if (isalpha(text[i])) {
            word[0] = tolower(text[i]);
            word[1] = '\0';

            int found = 0;
            for (j = 0; j < num_words; j++) {
                if (strcmp(word, words[j].word) == 0) {
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
    int num_words;

    read_words(words, &num_words);
    sort_words(words, num_words);

    char *text = "Ye olde spelling checkere example. This program doth checketh thy spelling of words. It is quite useful for ensuring thou art using correct medieval English.";
    int text_length = strlen(text);

    spell_check(text, text_length, words, num_words);

    return 0;
}