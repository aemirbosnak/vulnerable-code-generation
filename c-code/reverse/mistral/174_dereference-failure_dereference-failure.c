#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 256
#define MAX_LINES 100

void knight_err(const char *message) {
    printf("Oh, brave knight, thou art undone!\n");
    printf("%s\n", message);
    exit(1);
}

int main(int argc, char *argv[]) {
    char *filename;
    FILE *file;
    char line[MAX_NAME_LENGTH];
    int lines_read = 0;

    if (argc != 2)
        knight_err("Thou hast not provided a file, noble knight!");

    filename = argv[1];
    file = fopen(filename, "r");

    if (!file)
        knight_err("The file thou seekest doth not exist, brave knight!");

    while (fgets(line, MAX_NAME_LENGTH, file) && lines_read < MAX_LINES) {
        printf("Line %d:\n%s", lines_read + 1, line);
        lines_read++;
    }

    fclose(file);

    if (lines_read == MAX_LINES)
        printf("The ancient scroll doth reveal its secrets to thee.\n");
    else
        knight_err("The scroll is too long, brave knight! Seek a shorter one.");

    return 0;
}
