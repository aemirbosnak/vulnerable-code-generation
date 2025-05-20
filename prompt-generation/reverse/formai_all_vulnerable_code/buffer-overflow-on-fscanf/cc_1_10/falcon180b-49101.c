//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word_frequency {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

int compare_word_frequency(const void *a, const void *b) {
    const struct word_frequency *word_a = a;
    const struct word_frequency *word_b = b;
    return word_b->frequency - word_a->frequency;
}

void add_word(struct word_frequency *word_list, int word_count, const char *word) {
    int i;
    for (i = 0; i < word_count; i++) {
        if (strcmp(word_list[i].word, word) == 0) {
            word_list[i].frequency++;
            return;
        }
    }
    if (word_count >= MAX_WORDS) {
        printf("Error: Maximum number of words reached.\n");
        exit(1);
    }
    strcpy(word_list[word_count].word, word);
    word_list[word_count].frequency = 1;
    word_count++;
}

void print_word_list(const struct word_frequency *word_list, int word_count) {
    qsort(word_list, word_count, sizeof(struct word_frequency), compare_word_frequency);
    printf("Word frequency:\n");
    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", word_list[i].word, word_list[i].frequency);
    }
}

int main() {
    FILE *input_file;
    char input_buffer[MAX_WORD_LENGTH];
    struct word_frequency word_list[MAX_WORDS];
    int word_count = 0;

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    while (fscanf(input_file, "%s", input_buffer)!= EOF) {
        input_buffer[strcspn(input_buffer, "\n")] = '\0';
        add_word(word_list, word_count, input_buffer);
    }

    fclose(input_file);

    print_word_list(word_list, word_count);

    return 0;
}