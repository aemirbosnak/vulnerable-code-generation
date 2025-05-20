//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(char *filename, WordCount words[]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(words[i].word, word) == 0) {
                words[i].count++;
                break;
            }
        }
        if (i == MAX_WORDS) {
            printf("Error: Too many unique words in file\n");
            exit(1);
        }
    }

    fclose(file);
}

void write_file(char *filename, WordCount words[]) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            fprintf(file, "%s %d\n", words[i].word, words[i].count);
        }
    }

    fclose(file);
}

void translate(char *input_file, char *output_file) {
    WordCount english_words[MAX_WORDS];
    WordCount alien_words[MAX_WORDS];

    read_file(input_file, english_words);

    int num_alien_words = 0;
    for (int i = 0; i < MAX_WORDS; i++) {
        if (english_words[i].count > 0) {
            char alien_word[MAX_WORD_LENGTH];
            sprintf(alien_word, "x%d", num_alien_words++);
            strcpy(alien_words[i].word, alien_word);
        }
    }

    write_file(output_file, alien_words);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        exit(1);
    }

    translate(argv[1], argv[2]);

    printf("Translation complete!\n");
    return 0;
}