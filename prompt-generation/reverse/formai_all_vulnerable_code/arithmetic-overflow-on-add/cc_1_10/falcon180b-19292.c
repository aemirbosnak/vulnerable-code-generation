//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 1024
#define MAX_LINE_LENGTH 1024

struct Word {
    char word[MAX_WORD_LENGTH];
    int count;
};

struct Line {
    char line[MAX_LINE_LENGTH];
    int length;
    struct Word words[100];
};

int is_alpha(char c) {
    if (isalpha(c)) {
        return 1;
    } else {
        return 0;
    }
}

int is_space(char c) {
    if (isspace(c)) {
        return 1;
    } else {
        return 0;
    }
}

void add_word(struct Word *word, char *line, int start, int end) {
    strncpy(word->word, line + start, end - start);
    word->word[end - start] = '\0';
    word->count = 1;
}

void update_word_count(struct Word *word) {
    word->count++;
}

void add_line(struct Line *line, char *line_buffer) {
    int i = 0;
    while (i < MAX_LINE_LENGTH && line_buffer[i]!= '\0') {
        struct Word *word = &line->words[line->length];
        int start = i;
        while (is_alpha(line_buffer[i]) && i < MAX_LINE_LENGTH) {
            i++;
        }
        int end = i;
        if (start!= end) {
            add_word(word, line_buffer, start, end);
        }
        line->length++;
    }
}

void print_word_counts(struct Line *line) {
    for (int i = 0; i < line->length; i++) {
        printf("%s: %d\n", line->words[i].word, line->words[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        exit(1);
    }

    struct Line line;
    char line_buffer[MAX_LINE_LENGTH];
    while (fgets(line_buffer, MAX_LINE_LENGTH, file)!= NULL) {
        add_line(&line, line_buffer);
    }
    fclose(file);

    for (int i = 0; i < line.length; i++) {
        update_word_count(&line.words[i]);
    }

    printf("Word Count:\n");
    print_word_counts(&line);

    return 0;
}