//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

struct word {
    char word[MAX_WORD_LENGTH];
    int count;
};

void read_file(FILE *fp, struct word words[MAX_WORDS]) {
    char ch;
    int i = 0;

    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            words[i].word[0] = tolower(ch);
            words[i].count = 1;
            i++;
        } else if (isdigit(ch)) {
            words[i-1].word[words[i-1].count] = ch;
            words[i-1].count++;
        }
    }
}

void sort_words(struct word words[MAX_WORDS]) {
    int i, j;
    struct word temp;

    for (i = 0; i < MAX_WORDS-1; i++) {
        for (j = i+1; j < MAX_WORDS; j++) {
            if (strcmp(words[i].word, words[j].word) > 0) {
                temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

void print_words(struct word words[MAX_WORDS]) {
    int i;

    for (i = 0; i < MAX_WORDS; i++) {
        printf("%s %d\n", words[i].word, words[i].count);
    }
}

int main() {
    FILE *fp;
    struct word words[MAX_WORDS];

    fp = fopen("resume.txt", "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    read_file(fp, words);
    fclose(fp);

    sort_words(words);
    print_words(words);

    return 0;
}