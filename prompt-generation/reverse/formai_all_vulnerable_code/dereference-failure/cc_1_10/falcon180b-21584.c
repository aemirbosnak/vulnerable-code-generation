//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000
#define WORD_LENGTH 100

struct word_count {
    char word[WORD_LENGTH];
    int count;
};

int main() {
    FILE *file;
    char line[1024];
    char *word;
    struct word_count *word_counts = malloc(MAX_WORDS * sizeof(struct word_count));
    int num_words = 0;

    if (word_counts == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        word = strtok(line, ",.?!;:\"'");
        while (word!= NULL) {
            if (num_words >= MAX_WORDS) {
                printf("Maximum number of words reached.\n");
                exit(1);
            }
            strcpy(word_counts[num_words].word, word);
            word_counts[num_words].count = 1;
            num_words++;
            word = strtok(NULL, ",.?!;:\"'");
        }
    }

    fclose(file);

    for (int i = 0; i < num_words; i++) {
        if (word_counts[i].count > 1) {
            printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
        }
    }

    free(word_counts);

    return 0;
}