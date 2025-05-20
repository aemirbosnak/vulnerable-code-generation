//Falcon-180B DATASET v1.0 Category: File handling ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FILE_NAME_LENGTH 50
#define MAX_NUM_LINES 1000

typedef struct {
    char *line;
    int line_number;
} Line;

void print_file_lines(FILE *file, int num_lines) {
    char line[MAX_LINE_LENGTH];
    Line lines[MAX_NUM_LINES];
    int num_printed_lines = 0;

    rewind(file);

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (num_printed_lines >= num_lines) {
            break;
        }

        Line *current_line = &lines[num_printed_lines];
        current_line->line = strdup(line);
        current_line->line_number = num_printed_lines + 1;

        num_printed_lines++;
    }

    for (int i = 0; i < num_printed_lines; i++) {
        printf("%d: %s\n", lines[i].line_number, lines[i].line);
    }
}

int main() {
    FILE *file;
    char file_name[MAX_FILE_NAME_LENGTH];
    char line[MAX_LINE_LENGTH];
    int num_lines = 0;
    int line_number = 1;

    printf("Enter the name of the file to read: ");
    scanf("%s", file_name);

    file = fopen(file_name, "r");

    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (num_lines > 0 && strcmp(line, "\n") == 0) {
            line_number++;
            num_lines--;
        } else if (num_lines > 0) {
            printf("Error: file contains more than %d lines.\n", num_lines);
            exit(1);
        } else {
            num_lines++;
        }
    }

    if (num_lines == 0) {
        printf("Error: file is empty.\n");
        exit(1);
    }

    fclose(file);

    printf("Printing the first %d lines of the file:\n", num_lines);

    print_file_lines(file_name, num_lines);

    return 0;
}