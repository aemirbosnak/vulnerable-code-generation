//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORD_COUNT 10000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void add_word(WordCount *word_counts, int count, char *word) {
    for (int i = 0; i < count; i++) {
        strcat(word, " ");
    }
    strcat(word, "\0");
    WordCount *wc = (WordCount *)malloc(sizeof(WordCount));
    strcpy(wc->word, word);
    wc->count = 1;
    int j;
    for (j = 0; j < count; j++) {
        if (word_counts[j].count == 0) {
            break;
        }
    }
    for (int k = count - 1; k >= j; k--) {
        word_counts[k] = word_counts[k - 1];
    }
    word_counts[j] = *wc;
    free(wc);
}

void print_word_counts(WordCount *word_counts, int count) {
    for (int i = 0; i < count; i++) {
        if (word_counts[i].count > 0) {
            printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
        }
    }
}

int main() {
    FILE *file;
    char ch;
    int in_word = 0;
    char word[MAX_WORD_LENGTH];
    int word_length = 0;
    WordCount word_counts[MAX_WORD_COUNT];
    int count = 0;

    file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            in_word = 1;
            word[word_length] = tolower(ch);
            word_length++;
        } else if (in_word) {
            in_word = 0;
            add_word(word_counts, count, word);
            word_length = 0;
        }
    }

    if (in_word) {
        add_word(word_counts, count, word);
    }

    fclose(file);

    print_word_counts(word_counts, count);

    return 0;
}