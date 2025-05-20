//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_SIZE 100

typedef struct {
    char *word;
    int count;
} WordCount;

void print_word_counts(WordCount *word_counts, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int compare_word_counts(const void *a, const void *b) {
    WordCount *wc1 = (WordCount *)a;
    WordCount *wc2 = (WordCount *)b;

    if (wc1->count > wc2->count) {
        return -1;
    } else if (wc1->count < wc2->count) {
        return 1;
    } else {
        return 0;
    }
}

void read_file(FILE *file, char *text) {
    char ch;

    while ((ch = fgetc(file))!= EOF) {
        if (isalnum(ch)) {
            strncat(text, &ch, 1);
        } else {
            strncat(text, " ", 1);
        }
    }
}

int main() {
    char filename[MAX_WORD_SIZE];
    char text[MAX_WORD_SIZE];
    WordCount word_counts[MAX_WORD_SIZE];
    int num_words = 0;

    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    read_file(file, text);

    char *token = strtok(text, " ");

    while (token!= NULL) {
        if (num_words >= MAX_WORD_SIZE) {
            printf("Maximum number of words exceeded.\n");
            return 1;
        }

        WordCount *wc = &word_counts[num_words];
        wc->word = strdup(token);
        wc->count = 1;

        num_words++;

        token = strtok(NULL, " ");
    }

    fclose(file);

    qsort(word_counts, num_words, sizeof(WordCount), compare_word_counts);

    printf("Word Count:\n");
    print_word_counts(word_counts, num_words);

    return 0;
}