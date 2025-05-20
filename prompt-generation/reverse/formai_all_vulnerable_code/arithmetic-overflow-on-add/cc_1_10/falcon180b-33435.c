//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(const char* filename, WordCount* word_counts, int word_count_size) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int index = hash(word);
        if (index >= 0 && index < word_count_size) {
            word_counts[index].count++;
        }
    }

    fclose(file);
}

int hash(const char* word) {
    int sum = 0;
    for (int i = 0; i < strlen(word); i++) {
        sum += word[i];
    }
    return sum % MAX_WORD_LENGTH;
}

void print_word_counts(WordCount* word_counts, int word_count_size) {
    for (int i = 0; i < word_count_size; i++) {
        if (word_counts[i].count > 0) {
            printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    WordCount word_counts[MAX_WORD_LENGTH];
    int word_count_size = 0;

    read_file(argv[1], word_counts, MAX_WORD_LENGTH);
    word_count_size = MAX_WORD_LENGTH;

    print_word_counts(word_counts, word_count_size);

    return 0;
}