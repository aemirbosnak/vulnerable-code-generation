//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: artistic
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

void read_file(char *filename, struct word_count *word_counts, int *num_words) {
    FILE *file;
    char line[MAX_WORD_LENGTH];
    char *word;
    int i = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: unable to open file %s\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        word = line;
        while ((word = strtok(word, ",.?!;:\"'"))!= NULL) {
            if (i >= MAX_WORDS) {
                printf("Error: too many words in file\n");
                exit(1);
            }

            struct word_count *current_word = &word_counts[i];

            strcpy(current_word->word, word);
            current_word->count = 1;

            i++;
        }
    }

    *num_words = i;

    fclose(file);
}

void print_word_counts(struct word_count *word_counts, int num_words) {
    printf("Word\t\tCount\n");
    printf("------------------------\n");

    for (int i = 0; i < num_words; i++) {
        printf("%s\t\t%d\n", word_counts[i].word, word_counts[i].count);
    }
}

void main() {
    char filename[MAX_WORD_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);

    struct word_count word_counts[MAX_WORDS];
    int num_words = 0;

    read_file(filename, word_counts, &num_words);

    print_word_counts(word_counts, num_words);
}