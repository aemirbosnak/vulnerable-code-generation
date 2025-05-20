//Falcon-180B DATASET v1.0 Category: Memory management ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define WORD_SIZE 50

typedef struct {
    char *word;
    int count;
} Word;

void read_file(char *filename, Word *words) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    int word_index = 0;
    char line[WORD_SIZE];
    while (fscanf(file, "%s", line)!= EOF) {
        words[word_index].word = strdup(line);
        words[word_index].count = 1;
        word_index++;
    }

    fclose(file);
}

void count_words(Word *words, int num_words) {
    for (int i = 0; i < num_words; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (strcmp(words[i].word, words[j].word) == 0) {
                words[i].count += words[j].count;
                words[j].count = 0;
            }
        }
    }
}

void print_words(Word *words, int num_words) {
    for (int i = 0; i < num_words; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    Word words[MAX_WORDS];
    read_file(filename, words);

    int num_words = 0;
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].word!= NULL) {
            num_words++;
        }
    }

    count_words(words, num_words);
    print_words(words, num_words);

    for (int i = 0; i < num_words; i++) {
        free(words[i].word);
    }

    return 0;
}