//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct word_t {
    char word[MAX_WORD_LENGTH];
    int frequency;
} Word;

void read_file(FILE *file, Word words[]) {
    char word[MAX_WORD_LENGTH];
    int i = 0;
    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= MAX_WORDS) {
            printf("Error: Too many words in file\n");
            exit(1);
        }
        strcpy(words[i].word, word);
        words[i].frequency = 1;
        i++;
    }
}

void count_words(Word words[], int num_words) {
    for (int i = 0; i < num_words; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (strcmp(words[i].word, words[j].word) == 0) {
                words[i].frequency += words[j].frequency;
                words[j].frequency = 0;
            }
        }
    }
}

void print_words(Word words[], int num_words) {
    for (int i = 0; i < num_words; i++) {
        if (words[i].frequency > 0) {
            printf("%s: %d\n", words[i].word, words[i].frequency);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Unable to open file\n");
        exit(1);
    }

    Word words[MAX_WORDS];
    int num_words = 0;

    read_file(file, words);
    count_words(words, num_words);
    print_words(words, num_words);

    fclose(file);
    return 0;
}