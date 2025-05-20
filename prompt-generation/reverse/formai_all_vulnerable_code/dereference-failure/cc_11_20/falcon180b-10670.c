//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Could not open file '%s'.\n", filename);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    int line_number = 1;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        // Remove trailing newline character
        line[strcspn(line, "\n")] = '\0';

        // Remove leading and trailing whitespace
        char *trimmed_line = line;
        while (isspace(*trimmed_line)) {
            trimmed_line++;
        }
        while (isspace(*(trimmed_line + strlen(trimmed_line) - 1))) {
            trimmed_line[strlen(trimmed_line) - 1] = '\0';
        }

        // Check if line is a comment
        if (trimmed_line[0] == '#') {
            continue;
        }

        // Check if line is blank
        if (strlen(trimmed_line) == 0) {
            continue;
        }

        // Check if line contains only whitespace
        char *ptr = trimmed_line;
        while (*ptr!= '\0') {
            if (!isspace(*ptr)) {
                break;
            }
            ptr++;
        }
        if (*ptr == '\0') {
            continue;
        }

        // Check if line contains only alphanumeric characters
        char *ptr2 = trimmed_line;
        while (*ptr2!= '\0') {
            if (!isalnum(*ptr2)) {
                break;
            }
            ptr2++;
        }
        if (*ptr2 == '\0') {
            printf("Error: Line %d contains non-alphanumeric characters.\n", line_number);
            fclose(file);
            return 1;
        }

        line_number++;
    }

    fclose(file);
    return 0;
}