//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 1000

struct word_count {
    char word[MAX_WORD_LEN];
    int count;
};

void add_word(struct word_count *word_counts, int num_words, char *word) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(word_counts[i].word, word) == 0) {
            word_counts[i].count++;
            return;
        }
    }
    strcpy(word_counts[num_words].word, word);
    word_counts[num_words].count = 1;
    num_words++;
}

void print_word_counts(struct word_count *word_counts, int num_words) {
    int i;
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int is_word_char(char c) {
    return isalnum(c) || c == '\'';
}

int main() {
    char input_buffer[1000000];
    char *input_ptr = input_buffer;
    int input_size = 0;
    int word_counts_size = 0;
    struct word_count *word_counts = NULL;

    printf("Enter text to count words:\n");
    fgets(input_buffer, sizeof(input_buffer), stdin);
    input_size = strlen(input_buffer);

    word_counts = malloc(sizeof(struct word_count));
    if (word_counts == NULL) {
        printf("Error: out of memory\n");
        return 1;
    }
    word_counts_size = 1;

    char *word_start = input_buffer;
    char *word_end = input_buffer;

    while (*word_end!= '\0') {
        if (!is_word_char(*word_end)) {
            *word_end = '\0';
            add_word(word_counts, word_counts_size, word_start);
            word_start = word_end + 1;
        }
        word_end++;
    }

    add_word(word_counts, word_counts_size, word_start);

    print_word_counts(word_counts, word_counts_size);

    free(word_counts);

    return 0;
}