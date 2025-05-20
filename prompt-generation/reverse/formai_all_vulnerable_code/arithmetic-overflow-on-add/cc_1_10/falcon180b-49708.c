//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

void read_words(char *filename, struct word_count *word_counts) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(word_counts[i].word, word) == 0) {
                word_counts[i].count++;
                break;
            }
        }
        if (i == MAX_WORDS) {
            printf("Error: too many unique words in file\n");
            exit(1);
        }
    }

    fclose(file);
}

void print_word_counts(struct word_count *word_counts) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (word_counts[i].count > 0) {
            printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    struct word_count word_counts[MAX_WORDS];
    read_words(argv[1], word_counts);
    print_word_counts(word_counts);

    return 0;
}