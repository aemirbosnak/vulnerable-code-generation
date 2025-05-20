//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

struct word {
    char *text;
    int length;
};

struct resume {
    int num_words;
    struct word *words;
};

struct resume *parse_resume(char *text) {
    struct resume *r = malloc(sizeof(struct resume));
    r->num_words = 0;
    r->words = malloc(MAX_WORDS * sizeof(struct word));

    char *p = text;
    while (*p!= '\0') {
        char *word_start = p;
        while (isalnum(*p) || *p == '-') {
            p++;
        }
        int length = p - word_start;
        if (length > 0 && length <= MAX_WORD_LENGTH) {
            if (r->num_words >= MAX_WORDS) {
                fprintf(stderr, "Error: Too many words in resume.\n");
                exit(1);
            }
            r->words[r->num_words].text = malloc(length + 1);
            strncpy(r->words[r->num_words].text, word_start, length);
            r->words[r->num_words].length = length;
            r->num_words++;
        }
        while (!isalnum(*p) && *p!= '-') {
            p++;
        }
    }

    return r;
}

void print_resume(struct resume *r) {
    for (int i = 0; i < r->num_words; i++) {
        printf("%s (%d)\n", r->words[i].text, r->words[i].length);
    }
}

int main() {
    char *text = "John Doe\n123 Main St.\nAnytown, USA 12345\n(123) 456-7890\njdoe@email.com";
    struct resume *r = parse_resume(text);
    print_resume(r);
    free(r->words);
    free(r);
    return 0;
}