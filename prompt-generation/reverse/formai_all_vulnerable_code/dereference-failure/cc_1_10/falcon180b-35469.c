//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64

typedef struct {
    char *text;
    int length;
} Word;

typedef struct {
    int count;
    Word *words;
} Line;

typedef struct {
    int num_lines;
    Line *lines;
} Ebook;

Ebook *ebook_open(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        exit(1);
    }

    Ebook *ebook = malloc(sizeof(Ebook));
    ebook->num_lines = 0;
    ebook->lines = NULL;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        Line *line_data = malloc(sizeof(Line));
        line_data->count = 0;
        line_data->words = NULL;

        char *word_start = line;
        while ((word_start = strpbrk(word_start, " \t\n\r\f\v"))!= NULL) {
            *word_start = '\0';
            char *word_end = word_start - 1;
            while (isspace(*word_end)) {
                *word_end = '\0';
                word_end--;
            }

            Word *word_data = malloc(sizeof(Word));
            word_data->text = strdup(word_start + 1);
            word_data->length = strlen(word_data->text);

            line_data->words = realloc(line_data->words, sizeof(Word) * (line_data->count + 1));
            line_data->words[line_data->count++] = *word_data;
        }

        ebook->lines = realloc(ebook->lines, sizeof(Line) * (ebook->num_lines + 1));
        ebook->lines[ebook->num_lines++] = *line_data;
    }

    fclose(file);
    return ebook;
}

void ebook_print(Ebook *ebook) {
    for (int i = 0; i < ebook->num_lines; i++) {
        Line *line_data = ebook->lines + i;
        for (int j = 0; j < line_data->count; j++) {
            Word *word_data = line_data->words + j;
            printf("%s ", word_data->text);
        }
        printf("\n");
    }
}

void ebook_close(Ebook *ebook) {
    for (int i = 0; i < ebook->num_lines; i++) {
        Line *line_data = ebook->lines + i;
        for (int j = 0; j < line_data->count; j++) {
            Word *word_data = line_data->words + j;
            free(word_data->text);
            free(word_data);
        }
        free(line_data->words);
        free(line_data);
    }
    free(ebook->lines);
    free(ebook);
}

int main() {
    Ebook *ebook = ebook_open("example.txt");
    ebook_print(ebook);
    ebook_close(ebook);

    return 0;
}