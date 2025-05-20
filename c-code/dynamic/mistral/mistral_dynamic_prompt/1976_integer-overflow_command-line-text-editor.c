#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

void edit_line(char *buffer, int line) {
    char input[BUFFER_SIZE];

    printf("Edit line %d:\n", line);
    fgets(input, BUFFER_SIZE, stdin);

    // Overflow happens here, assume '\n' as a part of input
    strcpy(buffer + (line * BUFFER_SIZE), input);
}

int main() {
    char file_content[10][BUFFER_SIZE];
    int num_lines;

    printf("Enter number of lines: ");
    scanf("%d", &num_lines);

    // Initialize file content
    for (int i = 0; i < num_lines; ++i) {
        printf("Enter line %d: ", i + 1);
        fgets(file_content[i], BUFFER_SIZE, stdin);
    }

    printf("\nEditing mode:\n");

    while (1) {
        printf("\nEnter line number to edit (or type 'q' to quit): ");
        char line_to_edit;
        scanf(" %c", &line_to_edit);

        if (line_to_edit == 'q')
            break;

        edit_line(file_content[(int)line_to_edit - 1], (int)line_to_edit - 1);

        // Overflow is exploitable here if the input is large enough.
        printf("\nPress any key to continue...");
        getchar();
    }

    printf("\nSaving file...\n");

    return 0;
}
