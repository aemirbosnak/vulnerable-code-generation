#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void edit_text(char *filename) {
    FILE *file = fopen(filename, "r+");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    int line_number = 1;

    while (fgets(line, sizeof(line), file)) {
        printf("%d: %s", line_number, line);
        line_number++;
    }

    fseek(file, 0, SEEK_END);

    while (1) {
        printf("\nEnter line number to edit (or 'q' to quit): ");
        char input[10];
        fgets(input, sizeof(input), stdin);
        if (input[0] == 'q') {
            break;
        }

        int edit_line_number = atoi(input);
        if (edit_line_number <= 0) {
            printf("Invalid line number\n");
            continue;
        }

        fseek(file, 0, SEEK_SET);
        line_number = 1;
        char buffer[MAX_LINE_LENGTH];

        while (line_number < edit_line_number && fgets(buffer, sizeof(buffer), file)) {
            line_number++;
        }

        if (line_number != edit_line_number) {
            printf("Line number out of bounds\n");
            continue;
        }

        printf("Enter new content for line %d:\n", edit_line_number);
        fgets(buffer, sizeof(buffer), stdin);
        ftruncate(fileno(file), ftell(file));
        fseek(file, -strlen(buffer), SEEK_CUR);
        fputs(buffer, file);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    edit_text(argv[1]);

    return 0;
}
