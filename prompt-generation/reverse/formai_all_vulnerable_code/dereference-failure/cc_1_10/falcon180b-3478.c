//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of fields in a CSV row
#define MAX_FIELDS 100

// Define the struct to hold CSV data
typedef struct {
    char **fields; // Pointer to an array of strings
    int num_fields; // Number of fields in the row
} csv_row_t;

// Define the function to read a CSV file and return its data
csv_row_t *read_csv(const char *filename) {
    FILE *fp;
    char line[1024];
    csv_row_t *row;
    int num_fields = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    // Read the first row to determine the number of fields
    fgets(line, sizeof(line), fp);
    char *token = strtok(line, ",");
    while (token!= NULL) {
        num_fields++;
        token = strtok(NULL, ",");
    }

    // Allocate memory for the struct
    row = malloc(sizeof(csv_row_t));
    row->fields = malloc((num_fields + 1) * sizeof(char *));
    row->num_fields = num_fields;

    // Read the rest of the file and store the data in the struct
    rewind(fp);
    fgets(line, sizeof(line), fp);
    token = strtok(line, ",");
    int i = 0;
    while (token!= NULL) {
        row->fields[i] = strdup(token);
        i++;
        token = strtok(NULL, ",");
    }
    row->fields[i] = NULL;

    fclose(fp);
    return row;
}

// Define the function to print a CSV row
void print_csv_row(csv_row_t *row) {
    for (int i = 0; i < row->num_fields; i++) {
        printf("%s ", row->fields[i]);
    }
    printf("\n");
}

// Define the main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <csv_file>\n", argv[0]);
        exit(1);
    }

    csv_row_t *data = read_csv(argv[1]);
    print_csv_row(data);

    free(data->fields);
    free(data);
    return 0;
}