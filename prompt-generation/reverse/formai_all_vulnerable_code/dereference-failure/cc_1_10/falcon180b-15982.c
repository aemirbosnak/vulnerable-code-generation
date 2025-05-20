//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

int compare_words(const void *a, const void *b) {
    const struct word_count *wc1 = a;
    const struct word_count *wc2 = b;

    return strcmp(wc1->word, wc2->word);
}

int main() {
    FILE *input_file;
    char line[MAX_WORD_LENGTH];
    int word_counts[MAX_WORDS] = {0};
    struct word_count *word_list = malloc(MAX_WORDS * sizeof(struct word_count));

    input_file = fopen("input.txt", "r");

    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, input_file)!= NULL) {
        char *word = strtok(line, " ");

        while (word!= NULL) {
            int i;

            for (i = 0; i < MAX_WORDS; i++) {
                if (strcmp(word, word_list[i].word) == 0) {
                    word_list[i].count++;
                    break;
                }
            }

            if (i == MAX_WORDS) {
                if (word_counts[MAX_WORDS - 1] == 0) {
                    strncpy(word_list[MAX_WORDS - 1].word, word, MAX_WORD_LENGTH - 1);
                    word_list[MAX_WORDS - 1].count = 1;
                }
            }

            word = strtok(NULL, " ");
        }
    }

    fclose(input_file);

    qsort(word_list, MAX_WORDS, sizeof(struct word_count), compare_words);

    printf("Word Counts:\n");

    for (int i = 0; i < MAX_WORDS; i++) {
        if (word_list[i].count > 0) {
            printf("%s: %d\n", word_list[i].word, word_list[i].count);
        }
    }

    free(word_list);

    return 0;
}