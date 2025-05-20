//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LEN 100

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void read_words(FILE *file, WordCount *word_counts, int num_words) {
    char word[MAX_WORD_LEN];
    while (fscanf(file, "%s", word)!= EOF) {
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        int index = 0;
        while (index < num_words && strcmp(word_counts[index].word, word)!= 0) {
            index++;
        }
        if (index == num_words) {
            printf("Reached max number of words (%d)\n", num_words);
            exit(1);
        }
        word_counts[index].count++;
    }
}

void print_word_counts(WordCount *word_counts, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    FILE *file;
    file = fopen("cyberpunk.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    WordCount word_counts[MAX_WORDS];
    int num_words = 0;

    read_words(file, word_counts, MAX_WORDS);
    num_words = MAX_WORDS;

    print_word_counts(word_counts, num_words);

    fclose(file);
    return 0;
}