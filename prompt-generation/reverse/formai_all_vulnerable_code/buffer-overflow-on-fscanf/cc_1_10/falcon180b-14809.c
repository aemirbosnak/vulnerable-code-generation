//Falcon-180B DATASET v1.0 Category: Data mining ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void read_file(FILE *file, WordFrequency *word_frequencies) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(word_frequencies[i].word, word) == 0) {
                word_frequencies[i].frequency++;
                break;
            }
        }
        if (i == MAX_WORDS) {
            if (strlen(word) <= MAX_WORD_LENGTH) {
                strcpy(word_frequencies[i].word, word);
                word_frequencies[i].frequency = 1;
            }
        }
    }
}

void print_frequencies(WordFrequency *word_frequencies) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (word_frequencies[i].frequency > 0) {
            printf("%s: %d\n", word_frequencies[i].word, word_frequencies[i].frequency);
        }
    }
}

int main() {
    FILE *file;
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    WordFrequency word_frequencies[MAX_WORDS];
    memset(word_frequencies, 0, sizeof(word_frequencies));

    read_file(file, word_frequencies);

    print_frequencies(word_frequencies);

    fclose(file);

    return 0;
}