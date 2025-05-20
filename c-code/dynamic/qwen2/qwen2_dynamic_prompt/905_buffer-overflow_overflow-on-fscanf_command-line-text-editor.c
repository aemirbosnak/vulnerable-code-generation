#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

void edit_file(const char *filename) {
    FILE *file = fopen(filename, "r+");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fscanf(file, "%[^\n]", line) != EOF) {
        printf("%s\n", line);
    }

    fseek(file, 0, SEEK_END);

    char new_line[MAX_LINE_LENGTH];
    printf("Enter new line: ");
    fgets(new_line, sizeof(new_line), stdin);

    fprintf(file, "%s", new_line);

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    edit_file(argv[1]);

    return 0;
}
