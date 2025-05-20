#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void edit_file(const char *filename) {
    FILE *file = fopen(filename, "r+");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char buffer[MAX_LINE_LENGTH];
    size_t line_number = 0;

    while (fgets(buffer, sizeof(buffer), file)) {
        line_number++;
        printf("%zu: %s", line_number, buffer);
    }

    fclose(file);

    // Intentional dereference failure (forgotten memory)
    char *line_to_edit = NULL;
    printf("Enter line number to edit: ");
    scanf("%zu", &line_number);
    fseek(file, 0, SEEK_SET);

    size_t current_line = 0;
    while (fgets(buffer, sizeof(buffer), file)) {
        current_line++;
        if (current_line == line_number) {
            line_to_edit = buffer; // This is incorrect, buffer is local to this scope
            break;
        }
    }

    if (line_to_edit) {
        printf("Editing line: %s", line_to_edit);
        printf("Enter new content: ");
        fgets(buffer, sizeof(buffer), stdin);
        strcpy(line_to_edit, buffer); // This will overwrite the buffer, not the file
    } else {
        printf("Line not found.\n");
    }

    // Attempt to write back to file (will fail due to forgotten memory)
    fseek(file, 0, SEEK_SET);
    while (fgets(buffer, sizeof(buffer), file)) {
        fputs(buffer, stdout);
    }

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
