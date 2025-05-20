//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: ephemeral
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(FILE *file, WordCount *word_counts, int num_words) {
    char ch;
    int i = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (isspace(ch)) {
            word_counts[i].word[word_counts[i].count] = '\0';
            i++;
            if (i >= num_words) {
                break;
            }
        } else {
            word_counts[i].word[word_counts[i].count++] = ch;
        }
    }
    word_counts[i].word[word_counts[i].count] = '\0';
}

void count_words(WordCount *word_counts, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    WordCount word_counts[MAX_WORDS];
    int num_words = 0;

    read_file(file, word_counts, MAX_WORDS);
    count_words(word_counts, num_words);

    fclose(file);
    return 0;
}