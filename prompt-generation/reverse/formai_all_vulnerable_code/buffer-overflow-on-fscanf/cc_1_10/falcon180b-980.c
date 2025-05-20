//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define WORD_LENGTH 50

typedef struct {
    char word[WORD_LENGTH];
    int frequency;
} word_t;

void read_file(const char* filename, word_t* words) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char buffer[WORD_LENGTH];
    while (fscanf(file, "%s", buffer)!= EOF) {
        int i;
        for (i = 0; i < strlen(buffer); i++) {
            if (!isalpha(buffer[i])) {
                buffer[i] = '\0';
            }
        }
        strcpy(words[i].word, buffer);
        words[i].frequency = 1;
        i++;
    }

    fclose(file);
}

void sort_words(word_t* words, int num_words) {
    int i, j;
    for (i = 0; i < num_words - 1; i++) {
        for (j = 0; j < num_words - i - 1; j++) {
            if (strcmp(words[j].word, words[j+1].word) > 0) {
                word_t temp = words[j];
                words[j] = words[j+1];
                words[j+1] = temp;
            }
        }
    }
}

void print_word_frequencies(word_t* words, int num_words) {
    int i;
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    word_t words[MAX_WORDS];
    read_file(argv[1], words);

    int num_words = 0;
    while (num_words < MAX_WORDS && words[num_words].frequency > 0) {
        num_words++;
    }

    sort_words(words, num_words);
    print_word_frequencies(words, num_words);

    return 0;
}