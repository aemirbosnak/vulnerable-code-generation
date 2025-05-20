//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 10000

struct word_count {
    char *word;
    int count;
};

int compare_words(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main(int argc, char *argv[]) {
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int word_count = 0;

    struct word_count *word_array = malloc(MAX_WORDS * sizeof(struct word_count));
    if (word_array == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory.\n");
        exit(1);
    }

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open file %s.\n", argv[1]);
        exit(1);
    }

    while ((read = getline(&line, &len, file))!= -1) {
        char *word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            int i;
            for (i = 0; i < word_count; i++) {
                if (strcmp(word_array[i].word, word) == 0) {
                    word_array[i].count++;
                    break;
                }
            }
            if (i == word_count) {
                if (word_count >= MAX_WORDS) {
                    fprintf(stderr, "Error: Maximum word count reached.\n");
                    exit(1);
                }
                word_array[word_count].word = strdup(word);
                word_array[word_count].count = 1;
                word_count++;
            }
            word = strtok(NULL, ",.?!;:");
        }
    }

    qsort(word_array, word_count, sizeof(struct word_count), compare_words);

    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", word_array[i].word, word_array[i].count);
    }

    free(line);
    fclose(file);
    free(word_array);

    return 0;
}