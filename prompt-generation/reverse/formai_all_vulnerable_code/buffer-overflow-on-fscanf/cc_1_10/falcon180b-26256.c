//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_SIZE 100
#define MAX_DICT_SIZE 1000

struct dict_entry {
    char word[MAX_WORD_SIZE];
    int freq;
};

struct dict_entry dict[MAX_DICT_SIZE];
int dict_size = 0;

int compare_dict_entries(const void *a, const void *b) {
    struct dict_entry *entry_a = (struct dict_entry *)a;
    struct dict_entry *entry_b = (struct dict_entry *)b;

    return entry_a->freq - entry_b->freq;
}

void add_word_to_dict(char *word) {
    int i;
    for (i = 0; i < dict_size; i++) {
        if (strcmp(dict[i].word, word) == 0) {
            dict[i].freq++;
            return;
        }
    }

    if (dict_size >= MAX_DICT_SIZE) {
        qsort(dict, MAX_DICT_SIZE, sizeof(struct dict_entry), compare_dict_entries);
        dict_size = MAX_DICT_SIZE;
    }

    strcpy(dict[dict_size].word, word);
    dict[dict_size].freq = 1;
    dict_size++;
}

void build_dict(char *filename) {
    FILE *fp;
    char word[MAX_WORD_SIZE];

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    while (fscanf(fp, "%s", word)!= EOF) {
        add_word_to_dict(word);
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    build_dict(argv[1]);

    qsort(dict, dict_size, sizeof(struct dict_entry), compare_dict_entries);

    printf("Dictionary sorted by frequency:\n");
    for (int i = 0; i < dict_size; i++) {
        printf("%s %d\n", dict[i].word, dict[i].freq);
    }

    return 0;
}