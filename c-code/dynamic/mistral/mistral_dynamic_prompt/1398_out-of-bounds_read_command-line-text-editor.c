#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 256

void read_file(char *filename) {
    FILE *file = fopen(filename, "r");
    char line[MAX_LINE];

    while (fgets(line, MAX_LINE, file)) {
        printf("%s", line);
    }

    fclose(file);
}

void write_file(char *filename, char *content) {
    FILE *file = fopen(filename, "w");
    fputs(content, file);
    fclose(file);
}

void edit(char *filename) {
    char mode = 'r'; // default to read mode
    char buffer[1];
    printf("Mode: %c\n", mode);

    read_file(filename);

    printf("\nPress r to read, w to write, q to quit: ");
    scanf("%s", buffer);

    if (buffer[0] == 'r') {
        mode = 'r';
    } else if (buffer[0] == 'w') {
        mode = 'w';
    } else if (buffer[0] == 'q') {
        exit(0);
    } else {
        printf("Invalid input. Try again.\n");
        edit(filename);
    }

    if (mode == 'w') {
        char input[MAX_LINE];
        printf("\nEnter content:\n");
        fgets(input, MAX_LINE, stdin);
        write_file(filename, input);
    }
}

int main() {
    char filename[1024];
    printf("Enter file name: ");
    scanf("%s", filename);

    edit(filename);

    return 0;
}
