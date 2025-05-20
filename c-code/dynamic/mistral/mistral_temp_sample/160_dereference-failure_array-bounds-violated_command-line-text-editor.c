#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024

void edit_line(char *line) {
    char *buffer = (char *)malloc(MAX_LINE * sizeof(char));
    if (!buffer) {
        fprintf(stderr, "Out of memory!\n");
        return;
    }

    printf("Current line: %s\n", line);
    printf("Enter new line (up to %d characters): ", MAX_LINE);
    fgets(buffer, MAX_LINE, stdin);

    free(line);
    strcpy(line, buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r+");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    char line[MAX_LINE];
    int line_number = 1;
    while (fgets(line, MAX_LINE, file)) {
        printf("\nLine %d:\n", line_number);
        edit_line(line);
        fseek(file, ftell(file) - strlen(line), SEEK_SET);
        fputs(line, file);
        line_number++;
    }

    fclose(file);
    return 0;
}
