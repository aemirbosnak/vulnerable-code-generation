//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

void read_file(FILE *file, struct word_count *word_counts, int num_words) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(word_counts[i].word, word) == 0) {
                word_counts[i].count++;
                break;
            }
        }
        if (i == num_words) {
            word_counts[num_words].word[0] = '\0';
            strncat(word_counts[num_words].word, word, MAX_WORD_LENGTH - 1);
            word_counts[num_words].count = 1;
            num_words++;
        }
    }
}

void print_spam_words(struct word_count *word_counts, int num_words) {
    printf("Spam words:\n");
    for (int i = 0; i < num_words; i++) {
        if (word_counts[i].count > 1) {
            printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    struct word_count word_counts[MAX_WORDS];
    int num_words = 0;

    read_file(file, word_counts, num_words);
    fclose(file);

    print_spam_words(word_counts, num_words);

    return 0;
}