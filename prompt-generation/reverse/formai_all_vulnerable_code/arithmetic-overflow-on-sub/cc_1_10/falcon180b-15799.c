//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(FILE *file, char *filename) {
    char ch;
    int i = 0;
    int in_word = 0;
    WordCount words[MAX_WORDS];

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            in_word = 1;
        } else if (in_word) {
            words[i].word[words[i].count] = '\0';
            words[i].count++;
            in_word = 0;
            i++;
        }
    }

    if (in_word) {
        words[i].word[words[i].count] = '\0';
        words[i].count++;
    }
}

void sort_words(WordCount *words, int n) {
    int i, j;
    WordCount temp;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(words[i].word, words[j].word) > 0) {
                temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

void print_word_counts(WordCount *words, int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    char filename[100];
    WordCount words[MAX_WORDS];
    int n;

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    read_file(file, filename);
    fclose(file);

    sort_words(words, n);
    print_word_counts(words, n);

    return 0;
}