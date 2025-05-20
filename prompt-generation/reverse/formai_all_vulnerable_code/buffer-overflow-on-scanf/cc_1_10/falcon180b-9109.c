//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_CHARS 1024
#define MAX_WORD_CHARS 64
#define MAX_WORDS 1024

typedef struct {
    char *word;
    int count;
} WordCount;

void read_file(FILE *f, char *line, int max_chars) {
    int ch;
    int i = 0;

    while ((ch = fgetc(f))!= EOF) {
        if (i >= max_chars - 2) {
            fprintf(stderr, "Line too long: %s\n", line);
            exit(1);
        }
        if (isspace(ch)) {
            line[i] = '\0';
            return;
        }
        line[i++] = tolower(ch);
    }
    line[i] = '\0';
}

void tokenize(char *line, char **words, int max_words) {
    char *word = strtok(line, ",.?!;:");
    int i = 0;

    while (word!= NULL && i < max_words) {
        words[i++] = word;
        word = strtok(NULL, ",.?!;:");
    }
}

int main() {
    char filename[MAX_LINE_CHARS];
    char line[MAX_LINE_CHARS];
    WordCount words[MAX_WORDS];
    int num_words = 0;

    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *f = fopen(filename, "r");

    if (f == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_LINE_CHARS, f)!= NULL) {
        read_file(f, line, MAX_LINE_CHARS);

        tokenize(line, words[num_words].word, MAX_WORD_CHARS);
        num_words++;
    }

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}