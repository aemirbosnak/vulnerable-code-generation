//Falcon-180B DATASET v1.0 Category: Educational ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void read_words(char* filename, WordCount* word_counts, int count) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LEN];
    while (fscanf(fp, "%s", word)!= EOF) {
        int len = strlen(word);
        if (len > MAX_WORD_LEN) {
            printf("Error: word '%s' is too long\n", word);
            exit(2);
        }

        for (int i = 0; i < len; i++) {
            if (!isalpha(word[i])) {
                printf("Error: word '%s' contains non-alphabetic character\n", word);
                exit(3);
            }
        }

        int index = 0;
        while (index < count && strcmp(word_counts[index].word, word)!= 0) {
            index++;
        }

        if (index == count) {
            printf("Error: too many unique words\n");
            exit(4);
        }

        word_counts[index].word[0] = toupper(word[0]);
        strcpy(word_counts[index].word + 1, &word[1]);
        word_counts[index].count = 1;
    }

    fclose(fp);
}

void print_word_counts(WordCount* word_counts, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    char filename[MAX_WORD_LEN];
    printf("Enter filename: ");
    scanf("%s", filename);

    WordCount word_counts[MAX_WORDS];
    int count = 0;

    read_words(filename, word_counts, MAX_WORDS);

    print_word_counts(word_counts, count);

    return 0;
}