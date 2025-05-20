//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void read_words(char *filename, WordFrequency *words) {
    FILE *file;
    char word[MAX_WORD_LENGTH];
    int i = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= MAX_WORDS) {
            printf("Too many words in file\n");
            exit(1);
        }
        strcpy(words[i].word, word);
        words[i].frequency = 1;
        i++;
    }

    fclose(file);
}

void sort_words(WordFrequency *words) {
    int i, j;
    WordFrequency temp;

    for (i = 0; i < MAX_WORDS - 1; i++) {
        for (j = i + 1; j < MAX_WORDS; j++) {
            if (words[j].frequency > words[i].frequency) {
                temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

void print_top_words(WordFrequency *words, int num_words) {
    int i;

    for (i = 0; i < num_words && i < MAX_WORDS; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main(int argc, char *argv[]) {
    WordFrequency words[MAX_WORDS];

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    read_words(argv[1], words);
    sort_words(words);
    print_top_words(words, 10);

    return 0;
}