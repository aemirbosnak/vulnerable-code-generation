//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 100000
#define MAX_WORD_LEN 100

typedef struct word_count {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void read_file(FILE *file, WordCount words[], int *num_words) {
    char line[1024];
    char *word = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, file))!= -1) {
        if (line[read - 1] == '\n') {
            line[--read] = '\0';
        }

        word = strtok_r(line, ",.!?;:\"'", &line);

        while (word!= NULL) {
            for (int i = 0; i < strlen(word); i++) {
                if (!isalpha(word[i])) {
                    word[i] = '\0';
                    break;
                }
            }

            if (strlen(word) > 0) {
                int index = 0;

                while (index < *num_words && strcmp(words[index].word, word)!= 0) {
                    index++;
                }

                if (index == *num_words) {
                    if (*num_words >= MAX_WORDS) {
                        printf("Error: Maximum number of words (%d) exceeded.\n", MAX_WORDS);
                        exit(1);
                    }

                    (*num_words)++;
                }

                words[index].count++;
            }

            word = strtok_r(NULL, ",.!?;:\"'", &line);
        }
    }
}

void print_word_counts(WordCount words[], int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    WordCount words[MAX_WORDS];
    int num_words = 0;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error: Unable to open file '%s'.\n", argv[1]);
        return 1;
    }

    read_file(file, words, &num_words);
    fclose(file);

    print_word_counts(words, num_words);

    return 0;
}