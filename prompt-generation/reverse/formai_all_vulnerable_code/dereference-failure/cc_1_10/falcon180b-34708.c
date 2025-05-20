//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 255

// Struct to hold CSV data
typedef struct {
    char **fields;
    int num_fields;
} CSVData;

// Function to read CSV file and return CSV data
CSVData read_csv_file(FILE *file) {
    CSVData csv_data = {NULL, 0};
    char line[MAX_LINE_LENGTH];
    char delimiter = ',';
    char *field;

    // Read first line to determine number of fields
    fgets(line, MAX_LINE_LENGTH, file);
    csv_data.num_fields = count_fields(line);
    csv_data.fields = malloc(csv_data.num_fields * sizeof(char*));

    // Read remaining lines and store in CSV data
    rewind(file);
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        field = strtok(line, ",");
        int field_index = 0;
        while (field!= NULL) {
            csv_data.fields[field_index] = strdup(field);
            field = strtok(NULL, ",");
            field_index++;
        }
    }

    return csv_data;
}

// Function to count number of fields in a line
int count_fields(char *line) {
    int count = 0;
    char *field = strtok(line, ",");
    while (field!= NULL) {
        count++;
        field = strtok(NULL, ",");
    }
    return count;
}

// Function to print CSV data
void print_csv_data(CSVData csv_data) {
    int i;
    for (i = 0; i < csv_data.num_fields; i++) {
        printf("%s\t", csv_data.fields[i]);
    }
    printf("\n");
}

// Function to free CSV data
void free_csv_data(CSVData csv_data) {
    int i;
    for (i = 0; i < csv_data.num_fields; i++) {
        free(csv_data.fields[i]);
    }
    free(csv_data.fields);
}

int main() {
    FILE *file = fopen("example.csv", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    CSVData csv_data = read_csv_file(file);
    if (csv_data.fields == NULL) {
        printf("Error reading CSV data\n");
        return 1;
    }

    print_csv_data(csv_data);

    free_csv_data(csv_data);
    fclose(file);

    return 0;
}