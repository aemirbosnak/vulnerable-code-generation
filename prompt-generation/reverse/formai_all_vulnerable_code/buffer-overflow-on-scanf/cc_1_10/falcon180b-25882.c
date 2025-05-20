//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word {
    char text[MAX_WORD_LENGTH];
    int frequency;
};

int compare_words(const void *a, const void *b) {
    const struct word *word_a = a;
    const struct word *word_b = b;

    return strcmp(word_a->text, word_b->text);
}

void print_word_frequency(const struct word *word_table, int num_words) {
    qsort(word_table, num_words, sizeof(struct word), compare_words);

    for (int i = 0; i < num_words; ++i) {
        printf("%s: %d\n", word_table[i].text, word_table[i].frequency);
    }
}

int main() {
    FILE *input_file;
    char filename[MAX_WORD_LENGTH];
    char line[MAX_WORD_LENGTH];
    int num_words = 0;
    struct word word_table[MAX_WORDS];

    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    input_file = fopen(filename, "r");

    if (input_file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, input_file)!= NULL) {
        char *token = strtok(line, ",.?!;:\"'");

        while (token!= NULL) {
            if (num_words >= MAX_WORDS) {
                printf("Too many words in the input file.\n");
                exit(1);
            }

            strcpy(word_table[num_words].text, token);
            ++word_table[num_words].frequency;
            ++num_words;

            token = strtok(NULL, ",.?!;:\"'");
        }
    }

    fclose(input_file);

    print_word_frequency(word_table, num_words);

    return 0;
}