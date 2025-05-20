//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 50
#define NUM_WORDS 10

void read_file(FILE* file, char** lines, int* num_lines) {
    char line[MAX_LINE_LENGTH];
    int i = 0;
    char* token;

    *num_lines = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (i >= *num_lines) {
            *num_lines += 10;
            lines = realloc(lines, sizeof(char*) * *num_lines);
        }

        lines[*num_lines - 1] = strdup(line);
        i++;
    }
}

void count_words(char** lines, int num_lines, int* num_words) {
    char* line;
    char* token;
    int i = 0;

    *num_words = 0;

    for (i = 0; i < num_lines; i++) {
        line = lines[i];
        token = strtok(line, " ");

        while (token!= NULL) {
            if (strlen(token) > MAX_WORD_LENGTH) {
                printf("Error: Word '%s' is too long.\n", token);
                exit(1);
            }

            (*num_words)++;

            token = strtok(NULL, " ");
        }
    }
}

void print_words(char** words, int num_words) {
    int i;

    for (i = 0; i < num_words; i++) {
        printf("%s ", words[i]);
    }

    printf("\n");
}

void free_lines(char** lines, int num_lines) {
    int i;

    for (i = 0; i < num_lines; i++) {
        free(lines[i]);
    }

    free(lines);
}

int main(int argc, char* argv[]) {
    FILE* file;
    char** lines;
    int num_lines;
    int num_words;

    if (argc!= 2) {
        printf("Error: Wrong number of arguments.\n");
        return 1;
    }

    file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error: Could not open file '%s'.\n", argv[1]);
        return 1;
    }

    read_file(file, &lines, &num_lines);
    count_words(lines, num_lines, &num_words);
    print_words(lines, num_words);

    free_lines(lines, num_lines);

    fclose(file);

    return 0;
}