#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 100

char *line;
int num_lines = 0;

void read_line() {
    line = realloc(line, (num_lines + 1) * BUF_SIZE);
    if (!line) {
        fprintf(stderr, "Out of memory!\n");
        exit(1);
    }

    fgets(line + num_lines * BUF_SIZE, BUF_SIZE, stdin);
    num_lines++;
}

void print_lines() {
    for (int i = 0; i < num_lines; ++i)
        printf("%s", line + i * BUF_SIZE);
}

int main() {
    line = malloc(BUF_SIZE);
    if (!line) {
        fprintf(stderr, "Out of memory!\n");
        return 1;
    }

    read_line();
    print_lines();

    char c;
    while ((c = getchar()) != EOF) {
        int i = num_lines * BUF_SIZE;
        line[i] = c;
        read_line();
        line[i - 1] = c;
        print_lines();
    }

    return 0;
}
