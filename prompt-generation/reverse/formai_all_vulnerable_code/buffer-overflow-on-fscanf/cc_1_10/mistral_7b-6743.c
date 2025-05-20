//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALIEN_ALPHABET_SIZE 26

typedef struct alien_dna {
    char dna[ALIEN_ALPHABET_SIZE];
    int translation[ALIEN_ALPHABET_SIZE];
} alien_dna;

void load_alien_dna(alien_dna *alien, const char *filename) {
    FILE *file = fopen(filename, "r");
    int i;

    if (!file) {
        fprintf(stderr, "Error: Unable to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < ALIEN_ALPHABET_SIZE; ++i) {
        fscanf(file, " %c %d", &(alien->dna[i]), &(alien->translation[i]));
    }

    fclose(file);
}

void print_translated_text(const alien_dna *alien, const char *text) {
    int i;

    for (i = 0; text[i] != '\0'; ++i) {
        if (isalpha(text[i])) {
            putchar(alien->translation[tolower(text[i]) - 'a']);
        } else {
            putchar(text[i]);
        }
    }
}

int main(int argc, char *argv[]) {
    alien_dna alien;
    const char *filename;
    const char *text;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <alien_dna_file> <text>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    filename = argv[1];
    text = argv[2];

    load_alien_dna(&alien, filename);
    print_translated_text(&alien, text);

    free(alien.dna);
    free(alien.translation);

    return EXIT_SUCCESS;
}