//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 10

char *words[MAX_WORDS];
int num_words = 0;

void load_words(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        words[num_words++] = strdup(word);
    }

    fclose(file);
}

void generate_theory() {
    srand(time(NULL));

    int num_words_in_theory = rand() % (MAX_WORDS - 2) + 2;
    char *theory[num_words_in_theory];

    theory[0] = words[rand() % num_words];

    for (int i = 1; i < num_words_in_theory; i++) {
        int j = rand() % num_words;
        while (j == (i - 1)) {
            j = rand() % num_words;
        }
        theory[i] = words[j];
    }

    printf("New conspiracy theory: ");
    for (int i = 0; i < num_words_in_theory; i++) {
        printf("%s ", theory[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <word_list_file> <num_theories>\n", argv[0]);
        return 1;
    }

    load_words(argv[1]);

    int num_theories = atoi(argv[2]);

    for (int i = 0; i < num_theories; i++) {
        generate_theory();
    }

    return 0;
}