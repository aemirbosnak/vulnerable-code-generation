//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to read a line from the input file
char *read_line(FILE *file) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    line = malloc(MAX_LINE_LENGTH);
    if (line == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory.\n");
        exit(1);
    }

    while ((read = getline(&line, &len, file))!= -1) {
        if (read > 0) {
            line[read - 1] = '\0'; // Remove newline character
            break;
        } else {
            line = realloc(line, len + 1);
        }
    }

    return line;
}

// Function to read the contents of the input file into a string
char *read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Failed to open file '%s'.\n", filename);
        exit(1);
    }

    char *contents = NULL;
    size_t len = 0;
    char *line;

    while ((line = read_line(file))!= NULL) {
        contents = realloc(contents, len + strlen(line) + 1);
        strcat(contents, line);
        len += strlen(line);
    }

    fclose(file);
    return contents;
}

// Function to count the number of words in a string
int count_words(const char *str) {
    int count = 0;
    char *token;

    token = strtok(str, " ");
    while (token!= NULL) {
        count++;
        token = strtok(NULL, " ");
    }

    return count;
}

// Function to display the contents of the input file
void display_file(const char *filename) {
    char *contents = read_file(filename);
    int num_words = count_words(contents);

    printf("File contents:\n");
    printf("Number of words: %d\n", num_words);
    printf("%s", contents);
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    display_file(argv[1]);

    return 0;
}