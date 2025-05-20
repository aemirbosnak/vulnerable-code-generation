#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 100

void insert_line(char *text, int line_number) {
    char buffer[256];
    printf("Enter new line: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    if (line_number > MAX_LINES || line_number <= 0) {
        printf("Invalid line number.\n");
        return;
    }
    // Simulate inserting a line by printing it to stdout
    printf("%d: %s\n", line_number, buffer);
}

int main() {
    char *lines[MAX_LINES + 1];
    int num_lines = 0;

    while (1) {
        printf("Text Editor> ");
        char input[32];
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (input[0] == 'q') {
            break;
        } else if (input[0] == 'i' && input[1] == ' ') {
            int line_number = atoi(&input[2]);
            insert_line(lines[num_lines], line_number);
            num_lines++;
        } else {
            printf("Unknown command.\n");
        }
    }

    return 0;
}
