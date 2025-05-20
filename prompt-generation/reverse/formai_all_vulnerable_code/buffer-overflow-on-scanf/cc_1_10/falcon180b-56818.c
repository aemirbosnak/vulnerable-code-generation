//Falcon-180B DATASET v1.0 Category: File handling ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FILE_NAME_LENGTH 512

// Function prototypes
void read_file(FILE* file, char** lines, int* num_lines);
void write_file(FILE* file, char** lines, int num_lines);
void reverse_lines(char** lines, int num_lines);

int main() {
    char file_name[MAX_FILE_NAME_LENGTH];
    printf("Enter the name of the file to read: ");
    scanf("%s", file_name);

    FILE* input_file = fopen(file_name, "r");
    if (input_file == NULL) {
        printf("Error: Could not open file for reading.\n");
        exit(1);
    }

    char** lines = NULL;
    int num_lines = 0;
    read_file(input_file, &lines, &num_lines);

    fclose(input_file);

    printf("Enter the name of the output file: ");
    scanf("%s", file_name);

    FILE* output_file = fopen(file_name, "w");
    if (output_file == NULL) {
        printf("Error: Could not open file for writing.\n");
        exit(1);
    }

    reverse_lines(lines, num_lines);
    write_file(output_file, lines, num_lines);

    fclose(output_file);

    for (int i = 0; i < num_lines; i++) {
        free(lines[i]);
    }
    free(lines);

    return 0;
}

void read_file(FILE* file, char** lines, int* num_lines) {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        *num_lines += 1;
        lines = realloc(lines, sizeof(char*) * (*num_lines));
        lines[*num_lines - 1] = strdup(line);
    }
}

void write_file(FILE* file, char** lines, int num_lines) {
    for (int i = num_lines - 1; i >= 0; i--) {
        fprintf(file, "%s", lines[i]);
    }
}

void reverse_lines(char** lines, int num_lines) {
    for (int i = 0; i < num_lines / 2; i++) {
        char* temp = lines[i];
        lines[i] = lines[num_lines - 1 - i];
        lines[num_lines - 1 - i] = temp;
    }
}