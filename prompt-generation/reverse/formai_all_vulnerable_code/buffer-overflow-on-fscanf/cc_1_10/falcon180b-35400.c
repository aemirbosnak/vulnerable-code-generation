//Falcon-180B DATASET v1.0 Category: Educational ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORDS 1000
#define MIN_WORD_LENGTH 3
#define MAX_WORD_LENGTH 15

char *words[MAX_WORDS];
int num_words = 0;

void load_words(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH + 1];
    while (fscanf(fp, "%s", word)!= EOF) {
        if (strlen(word) >= MIN_WORD_LENGTH && strlen(word) <= MAX_WORD_LENGTH) {
            words[num_words] = strdup(word);
            num_words++;
        }
    }

    fclose(fp);
}

void generate_poem() {
    srand(time(NULL));

    int num_stanzas = rand() % 10 + 3;
    int num_lines_per_stanza = rand() % 5 + 2;

    for (int i = 0; i < num_stanzas; i++) {
        printf("Stanza %d:\n", i + 1);
        for (int j = 0; j < num_lines_per_stanza; j++) {
            int word_index = rand() % num_words;
            char *word = words[word_index];

            if (j == 0) {
                printf("%s ", toupper(word[0]));
            } else {
                printf("%s ", word);
            }
        }
        printf("\n\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    load_words(argv[1]);
    generate_poem();

    return 0;
}