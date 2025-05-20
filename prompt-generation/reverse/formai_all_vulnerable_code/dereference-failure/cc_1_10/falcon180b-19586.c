//Falcon-180B DATASET v1.0 Category: File handling ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char *word;
    int count;
} WordCount;

void read_file(const char *filename, WordCount *word_counts, int num_word_counts) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s.\n", filename);
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            int i;
            for (i = 0; i < num_word_counts; i++) {
                if (strcmp(word, word_counts[i].word) == 0) {
                    word_counts[i].count++;
                    break;
                }
            }
            if (i == num_word_counts) {
                word_counts[num_word_counts - 1].count++;
            }
            word = strtok(NULL, ",.?!;:");
        }
    }

    fclose(file);
}

void write_word_counts(const char *filename, WordCount *word_counts, int num_word_counts) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file %s.\n", filename);
        exit(1);
    }

    for (int i = 0; i < num_word_counts; i++) {
        fprintf(file, "%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <input_file> <output_file> <word1> [word2]...\n", argv[0]);
        return 1;
    }

    int num_word_counts = argc - 2;
    WordCount *word_counts = malloc(num_word_counts * sizeof(WordCount));

    for (int i = 0; i < num_word_counts; i++) {
        word_counts[i].word = argv[i + 2];
        word_counts[i].count = 0;
    }

    read_file(argv[1], word_counts, num_word_counts);
    write_word_counts(argv[2], word_counts, num_word_counts);

    free(word_counts);
    return 0;
}