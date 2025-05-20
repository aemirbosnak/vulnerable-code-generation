//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

struct word_count {
    char word[MAX_WORD_LENGTH + 1];
    int count;
};

int compare_words(const void *a, const void *b) {
    const struct word_count *wc1 = a;
    const struct word_count *wc2 = b;

    return strcmp(wc1->word, wc2->word);
}

void count_words(char *text, struct word_count *word_counts, int num_words) {
    char *word;
    char *start;
    int i;

    for (i = 0; i < num_words; i++) {
        word_counts[i].count = 0;
    }

    word = strtok(text, ",.!?;:");
    while (word!= NULL) {
        start = word;
        while (isalnum(*start)) {
            start++;
        }
        if (start - word <= MAX_WORD_LENGTH) {
            strncpy(word_counts[i].word, word, MAX_WORD_LENGTH);
            word_counts[i].word[MAX_WORD_LENGTH] = '\0';
            word_counts[i].count++;
            i++;
        }
        if (i >= num_words) {
            break;
        }
        word = strtok(NULL, ",.!?;:");
    }
}

void print_word_counts(struct word_count *word_counts, int num_words) {
    int i;

    for (i = 0; i < num_words; i++) {
        if (word_counts[i].count > 0) {
            printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    char *text;
    int text_size;
    struct word_count word_counts[MAX_WORDS];
    int num_words;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", argv[1]);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    text_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    text = malloc(text_size + 1);
    if (text == NULL) {
        printf("Error: could not allocate memory\n");
        fclose(file);
        return 1;
    }

    fread(text, text_size, 1, file);
    text[text_size] = '\0';
    fclose(file);

    num_words = 0;
    count_words(text, word_counts, MAX_WORDS);

    qsort(word_counts, num_words, sizeof(struct word_count), compare_words);

    printf("Word frequencies:\n");
    print_word_counts(word_counts, num_words);

    free(text);
    return 0;
}