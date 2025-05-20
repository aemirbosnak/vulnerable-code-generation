//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

void load_words(struct word_count *words, int num_words) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words file.\n");
        exit(1);
    }

    int i = 0;
    while (i < num_words && fscanf(file, "%s", words[i].word)!= EOF) {
        i++;
    }

    fclose(file);
}

void count_words(char *text, struct word_count *words, int num_words) {
    char *token = strtok(text, ",.?!;:");
    while (token!= NULL) {
        int j;
        for (j = 0; j < num_words; j++) {
            if (strcmp(token, words[j].word) == 0) {
                words[j].count++;
                break;
            }
        }

        if (j == num_words) {
            printf("Unknown word: %s\n", token);
        }

        token = strtok(NULL, ",.?!;:");
    }
}

void print_word_counts(struct word_count *words, int num_words) {
    printf("Word counts:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    struct word_count words[MAX_WORDS];
    int num_words = 0;

    load_words(words, num_words);
    count_words("Hello world! This is a test. ", words, num_words);

    print_word_counts(words, num_words);

    return 0;
}