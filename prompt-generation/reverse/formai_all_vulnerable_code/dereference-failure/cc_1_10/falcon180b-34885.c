//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

// Function to split a line into fields
char **split_line(char *line) {
    int num_fields = 0;
    char **fields = NULL;
    char *token;

    // Count the number of fields
    while ((token = strtok(line, ","))!= NULL) {
        num_fields++;
    }

    // Allocate memory for the fields
    fields = malloc(sizeof(char *) * num_fields);

    // Split the line into fields
    num_fields = 0;
    token = strtok(line, ",");
    while (token!= NULL) {
        fields[num_fields++] = token;
        token = strtok(NULL, ",");
    }

    return fields;
}

// Function to read a CSV file and print its contents
void read_csv_file(FILE *file) {
    char line[MAX_LINE_SIZE];
    char **fields;

    // Read each line of the file
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        // Split the line into fields
        fields = split_line(line);

        // Print the fields
        for (int i = 0; fields[i]!= NULL; i++) {
            printf("%s ", fields[i]);
        }
        printf("\n");

        // Free memory allocated for the fields
        for (int i = 0; fields[i]!= NULL; i++) {
            free(fields[i]);
        }
        free(fields);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", argv[1]);
        return 1;
    }

    read_csv_file(file);

    fclose(file);

    return 0;
}