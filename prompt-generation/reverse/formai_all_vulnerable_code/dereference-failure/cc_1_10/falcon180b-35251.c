//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to read a line from the file
char* read_line(FILE* file) {
    char* line = malloc(MAX_LINE_LENGTH * sizeof(char));
    if (line == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }
    fgets(line, MAX_LINE_LENGTH, file);
    return line;
}

// Function to parse a line into fields
char** parse_line(char* line, int* num_fields) {
    char* delimiter = ",";
    char** fields = malloc((*num_fields) * sizeof(char*));
    if (fields == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }
    char* token = strtok(line, delimiter);
    int i = 0;
    while (token!= NULL) {
        fields[i] = token;
        i++;
        token = strtok(NULL, delimiter);
    }
    *num_fields = i;
    return fields;
}

// Function to free memory allocated for fields
void free_fields(char** fields, int num_fields) {
    for (int i = 0; i < num_fields; i++) {
        free(fields[i]);
    }
    free(fields);
}

// Function to print fields
void print_fields(char** fields, int num_fields) {
    for (int i = 0; i < num_fields; i++) {
        printf("%s ", fields[i]);
    }
    printf("\n");
}

int main() {
    FILE* file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Error: File not found!\n");
        exit(1);
    }
    char* line = read_line(file);
    int num_fields = 0;
    char** fields = parse_line(line, &num_fields);
    while (fgetc(file)!= EOF) {
        line = read_line(file);
        fields = parse_line(line, &num_fields);
        print_fields(fields, num_fields);
    }
    free_fields(fields, num_fields);
    fclose(file);
    return 0;
}