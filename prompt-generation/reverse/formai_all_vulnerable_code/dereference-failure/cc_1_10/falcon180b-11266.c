//Falcon-180B DATASET v1.0 Category: Text processing ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64

typedef struct {
    char *text;
    int length;
} Text;

typedef struct {
    char *word;
    int count;
} Word;

void read_file(const char *filename, Text *text) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    text->text = malloc(MAX_LINE_LENGTH);
    text->length = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        int len = strlen(line);
        if (len > MAX_LINE_LENGTH - text->length) {
            printf("Error: line too long\n");
            exit(1);
        }
        strcat(text->text, line);
        text->length += len;
    }

    fclose(file);
}

void tokenize(Text *text, Word *words, int max_words) {
    int i = 0;
    char *token = strtok(text->text, " \t\n\r\f\v.,!?;:\"'()[]{}<>");
    while (token!= NULL && i < max_words) {
        if (strlen(token) > MAX_WORD_LENGTH) {
            printf("Error: word too long\n");
            exit(1);
        }
        words[i].word = malloc(strlen(token) + 1);
        strcpy(words[i].word, token);
        words[i].count = 1;
        i++;
        token = strtok(NULL, " \t\n\r\f\v.,!?;:\"'()[]{}<>");
    }
}

void print_words(Word *words, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    Text text;
    read_file(argv[1], &text);

    Word words[100];
    int num_words = 0;
    tokenize(&text, words, num_words);

    print_words(words, num_words);

    return 0;
}