//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

void read_file(FILE *file, struct word_count *word_counts, int num_words) {
    char ch;
    int i = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (isspace(ch)) {
            word_counts[i].count++;
            i++;
            if (i >= num_words) {
                break;
            }
        } else {
            strncat(word_counts[i].word, &ch, 1);
        }
    }
}

void sort_word_counts(struct word_count *word_counts, int num_words) {
    for (int i = 0; i < num_words - 1; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (word_counts[i].count < word_counts[j].count) {
                struct word_count temp = word_counts[i];
                word_counts[i] = word_counts[j];
                word_counts[j] = temp;
            }
        }
    }
}

void print_word_counts(struct word_count *word_counts, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    FILE *file;
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    struct word_count word_counts[MAX_WORDS];
    int num_words = 0;
    read_file(file, word_counts, MAX_WORDS);
    fclose(file);
    sort_word_counts(word_counts, num_words);
    printf("Word frequencies:\n");
    print_word_counts(word_counts, num_words);
    return 0;
}