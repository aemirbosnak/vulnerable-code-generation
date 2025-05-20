//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: shape shifting
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct {
    char *word;
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *wc1 = (WordCount *)a;
    WordCount *wc2 = (WordCount *)b;

    return strcmp(wc1->word, wc2->word);
}

int main(int argc, char *argv[]) {
    FILE *file;
    char *line = NULL;
    size_t line_size = 0;
    char *word = NULL;
    size_t word_size = 0;
    WordCount *word_counts = NULL;
    int num_words = 0;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'.\n", argv[1]);
        return 1;
    }

    while ((getline(&line, &line_size, file))!= -1) {
        char *p = line;
        while ((word = strsep(&p, " \t\n\r\f\v.,!?;:\"'"))!= NULL) {
            if (word[0] == '\0' || strlen(word) > MAX_WORD_LENGTH) {
                continue;
            }

            if (num_words >= MAX_WORDS) {
                fprintf(stderr, "Error: Too many words in file.\n");
                fclose(file);
                free(line);
                return 1;
            }

            word_counts = realloc(word_counts, sizeof(WordCount) * ++num_words);
            word_size = strlen(word);
            word_counts[num_words - 1].word = malloc(word_size + 1);
            strcpy(word_counts[num_words - 1].word, word);
            word_counts[num_words - 1].count = 1;
        }
    }

    if (line!= NULL) {
        free(line);
    }

    fclose(file);

    qsort(word_counts, num_words, sizeof(WordCount), compareWords);

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    free(word_counts);

    return 0;
}