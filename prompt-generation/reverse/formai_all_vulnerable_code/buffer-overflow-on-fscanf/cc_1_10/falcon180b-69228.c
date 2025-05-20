//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CONSPIRACY_LENGTH 1000
#define MAX_CONSPIRACY_WORDS 20
#define CONSPIRACY_WORD_LIST_FILE "conspiracy_words.txt"
#define CONSPIRACY_OUTPUT_FILE "conspiracy_theory.txt"

typedef struct {
    char *word;
    int probability;
} ConspiracyWord;

void read_word_list(ConspiracyWord *word_list, int num_words) {
    FILE *file = fopen(CONSPIRACY_WORD_LIST_FILE, "r");
    if (file == NULL) {
        printf("Error reading word list file.\n");
        exit(1);
    }

    for (int i = 0; i < num_words; i++) {
        ConspiracyWord word;
        fscanf(file, "%s %d", word.word, &word.probability);
        word_list[i] = word;
    }

    fclose(file);
}

void generate_conspiracy_theory(ConspiracyWord *word_list, int num_words) {
    srand(time(NULL));

    char theory[MAX_CONSPIRACY_LENGTH];
    memset(theory, 0, MAX_CONSPIRACY_LENGTH);

    int word_count = 0;
    while (word_count < MAX_CONSPIRACY_WORDS) {
        int rand_index = rand() % num_words;
        ConspiracyWord rand_word = word_list[rand_index];

        if (word_count == 0) {
            strcat(theory, rand_word.word);
            strcat(theory, " ");
        } else {
            strcat(theory, ", ");
            strcat(theory, rand_word.word);
        }

        word_count++;
    }

    FILE *output_file = fopen(CONSPIRACY_OUTPUT_FILE, "w");
    if (output_file == NULL) {
        printf("Error writing output file.\n");
        exit(1);
    }

    fprintf(output_file, "New conspiracy theory: %s\n", theory);

    fclose(output_file);
}

int main() {
    ConspiracyWord word_list[MAX_CONSPIRACY_WORDS];
    read_word_list(word_list, MAX_CONSPIRACY_WORDS);

    generate_conspiracy_theory(word_list, MAX_CONSPIRACY_WORDS);

    return 0;
}