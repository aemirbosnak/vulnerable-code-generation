//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: brave
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

void read_file(FILE *file, struct word_count words[MAX_WORDS]) {
    char ch;
    int i = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (isspace(ch)) {
            words[i].word[words[i].count] = '\0';
            i++;
            if (i >= MAX_WORDS) {
                printf("Maximum number of words exceeded.\n");
                exit(1);
            }
        } else {
            if (words[i].count >= MAX_WORD_LENGTH) {
                printf("Maximum word length exceeded.\n");
                exit(1);
            }
            words[i].word[words[i].count++] = tolower(ch);
        }
    }
    words[i].word[words[i].count] = '\0';
    i++;
}

void count_words(struct word_count words[MAX_WORDS], int num_words, char *filename) {
    FILE *file;
    if ((file = fopen(filename, "r")) == NULL) {
        printf("Error opening file %s.\n", filename);
        exit(1);
    }
    read_file(file, words);
    fclose(file);

    printf("Word count for %s:\n", filename);
    for (int i = 0; i < num_words; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }

    int num_words = 0;
    struct word_count words[MAX_WORDS];

    while (num_words < MAX_WORDS && argv[++argc]!= NULL) {
        count_words(words, num_words, argv[argc]);
        num_words += 1;
    }

    return 0;
}