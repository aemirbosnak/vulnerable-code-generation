//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000
#define MAX_WORD_SIZE 100

typedef struct {
    char word[MAX_WORD_SIZE];
    int count;
} WordCount;

void read_file(FILE *file, char *buffer) {
    int ch;
    int index = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (index < MAX_FILE_SIZE) {
            buffer[index++] = ch;
        }
    }
    buffer[index] = '\0';
}

void tokenize(char *buffer, WordCount *word_counts, int num_word_counts) {
    char *word_start = buffer;
    char *word_end;
    int i = 0;

    while (i < num_word_counts && *buffer!= '\0') {
        word_end = strpbrk(word_start, ",.?!;:\"'");
        if (word_end == NULL) {
            word_end = word_start + strlen(word_start);
        }
        *word_end = '\0';
        strcpy(word_counts[i].word, word_start);
        word_counts[i].count++;
        word_start = word_end + 1;
        i++;
    }
}

void print_word_counts(WordCount *word_counts, int num_word_counts) {
    for (int i = 0; i < num_word_counts; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char buffer[MAX_FILE_SIZE];
    read_file(file, buffer);

    int num_word_counts = 10;
    WordCount word_counts[num_word_counts];

    tokenize(buffer, word_counts, num_word_counts);

    print_word_counts(word_counts, num_word_counts);

    return 0;
}