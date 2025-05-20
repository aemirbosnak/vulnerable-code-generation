//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

// Function to read a line from the CSV file
char* read_line(FILE* file) {
    char* line = (char*) malloc(MAX_LINE_SIZE);
    if (line == NULL) {
        printf("Error: Out of memory.\n");
        exit(1);
    }

    if (fgets(line, MAX_LINE_SIZE, file) == NULL) {
        printf("Error: End of file reached before end of line.\n");
        exit(2);
    }

    return line;
}

// Function to split a line into fields
char** split_line(char* line) {
    int num_fields = 0;
    char** fields = NULL;

    char* field = strtok(line, ",");
    while (field!= NULL) {
        num_fields++;
        fields = (char**) realloc(fields, sizeof(char*) * num_fields);
        if (fields == NULL) {
            printf("Error: Out of memory.\n");
            exit(3);
        }
        fields[num_fields - 1] = field;
        field = strtok(NULL, ",");
    }

    return fields;
}

// Function to print the fields of a line
void print_fields(char** fields, int num_fields) {
    for (int i = 0; i < num_fields; i++) {
        printf("%s ", fields[i]);
    }
    printf("\n");
}

// Function to read and print the CSV file
void read_csv_file(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'.\n", filename);
        exit(4);
    }

    char* line = read_line(file);
    while (line!= NULL) {
        char** fields = split_line(line);
        print_fields(fields, strlen(fields) / sizeof(char*));
        line = read_line(file);
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s CSV_FILE\n", argv[0]);
        return 1;
    }

    read_csv_file(argv[1]);

    return 0;
}