//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 100
#define MAX_WORDS_IN_LINE 1000

typedef struct {
    char *word;
    int length;
} word_t;

typedef struct {
    word_t *words;
    int num_words;
} line_t;

line_t *read_line(FILE *file) {
    char buffer[MAX_LINE_LENGTH];
    line_t *line = (line_t *)malloc(sizeof(line_t));
    line->num_words = 0;
    line->words = (word_t *)malloc(MAX_WORDS_IN_LINE * sizeof(word_t));

    fgets(buffer, MAX_LINE_LENGTH, file);
    char *token = strtok(buffer, ",.?!;:");

    while (token!= NULL) {
        int length = strlen(token);
        if (length > MAX_WORD_LENGTH) {
            length = MAX_WORD_LENGTH;
        }
        word_t *word = (word_t *)malloc(sizeof(word_t));
        word->word = (char *)malloc(length + 1);
        word->length = length;
        strncpy(word->word, token, length);
        word->word[length] = '\0';
        line->words[line->num_words++] = *word;
        free(word);
        token = strtok(NULL, ",.?!;:");
    }

    return line;
}

void print_line(line_t *line) {
    for (int i = 0; i < line->num_words; i++) {
        printf("%s ", line->words[i].word);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'.\n", argv[1]);
        return 1;
    }

    line_t *line = read_line(file);
    print_line(line);

    free(line->words);
    free(line);
    fclose(file);

    return 0;
}