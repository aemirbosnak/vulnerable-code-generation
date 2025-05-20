//MISTRAL-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_THEORIES 10
#define WORDS_PER_THEORY 5
#define MAX_WORDS 100
#define SEED 42

typedef struct {
    char word[MAX_WORDS];
    int freq;
} word_t;

void load_dictionary(FILE *fp, word_t *dictionary) {
    fscanf(fp, "%s", dictionary->word);
    for (int i = 0; i < NUM_THEORIES; i++) {
        dictionary[i].freq = rand() % 10 + 1;
    }
}

void generate_theory(word_t *dictionary) {
    srand(SEED);
    printf("Conspiracy Theory %d:\n", rand() % NUM_THEORIES + 1);
    word_t current = {""};
    for (int i = 0; i < WORDS_PER_THEORY; i++) {
        int index = rand() % NUM_THEORIES;
        current = dictionary[index];
        printf("%s ", current.word);
        dictionary[index].freq--;
        if (current.freq <= 0) {
            for (int j = 0; j < NUM_THEORIES; j++) {
                if (dictionary[j].freq > 0) {
                    current = dictionary[j];
                    break;
                }
            }
        }
    }
    printf("\n");
}

int main() {
    word_t dictionary[NUM_THEORIES];
    FILE *fp = fopen("dictionary.txt", "r");
    load_dictionary(fp, dictionary);
    fclose(fp);
    for (int i = 0; i < 10; i++) {
        generate_theory(dictionary);
    }
    return 0;
}