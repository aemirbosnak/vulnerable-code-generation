//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

// Function to read one line from the input file
char *read_line(FILE *file) {
    char *line = malloc(MAX_LINE_LENGTH);
    char *pos = line;

    while (fgets(pos, MAX_LINE_LENGTH, file)!= NULL) {
        if (pos[strlen(pos) - 1] == '\n') {
            *pos = '\0';
            break;
        }
        pos += strlen(pos);
    }

    return line;
}

// Function to split a line into fields based on a delimiter
int split_line(char *line, char delimiter, char **fields) {
    int num_fields = 0;
    char *pos = line;
    char *token;

    while ((token = strtok_r(pos, delimiter, &pos))!= NULL) {
        fields[num_fields++] = token;
    }

    return num_fields;
}

// Function to read one record from the input file
int read_record(FILE *file, char delimiter, char **fields) {
    char *line = read_line(file);
    int num_fields = split_line(line, delimiter, fields);

    free(line);
    return num_fields;
}

// Function to write one record to the output file
void write_record(FILE *file, int num_fields, char **fields) {
    for (int i = 0; i < num_fields; i++) {
        fprintf(file, "%s", fields[i]);
        if (i < num_fields - 1) {
            fprintf(file, ",");
        }
    }
    fprintf(file, "\n");
}

// Function to read all records from the input file and write them to the output file
void read_and_write_records(FILE *input_file, FILE *output_file, char delimiter) {
    char **fields = malloc(sizeof(char *) * 100);
    int num_fields;

    while ((num_fields = read_record(input_file, delimiter, fields)) > 0) {
        write_record(output_file, num_fields, fields);
    }

    free(fields);
}

int main() {
    FILE *input_file = fopen("input.csv", "r");
    FILE *output_file = fopen("output.csv", "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    char delimiter = ',';

    read_and_write_records(input_file, output_file, delimiter);

    fclose(input_file);
    fclose(output_file);

    return 0;
}