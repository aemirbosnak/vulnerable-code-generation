//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char* word;
    int count;
} WordCount;

void initialize_word_count(WordCount* wc) {
    wc->word = NULL;
    wc->count = 0;
}

void free_word_count(WordCount* wc) {
    free(wc->word);
    wc->word = NULL;
    wc->count = 0;
}

void add_word(WordCount* wc, char* word) {
    if (wc->word == NULL) {
        wc->word = strdup(word);
        wc->count = 1;
    } else if (strcmp(word, wc->word) == 0) {
        wc->count++;
    } else {
        char* new_word = realloc(wc->word, strlen(wc->word) + strlen(word) + 2);
        if (new_word == NULL) {
            printf("Error: Out of memory\n");
            exit(1);
        }
        strcat(new_word, " ");
        strcat(new_word, word);
        wc->word = new_word;
        wc->count = 2;
    }
}

void print_word_counts(WordCount* wc) {
    if (wc->word == NULL) {
        printf("No words found\n");
    } else {
        printf("Found %s %d times\n", wc->word, wc->count);
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    WordCount word_count;

    initialize_word_count(&word_count);

    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        int i, j;
        for (i = 0; i < strlen(line); i++) {
            if (isalpha(line[i])) {
                j = i;
                while (isalpha(line[j])) {
                    j++;
                }
                char* word = malloc(j - i + 1);
                strncpy(word, line + i, j - i);
                word[j - i] = '\0';
                add_word(&word_count, word);
                free(word);
            }
        }
    }

    print_word_counts(&word_count);

    free_word_count(&word_count);

    return 0;
}