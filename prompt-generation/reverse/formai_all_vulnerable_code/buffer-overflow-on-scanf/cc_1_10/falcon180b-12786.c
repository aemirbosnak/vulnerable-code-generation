//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_SIZE 1024
#define MAX_LINE_SIZE 1024

typedef struct {
    char filename[MAX_FILE_NAME_SIZE];
    char line[MAX_LINE_SIZE];
} file_line_t;

void read_file(const char* filename, file_line_t* lines, int max_lines) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        return;
    }

    int line_count = 0;
    while (fgets(lines[line_count].line, MAX_LINE_SIZE, file)!= NULL) {
        if (line_count >= max_lines - 1) {
            break;
        }
        line_count++;
    }

    fclose(file);
}

void write_file(const char* filename, const file_line_t* lines, int num_lines) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: could not create file %s\n", filename);
        return;
    }

    for (int i = 0; i < num_lines; i++) {
        fprintf(file, "%s\n", lines[i].line);
    }

    fclose(file);
}

int main() {
    int max_lines = 100;
    file_line_t lines[max_lines];

    char filename[MAX_FILE_NAME_SIZE];
    printf("Enter the name of the file to recover data from: ");
    scanf("%s", filename);

    read_file(filename, lines, max_lines);

    printf("\nData recovered from file:\n");
    for (int i = 0; i < max_lines; i++) {
        printf("%s", lines[i].line);
    }

    char output_filename[MAX_FILE_NAME_SIZE];
    printf("\nEnter the name of the file to save the recovered data to: ");
    scanf("%s", output_filename);

    write_file(output_filename, lines, max_lines);

    printf("\nData saved to file %s\n", output_filename);

    return 0;
}