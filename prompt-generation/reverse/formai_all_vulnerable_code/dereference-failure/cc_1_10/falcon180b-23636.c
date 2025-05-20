//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCES 1000
#define MAX_WORDS 10000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(FILE *file, char *buffer) {
    int ch;
    int i = 0;

    while ((ch = fgetc(file))!= EOF) {
        if (i >= strlen(buffer)) {
            printf("Error: Buffer overflow\n");
            exit(1);
        }
        buffer[i++] = ch;
    }

    buffer[i] = '\0';
}

int is_word(char *word) {
    int i;

    for (i = 0; i < strlen(word); i++) {
        if (!isalpha(word[i])) {
            return 0;
        }
    }

    return 1;
}

int compare_words(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void count_words(char *sentence, WordCount *word_counts, int num_words) {
    char *token;
    char *copy = strdup(sentence);
    char *context = NULL;

    token = strtok_r(copy, ",.!?;:\"'()[]{}<>", &context);

    while (token!= NULL) {
        if (is_word(token)) {
            int i;

            for (i = 0; i < num_words; i++) {
                if (strcmp(token, word_counts[i].word) == 0) {
                    word_counts[i].count++;
                    break;
                }
            }

            if (i == num_words) {
                WordCount new_word_count;

                strncpy(new_word_count.word, token, MAX_WORD_LENGTH);
                new_word_count.word[MAX_WORD_LENGTH - 1] = '\0';
                new_word_count.count = 1;

                qsort(word_counts, num_words, sizeof(WordCount), compare_words);
                word_counts[num_words] = new_word_count;
                num_words++;
            }
        }

        token = strtok_r(NULL, ",.!?;:\"'()[]{}<>", &context);
    }

    free(copy);
}

void print_word_counts(WordCount *word_counts, int num_words) {
    int i;

    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    char buffer[1024];
    WordCount word_counts[MAX_WORDS];
    int num_words = 0;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error: Could not open file\n");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), file)!= NULL) {
        read_file(file, buffer);

        count_words(buffer, word_counts, num_words);
    }

    print_word_counts(word_counts, num_words);

    fclose(file);

    return 0;
}