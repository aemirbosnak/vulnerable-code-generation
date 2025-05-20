//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>

#define MAX_LINE_LEN 8192
#define MAX_WORD_LEN 1024

char *line = NULL;
size_t line_len = 0;

void read_file(FILE *fp) {
    char ch;
    while ((ch = fgetc(fp))!= EOF) {
        if (line_len >= MAX_LINE_LEN) {
            printf("Error: Line too long.\n");
            exit(1);
        }
        line = realloc(line, line_len + 1);
        line[line_len++] = tolower(ch);
    }
}

void tokenize(char *line) {
    char *word = line;
    char *delim = " \t\r\n\a";
    while (*word) {
        if (strchr(delim, *word)) {
            *word = '\0';
            printf("%s\n", word);
            word++;
        } else {
            word++;
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    read_file(fp);
    fclose(fp);

    tokenize(line);

    free(line);
    return 0;
}