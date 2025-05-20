//MISTRAL-7B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Sherlock Holmes
// Sherlock's Genome Sequencer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 10000
#define ALPHABET_SIZE 26

typedef struct {
    char base;
    int count;
} nucleotide_t;

void read_file(char *filename, nucleotide_t *nucleotides) {
    FILE *file = fopen(filename, "r");
    char sequence[MAX_LEN];
    char c;

    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while ((c = fgetc(file)) != EOF) {
        if (isalpha(c)) {
            int index = tolower(c) - 'a';
            nucleotides[index].count++;
            sequence[nucleotides[index].count++] = c;
        }
    }

    fclose(file);

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (nucleotides[i].count > 0) {
            printf("%c: %s\n", i + 'A', sequence);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    nucleotide_t nucleotides[ALPHABET_SIZE];

    read_file(argv[1], nucleotides);

    return EXIT_SUCCESS;
}