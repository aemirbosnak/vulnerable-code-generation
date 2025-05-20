//Falcon-180B DATASET v1.0 Category: Error handling ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *filename = "example.txt";
    char *delimiter = ",";
    int num_fields = 0;
    int i;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    // Count the number of fields in the first line
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        printf("Error reading file: %s\n", filename);
        exit(1);
    }
    num_fields = count_fields(line);

    // Read the rest of the file
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (process_line(line, num_fields, delimiter)!= 0) {
            printf("Error processing line: %s\n", line);
            exit(1);
        }
    }

    fclose(file);
    return 0;
}

int count_fields(char *line) {
    int count = 0;
    char *token = strtok(line, ",");
    while (token!= NULL) {
        count++;
        token = strtok(NULL, ",");
    }
    return count;
}

int process_line(char *line, int num_fields, char *delimiter) {
    char *token;
    int i;

    for (i = 0; i < num_fields; i++) {
        token = strtok(line, delimiter);
        if (token == NULL) {
            printf("Error: Missing field in line\n");
            return 1;
        }
        printf("Field %d: %s\n", i + 1, token);
    }

    return 0;
}