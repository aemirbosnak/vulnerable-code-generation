//Falcon2-11B DATASET v1.0 Category: Log analysis ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 100
#define MAX_NUM_LINES 10000

int main() {
    char line[MAX_LINE_LENGTH];
    char log_file[MAX_LINE_LENGTH];
    char shape[MAX_LINE_LENGTH];
    char* log_name;
    char* log_path;
    char* log_file_name;
    char* log_file_path;
    char* log_file_name_extension;
    char* log_file_path_extension;
    int num_lines;
    int num_shapes;
    int shape_index;
    int line_index;
    int shape_length;
    int max_shape_length;
    int max_line_length;
    int i;
    int j;
    int k;

    printf("Enter the path to the log file: ");
    fgets(log_file, MAX_LINE_LENGTH, stdin);
    log_file[strcspn(log_file, "\n")] = '\0';
    log_name = strtok(log_file, "/");
    log_path = strtok(NULL, "/");

    log_file_name = strtok(log_name, ".");
    log_file_path = strtok(log_path, ".");
    log_file_name_extension = strtok(NULL, ".");
    log_file_path_extension = strtok(NULL, ".");

    num_lines = 0;
    max_shape_length = 0;
    max_line_length = 0;
    for (i = 0; i < MAX_NUM_LINES; i++) {
        fgets(line, MAX_LINE_LENGTH, log_file);
        num_lines++;
        line_index = 0;
        while (line[line_index]!= '\0') {
            if (isalpha(line[line_index])) {
                shape[shape_index] = tolower(line[line_index]);
                shape_index++;
            }
            line_index++;
        }
        shape[shape_index] = '\0';
        shape_length = strlen(shape);
        if (shape_length > max_shape_length) {
            max_shape_length = shape_length;
        }
        if (strlen(line) > max_line_length) {
            max_line_length = strlen(line);
        }
    }

    printf("Number of lines in the log file: %d\n", num_lines);
    printf("Longest shape length: %d\n", max_shape_length);
    printf("Longest line length: %d\n", max_line_length);

    return 0;
}