//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_WORD_SIZE 64

char *trim(char *str) {
    char *end;
    if (str == NULL) {
        return NULL;
    }
    end = str + strlen(str) - 1;
    while (end > str && isspace(*end)) {
        end--;
        *end = '\0';
    }
    return str;
}

int is_word(char *str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (!isalpha(str[i])) {
            return 0;
        }
    }
    return 1;
}

void count_words(char *line, int *word_count) {
    char *word;
    char *next_word;
    char *trimmed_line = trim(line);
    word = strtok(trimmed_line, " ");
    while (word!= NULL) {
        if (is_word(word)) {
            *word_count += 1;
        }
        next_word = strtok(NULL, " ");
        word = next_word;
    }
}

void count_lines_and_words(FILE *fp) {
    char line[MAX_LINE_SIZE];
    int line_count = 0;
    int word_count = 0;
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        line_count += 1;
        count_words(line, &word_count);
    }
    printf("Total lines: %d\n", line_count);
    printf("Total words: %d\n", word_count);
}

int main(int argc, char *argv[]) {
    FILE *fp;
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        exit(1);
    }
    count_lines_and_words(fp);
    fclose(fp);
    return 0;
}