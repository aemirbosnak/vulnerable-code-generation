#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

void edit_text(char *filename) {
    FILE *file = fopen(filename, "r+");
    if (!file) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fseek(file, 0, SEEK_END);

    char input[MAX_LINE_LENGTH];
    printf("Enter new text (type 'exit' to save and quit): ");
    while (1) {
        fgets(input, sizeof(input), stdin);
        if (input[0] == 'e' && input[1] == 'x' && input[2] == 'i' && input[3] == 't') {
            break;
        }
        fprintf(file, "%s", input);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    edit_text(argv[1]);

    return 0;
}
