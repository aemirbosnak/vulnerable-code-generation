//Falcon-180B DATASET v1.0 Category: Data mining ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

struct word_freq {
    char word[MAX_WORD_LEN];
    int freq;
};

void read_file(FILE *fp, struct word_freq *words, int *num_words) {
    char ch;
    int i = 0;
    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            words[i].word[0] = tolower(ch);
            int j = 1;
            while ((ch = fgetc(fp))!= EOF && isalpha(ch)) {
                words[i].word[j++] = tolower(ch);
            }
            words[i].word[j] = '\0';
            words[i].freq++;
            i++;
        } else if (isspace(ch)) {
            continue;
        } else {
            fprintf(stderr, "Invalid character '%c' encountered\n", ch);
            exit(1);
        }
    }
    *num_words = i;
}

void sort_words(struct word_freq *words, int num_words) {
    for (int i = 0; i < num_words - 1; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (words[j].freq > words[i].freq) {
                struct word_freq temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

void print_words(struct word_freq *words, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].freq);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file '%s'\n", argv[1]);
        return 1;
    }

    struct word_freq words[MAX_WORDS];
    int num_words = 0;

    read_file(fp, words, &num_words);
    sort_words(words, num_words);
    print_words(words, num_words);

    fclose(fp);
    return 0;
}