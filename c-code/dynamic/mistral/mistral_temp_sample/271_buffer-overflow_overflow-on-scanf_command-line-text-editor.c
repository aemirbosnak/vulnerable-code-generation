#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 1024

void edit(char *filename) {
    FILE *file;
    char line[MAX_LINE];
    char newline[MAX_LINE];

    if ((file = fopen(filename, "r+")) == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    while (fgets(line, MAX_LINE, file)) {
        printf("%s", line);
        fgets(newline, MAX_LINE, stdin);
        fseek(file, strlen(line), SEEK_CUR);
        fwrite(newline, strlen(newline), 1, file);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    edit(argv[1]);

    return 0;
}
