//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

int compare_words(const void *a, const void *b) {
    struct word_count *word1 = (struct word_count *)a;
    struct word_count *word2 = (struct word_count *)b;

    if (word1->count > word2->count) {
        return -1;
    } else if (word1->count < word2->count) {
        return 1;
    } else {
        return 0;
    }
}

void print_word_counts(struct word_count *word_counts, int num_words) {
    qsort(word_counts, num_words, sizeof(struct word_count), compare_words);

    printf("Word\tCount\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s\t%d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    char word[MAX_WORD_LENGTH];
    int num_words = 0;
    struct word_count word_counts[MAX_WORDS];

    while (fscanf(file, "%s", word)!= EOF) {
        word[strcspn(word, "\n")] = '\0';
        tolower(word);

        int i = 0;
        while (i < num_words && strcmp(word_counts[i].word, word)!= 0) {
            i++;
        }

        if (i == num_words) {
            if (num_words >= MAX_WORDS) {
                printf("Error: Too many words in file\n");
                fclose(file);
                return 1;
            }

            strcpy(word_counts[num_words].word, word);
            word_counts[num_words].count = 1;
            num_words++;
        } else {
            word_counts[i].count++;
        }
    }

    fclose(file);

    print_word_counts(word_counts, num_words);

    return 0;
}