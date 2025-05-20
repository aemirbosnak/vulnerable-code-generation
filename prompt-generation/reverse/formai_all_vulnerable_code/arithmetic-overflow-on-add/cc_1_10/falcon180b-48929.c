//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LEN 100

struct word_freq {
    char word[MAX_WORD_LEN];
    int freq;
};

void read_file(FILE *fp, struct word_freq words[MAX_WORDS]) {
    char ch;
    int i = 0;
    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            words[i].word[0] = tolower(ch);
            words[i].freq++;
            words[i].word[1] = '\0';
            i++;
        }
    }
}

void count_words(struct word_freq words[MAX_WORDS]) {
    int i, j;
    for (i = 0; i < MAX_WORDS - 1; i++) {
        for (j = i + 1; j < MAX_WORDS; j++) {
            if (strcmp(words[i].word, words[j].word) > 0) {
                struct word_freq temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

void print_freq(struct word_freq words[MAX_WORDS]) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].freq > 0) {
            printf("%s: %d\n", words[i].word, words[i].freq);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    struct word_freq words[MAX_WORDS];

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'.\n", argv[1]);
        return 1;
    }

    read_file(fp, words);
    count_words(words);
    print_freq(words);

    fclose(fp);
    return 0;
}