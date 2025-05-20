//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

void initialize_word_count_table(struct word_count *table) {
    int i;
    for (i = 0; i < 26; i++) {
        table[i].word[0] = i + 'a';
        table[i].word[1] = '\0';
        table[i].count = 0;
    }
}

int compare_words(const void *a, const void *b) {
    const char *word1 = *(const char **)a;
    const char *word2 = *(const char **)b;
    return strcmp(word1, word2);
}

void count_words(FILE *file, struct word_count *table) {
    char word[MAX_WORD_LENGTH];
    int word_length;
    while (fscanf(file, "%s", word)!= EOF) {
        word_length = strlen(word);
        if (isalpha(word[0])) {
            table[(int)word[0] - 'a'].count++;
        } else if (word_length > 1) {
            table[(int)word[0] - 'a'].count++;
        }
    }
}

void print_word_counts(struct word_count *table) {
    int i;
    qsort(table, 26, sizeof(struct word_count), compare_words);
    for (i = 0; i < 26; i++) {
        printf("%c: %d\n", i + 'a', table[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    struct word_count table[26];
    initialize_word_count_table(table);
    count_words(file, table);
    print_word_counts(table);
    fclose(file);
    return 0;
}