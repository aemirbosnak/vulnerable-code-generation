//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: calm
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FILE_NAME 256

// Function to open file and check for errors
FILE* open_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    return file;
}

// Function to read file line by line
char* read_line(FILE* file) {
    char* line = malloc(MAX_LINE_LENGTH);
    fgets(line, MAX_LINE_LENGTH, file);
    return line;
}

// Function to write to new file
void write_to_file(FILE* output, const char* line) {
    fprintf(output, "%s", line);
}

// Function to indent line
void indent_line(char* line, int level) {
    int i;
    for (i = 0; i < level * 4; i++) {
        strcat(line, " ");
    }
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        exit(1);
    }

    char input_filename[MAX_FILE_NAME];
    strcpy(input_filename, argv[1]);

    char output_filename[MAX_FILE_NAME];
    strcpy(output_filename, argv[2]);

    FILE* input_file = open_file(input_filename);
    FILE* output_file = fopen(output_filename, "w");

    int level = 0;
    char* line = read_line(input_file);
    while (line!= NULL) {
        if (strstr(line, "<html")!= NULL) {
            level++;
        } else if (strstr(line, "</html")!= NULL) {
            level--;
        }
        indent_line(line, level);
        write_to_file(output_file, line);
        line = read_line(input_file);
    }

    fclose(input_file);
    fclose(output_file);

    printf("HTML file beautified successfully!\n");
    return 0;
}