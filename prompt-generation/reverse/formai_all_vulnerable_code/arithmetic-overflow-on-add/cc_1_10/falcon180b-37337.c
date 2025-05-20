//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINES 1000000
#define MAX_LINE_LEN 1000
#define MAX_WORDS_IN_LINE 100

typedef struct {
    char word[MAX_LINE_LEN];
    int count;
} word_t;

typedef struct {
    word_t *words;
    int num_words;
} line_t;

line_t *lines = NULL;
int num_lines = 0;

void add_line(char *line) {
    if (num_lines >= MAX_LINES) {
        printf("Error: too many lines\n");
        return;
    }
    lines = realloc(lines, sizeof(line_t) * ++num_lines);
    line_t *new_line = &lines[num_lines - 1];
    new_line->num_words = 0;
    new_line->words = NULL;
    char *word_start = line;
    while (*word_start) {
        char *word_end = word_start;
        while (isalnum(*word_end)) {
            word_end++;
        }
        int len = word_end - word_start;
        if (len > MAX_LINE_LEN - 1) {
            printf("Error: word too long\n");
            return;
        }
        strncpy(new_line->words[new_line->num_words++].word, word_start, len);
        new_line->words[new_line->num_words - 1].word[len] = '\0';
        word_start = word_end;
    }
}

void print_word_counts() {
    for (int i = 0; i < num_lines; i++) {
        printf("Line %d:\n", i + 1);
        for (int j = 0; j < lines[i].num_words; j++) {
            printf("%s: %d\n", lines[i].words[j].word, lines[i].words[j].count);
        }
    }
}

int main() {
    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, stdin)) {
        add_line(line);
    }
    print_word_counts();
    return 0;
}