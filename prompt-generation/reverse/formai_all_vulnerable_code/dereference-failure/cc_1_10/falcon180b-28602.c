//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word {
    char word[MAX_WORD_LENGTH];
    int count;
};

struct resume {
    struct word *words;
    int num_words;
};

void initialize_resume(struct resume *r) {
    r->words = (struct word *)malloc(MAX_WORDS * sizeof(struct word));
    r->num_words = 0;
}

void add_word(struct resume *r, char *word) {
    int i;
    for (i = 0; i < r->num_words; i++) {
        if (strcmp(r->words[i].word, word) == 0) {
            r->words[i].count++;
            return;
        }
    }
    if (r->num_words >= MAX_WORDS) {
        printf("Error: Too many words\n");
        exit(1);
    }
    strcpy(r->words[r->num_words].word, word);
    r->words[r->num_words].count = 1;
    r->num_words++;
}

void print_resume(struct resume *r) {
    int i;
    for (i = 0; i < r->num_words; i++) {
        printf("%s: %d\n", r->words[i].word, r->words[i].count);
    }
}

void free_resume(struct resume *r) {
    free(r->words);
}

int main() {
    FILE *fp;
    char line[100];
    char word[MAX_WORD_LENGTH];
    struct resume r;

    initialize_resume(&r);

    fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *token = strtok(line, " ");
        while (token!= NULL) {
            strcpy(word, token);
            add_word(&r, word);
            token = strtok(NULL, " ");
        }
    }

    print_resume(&r);

    free_resume(&r);

    return 0;
}