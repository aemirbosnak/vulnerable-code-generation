//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word {
    char *text;
    int length;
    int count;
};

struct resume {
    int num_words;
    struct word *words;
};

struct resume *create_resume() {
    struct resume *r = malloc(sizeof(struct resume));
    r->num_words = 0;
    r->words = NULL;
    return r;
}

void add_word(struct resume *r, char *word) {
    int i;
    for (i = 0; i < r->num_words; i++) {
        if (strcmp(r->words[i].text, word) == 0) {
            r->words[i].count++;
            return;
        }
    }
    if (r->num_words >= MAX_WORDS) {
        printf("Error: Maximum number of words reached.\n");
        return;
    }
    r->num_words++;
    r->words = realloc(r->words, sizeof(struct word) * r->num_words);
    r->words[r->num_words - 1].text = strdup(word);
    r->words[r->num_words - 1].length = strlen(word);
    r->words[r->num_words - 1].count = 1;
}

void print_resume(struct resume *r) {
    int i;
    for (i = 0; i < r->num_words; i++) {
        printf("%s: %d\n", r->words[i].text, r->words[i].count);
    }
}

void destroy_resume(struct resume *r) {
    int i;
    for (i = 0; i < r->num_words; i++) {
        free(r->words[i].text);
    }
    free(r->words);
    free(r);
}

int main() {
    char line[MAX_WORD_LENGTH];
    char *word;
    struct resume *r = create_resume();

    while (fgets(line, MAX_WORD_LENGTH, stdin)!= NULL) {
        word = strtok(line, " ");
        while (word!= NULL) {
            add_word(r, word);
            word = strtok(NULL, " ");
        }
    }

    print_resume(r);

    destroy_resume(r);

    return 0;
}