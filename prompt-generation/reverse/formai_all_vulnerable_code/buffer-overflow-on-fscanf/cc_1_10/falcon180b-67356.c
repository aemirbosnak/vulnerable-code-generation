//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

struct word {
    char text[MAX_WORD_LENGTH];
    int frequency;
};

void load_words(struct word *words) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words file.\n");
        exit(1);
    }

    int num_words = 0;
    while (fscanf(file, "%s %d", words[num_words].text, &words[num_words].frequency) == 2) {
        num_words++;
        if (num_words >= MAX_WORDS) {
            printf("Too many words in file.\n");
            exit(1);
        }
    }

    fclose(file);
}

void generate_theory(struct word *words) {
    srand(time(NULL));

    int num_words = rand() % MAX_WORDS + 1;
    int theory_length = rand() % 50 + 10;
    char theory[theory_length];

    int i = 0;
    while (i < num_words) {
        int word_index = rand() % MAX_WORDS;
        strncat(theory, words[word_index].text, strlen(words[word_index].text));
        i++;
    }

    printf("Theory: %s\n", theory);
}

int main() {
    struct word words[MAX_WORDS];
    load_words(words);

    int num_theories = rand() % 10 + 1;
    for (int i = 0; i < num_theories; i++) {
        generate_theory(words);
    }

    return 0;
}