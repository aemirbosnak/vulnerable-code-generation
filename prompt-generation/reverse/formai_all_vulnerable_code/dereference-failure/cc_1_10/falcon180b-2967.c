//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void read_file(FILE *file, WordFrequency *word_frequencies) {
    char line[2048];
    char *word = NULL;
    size_t word_length = 0;
    while (fgets(line, sizeof(line), file)!= NULL) {
        for (char *p = line; *p!= '\0'; p++) {
            if (isspace(*p)) {
                if (word_length > 0) {
                    word = strndup(line, word_length);
                    word[word_length] = '\0';
                    int index = 0;
                    while (index < MAX_WORDS && word_frequencies[index].frequency > 0) {
                        index++;
                    }
                    if (index < MAX_WORDS) {
                        strcpy(word_frequencies[index].word, word);
                        word_frequencies[index].frequency = 1;
                    } else {
                        printf("Skipping word: %s\n", word);
                    }
                }
                word_length = 0;
            } else if (isalpha(*p)) {
                if (word_length >= MAX_WORD_LENGTH) {
                    printf("Skipping long word starting with: %c\n", *p);
                    break;
                }
                if (word == NULL) {
                    word = malloc(word_length + 2);
                    if (word == NULL) {
                        printf("Out of memory\n");
                        exit(1);
                    }
                    strncpy(word, line, word_length);
                    word[word_length] = *p;
                    word[word_length + 1] = '\0';
                } else {
                    strncat(word, p, 1);
                }
                word_length++;
            }
        }
    }
}

void print_word_frequencies(WordFrequency *word_frequencies) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (word_frequencies[i].frequency > 0) {
            printf("%-30s %d\n", word_frequencies[i].word, word_frequencies[i].frequency);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s FILE\n", argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }
    WordFrequency word_frequencies[MAX_WORDS];
    memset(word_frequencies, 0, sizeof(word_frequencies));
    read_file(file, word_frequencies);
    print_word_frequencies(word_frequencies);
    return 0;
}