//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

struct word_freq {
    char word[MAX_WORD_LEN];
    int freq;
};

void read_words(FILE *fp, struct word_freq words[]) {
    char line[1024];
    int i = 0;

    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *p = line;
        while (*p!= '\0') {
            if (isalpha(*p)) {
                if (i >= MAX_WORDS) {
                    printf("Error: Too many words.\n");
                    exit(1);
                }
                strcpy(words[i].word, p);
                words[i].freq = 1;
                i++;
            }
            p++;
        }
    }
}

void count_words(struct word_freq words[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(words[i].word, words[j].word) == 0) {
                words[i].freq += words[j].freq;
                words[j].freq = 0;
            }
        }
    }
}

void print_words(struct word_freq words[], int n) {
    for (int i = 0; i < n; i++) {
        if (words[i].freq > 0) {
            printf("%s: %d\n", words[i].word, words[i].freq);
        }
    }
}

int main() {
    FILE *fp;
    char filename[MAX_WORD_LEN];
    struct word_freq words[MAX_WORDS];

    printf("Enter the name of the text file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    read_words(fp, words);
    fclose(fp);

    count_words(words, MAX_WORDS);

    printf("Word frequencies:\n");
    print_words(words, MAX_WORDS);

    return 0;
}