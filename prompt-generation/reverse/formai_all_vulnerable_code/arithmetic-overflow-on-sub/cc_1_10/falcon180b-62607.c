//Falcon-180B DATASET v1.0 Category: Text processing ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

char *read_line(FILE *file) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char ch;

    line = malloc(MAX_LINE_LENGTH);
    if (!line) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    do {
        read = getline(&line, &len, file);
        if (read == -1) {
            printf("Error reading file.\n");
            exit(EXIT_FAILURE);
        }
    } while (line[read - 1]!= '\n' && read < len - 1);

    line[read] = '\0';

    return line;
}

void process_line(char *line) {
    char *word = strtok(line, " ");
    while (word!= NULL) {
        printf("%s\n", word);
        word = strtok(NULL, " ");
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    char *line;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (!file) {
        printf("Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    line = read_line(file);
    while (line!= NULL) {
        process_line(line);
        line = read_line(file);
    }

    free(line);
    fclose(file);

    return 0;
}