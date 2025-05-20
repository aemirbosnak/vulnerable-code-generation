//Falcon-180B DATASET v1.0 Category: Error handling ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_LINE_LEN 1024

void error(char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(1);
}

void read_file(char *filename, char **lines) {
    FILE *fp;
    char line[MAX_LINE_LEN];
    int num_lines = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        error("Could not open file");
    }

    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        lines[num_lines++] = strdup(line);
    }

    fclose(fp);
}

void write_file(char *filename, char **lines, int num_lines) {
    FILE *fp;
    int i;

    fp = fopen(filename, "w");
    if (fp == NULL) {
        error("Could not open file");
    }

    for (i = 0; i < num_lines; i++) {
        fprintf(fp, "%s", lines[i]);
    }

    fclose(fp);
}

void reverse_lines(char **lines, int num_lines) {
    char *temp;
    int i, j;

    for (i = 0, j = num_lines - 1; i < j; i++, j--) {
        temp = lines[i];
        lines[i] = lines[j];
        lines[j] = temp;
    }
}

void main() {
    char filename[1024];
    char *lines[MAX_LINE_LEN];
    int num_lines = 0;

    printf("Enter filename: ");
    scanf("%s", filename);

    read_file(filename, lines);

    printf("Reversed lines:\n");
    reverse_lines(lines, num_lines);
    write_file(filename, lines, num_lines);
}