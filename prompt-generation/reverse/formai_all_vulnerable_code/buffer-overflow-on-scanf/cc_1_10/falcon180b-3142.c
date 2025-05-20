//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void read_file(FILE *file, char *filename) {
    char ch;
    int i = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            if (i >= MAX_WORD_LEN) {
                printf("Error: Word is too long. Skipping...\n");
            } else {
                strncat(filename, &ch, 1);
                i++;
            }
        } else {
            if (i > 0) {
                filename[i] = '\0';
                i = 0;
            }
        }
    }
}

void count_words(char *filename, WordCount words[]) {
    FILE *file;
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }
    read_file(file, filename);
    fclose(file);

    int j = 0;
    for (int i = 0; i < strlen(filename); i++) {
        if (isalpha(filename[i])) {
            words[j].word[0] = tolower(filename[i]);
            words[j].word[1] = '\0';
            words[j].count = 1;
            j++;
        }
    }
}

void print_word_counts(WordCount words[], int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    char filename[MAX_WORD_LEN];
    printf("Enter file name: ");
    scanf("%s", filename);

    WordCount words[MAX_WORDS];
    count_words(filename, words);

    printf("Word counts:\n");
    print_word_counts(words, MAX_WORDS);

    return 0;
}