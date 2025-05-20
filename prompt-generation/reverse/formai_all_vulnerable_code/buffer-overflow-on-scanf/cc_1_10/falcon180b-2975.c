//Falcon-180B DATASET v1.0 Category: Text processing ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 100

struct word_count {
    char word[MAX_WORD_LEN];
    int count;
};

void read_file(FILE *fp, struct word_count words[MAX_WORDS]) {
    char ch;
    int i = 0;

    while ((ch = fgetc(fp))!= EOF) {
        if (isspace(ch)) {
            words[i].word[strlen(words[i].word) - 1] = '\0';
            i++;
        } else {
            strncat(words[i].word, &ch, 1);
        }
    }

    words[i].word[strlen(words[i].word) - 1] = '\0';
    i++;
}

void count_words(struct word_count words[MAX_WORDS], int num_words) {
    for (int i = 0; i < num_words; i++) {
        for (int j = 0; j < i; j++) {
            if (strcmp(words[i].word, words[j].word) == 0) {
                words[i].count = words[j].count;
                break;
            }
        }

        if (words[i].count == 0) {
            words[i].count = 1;
        }
    }
}

void print_word_counts(struct word_count words[MAX_WORDS], int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    FILE *fp;
    char filename[MAX_WORD_LEN];
    struct word_count words[MAX_WORDS];
    int num_words = 0;

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    read_file(fp, words);
    count_words(words, num_words);
    print_word_counts(words, num_words);

    fclose(fp);

    return 0;
}