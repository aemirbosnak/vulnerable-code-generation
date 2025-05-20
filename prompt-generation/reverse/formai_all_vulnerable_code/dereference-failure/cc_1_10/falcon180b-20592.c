//Falcon-180B DATASET v1.0 Category: File handling ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *word;
    int count;
} WordCount;

int compare_strings(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void print_word_counts(WordCount *word_counts, int num_words) {
    qsort(word_counts, num_words, sizeof(WordCount), compare_strings);

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    FILE *input_file = fopen("input.txt", "r");

    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    char line[MAX_LINE_SIZE];
    char *word;
    int num_words = 0;
    WordCount *word_counts = NULL;

    while (fgets(line, MAX_LINE_SIZE, input_file)!= NULL) {
        num_words = 0;
        word_counts = realloc(word_counts, sizeof(WordCount) * (num_words + 1));

        char *token = strtok(line, ",.!?;:");
        while (token!= NULL) {
            word = strtok(token, "a-zA-Z0-9");

            if (word!= NULL && strlen(word) > 0) {
                int i;
                for (i = 0; i < num_words; i++) {
                    if (strcmp(word, word_counts[i].word) == 0) {
                        word_counts[i].count++;
                        break;
                    }
                }

                if (i == num_words) {
                    word_counts[num_words].word = strdup(word);
                    word_counts[num_words].count = 1;
                    num_words++;
                }
            }

            token = strtok(NULL, ",.!?;:");
        }
    }

    fclose(input_file);

    print_word_counts(word_counts, num_words);

    free(word_counts);

    return 0;
}