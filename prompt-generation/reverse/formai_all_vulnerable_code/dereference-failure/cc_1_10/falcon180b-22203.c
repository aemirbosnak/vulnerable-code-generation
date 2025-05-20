//Falcon-180B DATASET v1.0 Category: File handling ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1000
#define MAX_WORD_SIZE 50

char *read_line(FILE *file) {
    char line[MAX_LINE_SIZE];
    fgets(line, MAX_LINE_SIZE, file);
    return strdup(line);
}

char *read_word(char *line) {
    char word[MAX_WORD_SIZE];
    char *p = line;
    int i = 0;

    while (*p && isspace(*p)) {
        p++;
    }

    while (*p &&!isspace(*p)) {
        word[i++] = *p++;
    }

    word[i] = '\0';
    return strdup(word);
}

void write_word(char *word, FILE *outfile) {
    fprintf(outfile, "%s\n", word);
}

int main() {
    FILE *infile, *outfile;
    char *line, *word;

    infile = fopen("in.txt", "r");
    outfile = fopen("out.txt", "w");

    if (infile == NULL || outfile == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while ((line = read_line(infile))!= NULL) {
        word = strtok(line, " ");

        while (word!= NULL) {
            write_word(word, outfile);
            word = strtok(NULL, " ");
        }

        free(line);
    }

    fclose(infile);
    fclose(outfile);

    return 0;
}