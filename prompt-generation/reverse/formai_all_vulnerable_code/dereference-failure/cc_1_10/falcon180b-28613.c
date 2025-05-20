//Falcon-180B DATASET v1.0 Category: File handling ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 256
#define MAX_FILE_NAME_SIZE 256
#define MAX_NUM_LINES 1000

typedef struct {
    char *file_name;
    char *line;
} file_line_t;

int main() {
    file_line_t *file_lines = malloc(MAX_NUM_LINES * sizeof(file_line_t));
    int num_lines = 0;
    char file_name[MAX_FILE_NAME_SIZE];
    char line[MAX_LINE_SIZE];
    FILE *file;

    printf("Enter file name: ");
    scanf("%s", file_name);

    file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", file_name);
        exit(1);
    }

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        if (num_lines >= MAX_NUM_LINES) {
            printf("Error: maximum number of lines reached\n");
            exit(1);
        }
        file_lines[num_lines].file_name = strdup(file_name);
        file_lines[num_lines].line = strdup(line);
        num_lines++;
    }

    fclose(file);

    printf("Enter search string: ");
    scanf("%s", line);

    num_lines = 0;
    for (int i = 0; i < MAX_NUM_LINES; i++) {
        if (strstr(file_lines[i].line, line)!= NULL) {
            printf("%s:%s\n", file_lines[i].file_name, file_lines[i].line);
            num_lines++;
        }
    }

    free(file_lines);

    return 0;
}