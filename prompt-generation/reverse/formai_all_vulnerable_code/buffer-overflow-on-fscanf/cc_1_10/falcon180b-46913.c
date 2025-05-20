//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 255
#define MAX_NUM_WORDS 10000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void add_word(char* word, int count, WordCount* words, int num_words) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(word, words[i].word) == 0) {
            words[i].count += count;
            return;
        }
    }
    if (num_words >= MAX_NUM_WORDS) {
        printf("Error: Maximum number of words reached.\n");
        exit(1);
    }
    strcpy(words[num_words].word, word);
    words[num_words].count = count;
    num_words++;
}

void print_word_counts(WordCount* words, int num_words) {
    printf("Word Count:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }
    char word[MAX_WORD_LENGTH];
    int count = 0;
    int num_words = 0;
    WordCount words[MAX_NUM_WORDS];
    while (fscanf(file, "%s", word)!= EOF) {
        count = 1;
        while (fscanf(file, "%s", word)!= EOF) {
            if (count == 1) {
                count++;
                continue;
            }
            add_word(word, count, words, num_words);
        }
        count = 1;
    }
    fclose(file);
    print_word_counts(words, num_words);
    return 0;
}