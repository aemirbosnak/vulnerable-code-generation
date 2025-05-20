//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(char* filename, WordCount* word_counts) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    WordCount* current_word_count = word_counts;
    while (fscanf(file, "%s", word) == 1) {
        if (strlen(word) == 0) {
            continue;
        }

        current_word_count->word[0] = tolower(word[0]);
        strcpy(current_word_count->word + 1, word + 1);
        current_word_count->count++;

        if (current_word_count - word_counts >= MAX_WORDS - 1) {
            printf("Error: too many unique words in file '%s'\n", filename);
            fclose(file);
            exit(1);
        }

        current_word_count++;
    }

    fclose(file);
}

void write_index(char* filename, WordCount* word_counts) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: could not create file '%s'\n", filename);
        exit(1);
    }

    for (WordCount* word_count = word_counts; word_count < word_counts + MAX_WORDS; word_count++) {
        if (word_count->count == 0) {
            continue;
        }

        fprintf(file, "%s: ", word_count->word);
        for (int i = 0; i < word_count->count; i++) {
            fprintf(file, "%d ", i + 1);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    WordCount word_counts[MAX_WORDS];
    read_file(argv[1], word_counts);
    write_index(argv[2], word_counts);

    return 0;
}