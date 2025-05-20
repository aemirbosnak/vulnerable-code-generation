//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a line from the CSV file
char* read_line(FILE* fp) {
    char* buffer = NULL;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    // Read the line
    while ((read = getline(&line, &len, fp))!= -1) {
        if (line[read - 1] == '\n') {
            line[--read] = '\0';
        } else {
            buffer = realloc(buffer, len + 1);
            strcpy(buffer, line);
            line = buffer;
        }
    }

    return line;
}

// Function to split a line into fields
char** split_line(char* line) {
    char* field = NULL;
    char** fields = NULL;
    int count = 0;

    // Count the number of fields
    while (*line!= '\0') {
        if (*line == ',') {
            count++;
        }
        line++;
    }

    // Allocate memory for the fields array
    fields = malloc(sizeof(char*) * (count + 1));

    // Split the line into fields
    field = strtok(line, ",");
    while (field!= NULL) {
        fields[count] = strdup(field);
        field = strtok(NULL, ",");
        count++;
    }
    fields[count] = NULL;

    return fields;
}

// Function to print the fields of a line
void print_line(char** fields) {
    int i;

    for (i = 0; fields[i]!= NULL; i++) {
        printf("%s ", fields[i]);
    }
    printf("\n");
}

// Function to read and print the contents of a CSV file
void read_csv_file(char* filename) {
    FILE* fp;
    char* line;
    char** fields;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    while ((line = read_line(fp))!= NULL) {
        fields = split_line(line);
        print_line(fields);
        free(line);
        free(fields);
    }

    fclose(fp);
}

// Main function
int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    read_csv_file(argv[1]);

    return 0;
}