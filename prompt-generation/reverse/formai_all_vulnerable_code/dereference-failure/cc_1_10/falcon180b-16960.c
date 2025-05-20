//Falcon-180B DATASET v1.0 Category: Text processing ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64

typedef struct {
    char *word;
    int count;
} WordCount;

int compare_words(const void *a, const void *b) {
    const WordCount *wc1 = a;
    const WordCount *wc2 = b;

    return strcmp(wc1->word, wc2->word);
}

void print_word_counts(WordCount *word_counts, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    char *filename = "input.txt";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *word = NULL;
    int num_words = 0;
    WordCount *word_counts = NULL;

    while ((read = getline(&line, &len, file))!= -1) {
        if (read == 0) {
            continue;
        }

        char *pos = line;
        while ((word = strsep(&pos, " \t\r\n"))!= NULL) {
            if (strlen(word) > MAX_WORD_LENGTH) {
                printf("Error: Word is too long - %s\n", word);
                continue;
            }

            if (num_words >= MAX_LINE_LENGTH) {
                printf("Error: Too many words in line\n");
                break;
            }

            word_counts[num_words].word = strdup(word);
            word_counts[num_words].count = 1;
            num_words++;
        }
    }

    if (line!= NULL) {
        free(line);
    }

    qsort(word_counts, num_words, sizeof(WordCount), compare_words);

    print_word_counts(word_counts, num_words);

    for (int i = 0; i < num_words; i++) {
        free(word_counts[i].word);
    }
    free(word_counts);

    fclose(file);

    return 0;
}