//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 100

typedef struct _word_count {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void read_file(FILE *fp, WordCount *word_counts, int max_words) {
    char ch;
    int i = 0;
    while ((ch = fgetc(fp))!= EOF) {
        if (isspace(ch)) {
            word_counts[i].word[strlen(word_counts[i].word) - 1] = '\0';
            i++;
            if (i >= max_words) {
                printf("Maximum number of words reached.\n");
                exit(1);
            }
        } else {
            strncat(word_counts[i].word, &ch, 1);
        }
    }
    word_counts[i].word[strlen(word_counts[i].word) - 1] = '\0';
    i++;
}

void count_words(WordCount *word_counts, int num_words) {
    for (int i = 0; i < num_words; i++) {
        char *word = word_counts[i].word;
        int count = 0;
        while (*word!= '\0') {
            if (isalpha(*word)) {
                count++;
            }
            word++;
        }
        word_counts[i].count = count;
    }
}

void print_word_counts(WordCount *word_counts, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    FILE *fp;
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int num_words = 0;
    WordCount word_counts[100];

    while (fscanf(fp, "%s", word_counts[num_words].word)!= EOF) {
        num_words++;
        if (num_words == 100) {
            printf("Maximum number of words reached.\n");
            exit(1);
        }
    }

    fclose(fp);

    read_file(fp, word_counts, num_words);
    count_words(word_counts, num_words);
    print_word_counts(word_counts, num_words);

    return 0;
}