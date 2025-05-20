//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void read_file(FILE *file, char *filename) {
    char ch;
    int i = 0;
    FILE *fp;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            strcat(file, &ch);
        }
    }

    fclose(fp);
}

int compare_words(const void *a, const void *b) {
    WordFrequency *word1 = (WordFrequency *) a;
    WordFrequency *word2 = (WordFrequency *) b;

    return strcmp(word1->word, word2->word);
}

void print_frequencies(WordFrequency *frequencies, int num_words) {
    qsort(frequencies, num_words, sizeof(WordFrequency), compare_words);

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", frequencies[i].word, frequencies[i].count);
    }
}

int main() {
    char file[MAX_WORDS][MAX_WORD_LENGTH];
    int num_words = 0;
    char word[MAX_WORD_LENGTH];
    int word_length = 0;
    WordFrequency frequencies[MAX_WORDS];

    printf("Enter the name of the input file: ");
    scanf("%s", file[0]);

    read_file(file[0], file[0]);

    for (int i = 0; i < strlen(file[0]); i++) {
        if (isalpha(file[0][i])) {
            word[word_length++] = tolower(file[0][i]);
        } else {
            word[word_length] = '\0';
            if (word_length > 0) {
                strcpy(frequencies[num_words].word, word);
                frequencies[num_words].count = 1;
                num_words++;
                word_length = 0;
            }
        }
    }

    if (word_length > 0) {
        strcpy(frequencies[num_words].word, word);
        frequencies[num_words].count = 1;
        num_words++;
    }

    print_frequencies(frequencies, num_words);

    return 0;
}