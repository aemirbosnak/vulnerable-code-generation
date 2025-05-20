//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1000
#define MAX_WORD 100

char *line = NULL;
char **words = NULL;
int num_words = 0;

void read_line(FILE *file) {
    char ch;
    int i = 0;
    if (line!= NULL) {
        free(line);
    }
    line = malloc(MAX_LINE * sizeof(char));
    while ((ch = fgetc(file))!= EOF) {
        if (ch == '\n') {
            line[i] = '\0';
            break;
        }
        line[i] = ch;
        i++;
        if (i >= MAX_LINE) {
            fprintf(stderr, "Line too long!\n");
            exit(1);
        }
    }
    num_words = 0;
    words = malloc(MAX_WORD * sizeof(char *));
}

void tokenize() {
    char *word = strtok(line, " \t\r\n");
    while (word!= NULL) {
        words[num_words++] = strdup(word);
        word = strtok(NULL, " \t\r\n");
    }
}

void print_words() {
    int i;
    for (i = 0; i < num_words; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Cannot open file!\n");
        exit(1);
    }
    read_line(file);
    tokenize();
    print_words();
    free(line);
    int i;
    for (i = 0; i < num_words; i++) {
        free(words[i]);
    }
    free(words);
    return 0;
}