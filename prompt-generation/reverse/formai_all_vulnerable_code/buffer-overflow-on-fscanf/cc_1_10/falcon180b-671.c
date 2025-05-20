//Falcon-180B DATASET v1.0 Category: Text processing ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(FILE *fp, char *filename, char text[MAX_WORDS][MAX_WORD_LENGTH]) {
    int i = 0;
    char word[MAX_WORD_LENGTH];

    while (fscanf(fp, "%s", word)!= EOF) {
        strcpy(text[i], word);
        i++;
    }
}

void count_words(char text[MAX_WORDS][MAX_WORD_LENGTH], int num_words, WordCount counts[MAX_WORDS]) {
    int i, j;

    for (i = 0; i < num_words; i++) {
        for (j = 0; j < MAX_WORDS; j++) {
            if (strcmp(text[i], counts[j].word) == 0) {
                counts[j].count++;
                break;
            }
        }
        if (j == MAX_WORDS) {
            strcpy(counts[j].word, text[i]);
            counts[j].count = 1;
        }
    }
}

void print_counts(WordCount counts[MAX_WORDS], int num_counts) {
    int i;

    for (i = 0; i < num_counts; i++) {
        printf("%s: %d\n", counts[i].word, counts[i].count);
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char filename[100];
    char text[MAX_WORDS][MAX_WORD_LENGTH];
    WordCount counts[MAX_WORDS];
    int num_words;

    printf("Enter the name of the text file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    read_file(fp, filename, text);
    num_words = strlen(text[0]);

    count_words(text, num_words, counts);
    print_counts(counts, num_words);

    fclose(fp);
    return 0;
}