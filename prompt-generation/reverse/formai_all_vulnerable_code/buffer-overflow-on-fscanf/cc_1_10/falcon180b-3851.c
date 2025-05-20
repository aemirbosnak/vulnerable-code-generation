//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 100000

struct word {
    char *word;
    int count;
};

void read_file(FILE *file, struct word words[MAX_WORDS]) {
    char word[100];
    int i = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= MAX_WORDS) {
            printf("Error: Too many words in file.\n");
            exit(1);
        }
        words[i].word = strdup(word);
        words[i].count = 1;
        i++;
    }
}

void spell_check(FILE *file, struct word words[MAX_WORDS]) {
    char word[100];
    int i, j;

    while (fscanf(file, "%s", word)!= EOF) {
        for (i = 0; i < strlen(word); i++) {
            if (!isalpha(word[i])) {
                word[i] = tolower(word[i]);
            }
        }
        for (j = 0; j < MAX_WORDS; j++) {
            if (strcmp(word, words[j].word) == 0) {
                words[j].count++;
                break;
            }
        }
    }
}

void print_results(struct word words[MAX_WORDS]) {
    int i;

    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 1) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    FILE *file;
    struct word words[MAX_WORDS];

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    read_file(file, words);
    fclose(file);

    spell_check(file, words);

    print_results(words);

    return 0;
}