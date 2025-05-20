//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 100

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

int compare_words(const void *a, const void *b) {
    struct word_count *word_a = (struct word_count *)a;
    struct word_count *word_b = (struct word_count *)b;

    return strcmp(word_a->word, word_b->word);
}

int main(int argc, char *argv[]) {
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    int num_words = 0;
    struct word_count *word_counts = malloc(MAX_WORDS * sizeof(struct word_count));

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error: could not open file '%s'\n", argv[1]);
        exit(1);
    }

    while ((getline(&line, &len, file))!= -1) {
        char *word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(word, word_counts[i].word) == 0) {
                    word_counts[i].count++;
                    break;
                }
            }

            if (i == num_words) {
                if (num_words >= MAX_WORDS) {
                    printf("Error: maximum number of words (%d) exceeded\n", MAX_WORDS);
                    exit(1);
                }

                strncpy(word_counts[num_words].word, word, MAX_WORD_LENGTH);
                word_counts[num_words].word[MAX_WORD_LENGTH - 1] = '\0';
                word_counts[num_words].count = 1;
                num_words++;
            }

            word = strtok(NULL, ",.?!;:");
        }
    }

    qsort(word_counts, num_words, sizeof(struct word_count), compare_words);

    printf("Total words: %d\n", num_words);

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    free(word_counts);
    free(line);

    return 0;
}