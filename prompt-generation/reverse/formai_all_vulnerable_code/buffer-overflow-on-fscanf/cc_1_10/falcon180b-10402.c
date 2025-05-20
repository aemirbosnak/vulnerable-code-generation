//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void read_file(char *filename, WordFrequency *word_frequencies) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (strlen(word) > MAX_WORD_LENGTH) {
            printf("Warning: word '%s' is too long and will be truncated\n", word);
            strncpy(word, word, MAX_WORD_LENGTH - 1);
            word[MAX_WORD_LENGTH - 1] = '\0';
        }

        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        int index = 0;
        while (index < MAX_WORDS && word_frequencies[index].frequency > 0) {
            index++;
        }

        if (index < MAX_WORDS) {
            strcpy(word_frequencies[index].word, word);
            word_frequencies[index].frequency = 1;
        } else {
            printf("Warning: maximum number of words (%d) reached\n", MAX_WORDS);
        }
    }

    fclose(file);
}

void print_frequencies(WordFrequency *word_frequencies) {
    printf("Word frequencies:\n");
    for (int i = 0; i < MAX_WORDS; i++) {
        if (word_frequencies[i].frequency > 0) {
            printf("%s: %d\n", word_frequencies[i].word, word_frequencies[i].frequency);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    WordFrequency word_frequencies[MAX_WORDS];
    read_file(argv[1], word_frequencies);
    print_frequencies(word_frequencies);

    return 0;
}