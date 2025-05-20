//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_FIELDS 1000

// Function to split a line into fields based on comma delimiter
char **split_line(char *line) {
    int num_fields = 0;
    char **fields = NULL;
    char *token;

    // Count the number of fields
    char *ptr = strtok(line, ",");
    while (ptr!= NULL) {
        num_fields++;
        ptr = strtok(NULL, ",");
    }

    // Allocate memory for the fields array
    fields = (char **) malloc((num_fields + 1) * sizeof(char *));
    if (fields == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }

    // Split the line into fields
    ptr = strtok(line, ",");
    for (int i = 0; i < num_fields; i++) {
        fields[i] = ptr;
        ptr = strtok(NULL, ",");
    }
    fields[num_fields] = NULL;

    return fields;
}

// Function to read a CSV file and print its contents
void read_csv_file(FILE *fp) {
    char line[MAX_LINE_LENGTH];
    char **fields;

    // Read each line of the file
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        // Split the line into fields
        fields = split_line(line);

        // Print the fields
        for (int i = 0; fields[i]!= NULL; i++) {
            printf("%s ", fields[i]);
        }
        printf("\n");

        // Free memory allocated for fields array
        for (int i = 0; fields[i]!= NULL; i++) {
            free(fields[i]);
        }
        free(fields);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    read_csv_file(fp);

    fclose(fp);
    return 0;
}