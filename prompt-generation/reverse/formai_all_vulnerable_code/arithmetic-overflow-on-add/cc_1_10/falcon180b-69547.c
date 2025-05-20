//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_SIZE 1000

struct word {
    char word[MAX_WORD_LENGTH];
    int count;
};

struct dictionary {
    struct word words[MAX_DICTIONARY_SIZE];
    int size;
};

int compare_words(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void load_dictionary(struct dictionary *dict, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open dictionary file.\n");
        exit(EXIT_FAILURE);
    }

    dict->size = 0;
    while (fscanf(file, "%s", dict->words[dict->size].word)!= EOF) {
        dict->size++;
    }

    qsort(dict->words, dict->size, sizeof(struct word), compare_words);

    fclose(file);
}

void unload_dictionary(struct dictionary *dict) {
    dict->size = 0;
}

int is_word_in_dictionary(const struct dictionary *dict, const char *word) {
    int i;
    for (i = 0; i < dict->size; i++) {
        if (strcmp(dict->words[i].word, word) == 0) {
            return 1;
        }
    }
    return 0;
}

void spell_check(const struct dictionary *dict, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file.\n");
        exit(EXIT_FAILURE);
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        char *word = strtok(line, ",.!?;:");
        while (word!= NULL) {
            if (is_word_in_dictionary(dict, word)) {
                printf("%s\n", word);
            } else {
                printf("%s\n", word);
            }
            word = strtok(NULL, ",.!?;:");
        }
    }

    fclose(file);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        return 1;
    }

    struct dictionary dict;
    load_dictionary(&dict, argv[1]);
    spell_check(&dict, argv[2]);

    unload_dictionary(&dict);

    return 0;
}