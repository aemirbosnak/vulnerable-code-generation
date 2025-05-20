//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

struct word_frequency {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

int compare_words(const void *a, const void *b) {
    const struct word_frequency *w1 = a;
    const struct word_frequency *w2 = b;

    return strcmp(w1->word, w2->word);
}

void print_word_frequency(const struct word_frequency *word_frequency, int num_words) {
    qsort(word_frequency, num_words, sizeof(struct word_frequency), compare_words);

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_frequency[i].word, word_frequency[i].frequency);
    }
}

int main() {
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char line[1000];
    int num_words = 0;
    struct word_frequency word_frequency[MAX_WORDS];

    while (fgets(line, sizeof(line), file)!= NULL) {
        char *token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            if (num_words >= MAX_WORDS) {
                printf("Maximum number of words reached.\n");
                break;
            }

            int word_length = strlen(token);
            if (word_length >= MAX_WORD_LENGTH) {
                printf("Word is too long.\n");
                break;
            }

            strcpy(word_frequency[num_words].word, token);
            word_frequency[num_words].frequency++;
            num_words++;

            token = strtok(NULL, ",.?!;:");
        }
    }

    fclose(file);

    print_word_frequency(word_frequency, num_words);

    return 0;
}