//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 32

struct word {
    char word[MAX_WORD_LENGTH];
    int count;
};

struct word *word_list = NULL;
int num_words = 0;

void add_word(char *word) {
    struct word *new_word = malloc(sizeof(struct word));
    strcpy(new_word->word, word);
    new_word->count = 0;
    word_list = realloc(word_list, sizeof(struct word) * ++num_words);
    word_list[num_words - 1] = *new_word;
    free(new_word);
}

int compare_words(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void check_spelling(char *text) {
    char *word = strtok(text, ",.?!;:");
    while (word!= NULL) {
        int i = 0;
        while (i < num_words && strcmp(word_list[i].word, word)) {
            i++;
        }
        if (i == num_words) {
            add_word(word);
        } else {
            word_list[i].count++;
        }
        word = strtok(NULL, ",.?!;:");
    }
}

void print_misspelled_words(FILE *output) {
    qsort(word_list, num_words, sizeof(struct word), compare_words);
    for (int i = 0; i < num_words; i++) {
        if (word_list[i].count == 0) {
            fprintf(output, "Misspelled word: %s\n", word_list[i].word);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char text[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", text)!= EOF) {
        check_spelling(text);
    }

    fclose(file);

    FILE *output = fopen("misspelled_words.txt", "w");
    if (output == NULL) {
        printf("Error creating output file.\n");
        return 1;
    }

    print_misspelled_words(output);

    fclose(output);

    return 0;
}