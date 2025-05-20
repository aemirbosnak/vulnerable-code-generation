//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20
#define MAX_THEORIES 100

char words[MAX_WORDS][MAX_WORD_LENGTH];
int num_words;

void load_words(char *filename) {
    FILE *file = fopen(filename, "r");
    char line[MAX_WORD_LENGTH];
    char *word;
    int i = 0;

    while (fgets(line, MAX_WORD_LENGTH, file)) {
        word = strtok(line, " ");

        while (word!= NULL) {
            if (strlen(word) <= MAX_WORD_LENGTH) {
                strcpy(words[i], word);
                i++;
            }

            word = strtok(NULL, " ");
        }
    }

    num_words = i;

    fclose(file);
}

void generate_theory() {
    char theory[MAX_THEORIES][MAX_WORD_LENGTH];
    int num_theories = 0;

    srand(time(NULL));

    while (num_theories < MAX_THEORIES) {
        int start_index = rand() % num_words;
        int end_index = rand() % num_words;

        if (start_index == end_index) {
            continue;
        }

        int num_words_in_theory = rand() % (end_index - start_index + 1) + 2;

        for (int i = 0; i < num_words_in_theory; i++) {
            int word_index = start_index + i;

            if (word_index >= num_words) {
                word_index -= num_words;
            }

            strcpy(theory[num_theories], words[word_index]);
            num_theories++;
        }
    }

    for (int i = 0; i < num_theories; i++) {
        printf("%s\n", theory[i]);
    }
}

int main() {
    char filename[MAX_WORD_LENGTH];

    printf("Enter filename: ");
    scanf("%s", filename);

    load_words(filename);
    generate_theory();

    return 0;
}