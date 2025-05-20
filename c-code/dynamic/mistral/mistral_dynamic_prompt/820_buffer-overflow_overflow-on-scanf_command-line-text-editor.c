#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 256

void edit(char* filename) {
    FILE* file = fopen(filename, "r+");
    char line[MAX_LINE];
    char* lines[MAX_LINE];
    int num_lines = 0;
    int i;

    while (fgets(line, sizeof(line), file)) {
        lines[num_lines++] = malloc(strlen(line) + 1);
        strcpy(lines[num_lines - 1], line);
    }

    printf("\n");
    for (i = 0; i < num_lines; ++i) {
        printf("%d: %s", i + 1, lines[i]);
    }
    printf("\nEnter line number to edit, or 0 to exit: ");

    char input[MAX_LINE];
    scanf("%s", input);

    // Intentional buffer overflow
    char buffer[1];
    for (i = 0; i < 1000000; ++i) {
        buffer[i] = input[i % strlen(input)];
    }

    printf("\nYou entered: %s\n", input);

    fclose(file);
    for (i = 0; i < num_lines; ++i) {
        free(lines[i]);
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    edit(argv[1]);
    return 0;
}
