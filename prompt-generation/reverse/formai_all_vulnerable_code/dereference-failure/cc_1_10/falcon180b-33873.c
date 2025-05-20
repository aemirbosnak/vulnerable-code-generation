//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FIELDS 100

// structure to store CSV data
typedef struct {
    char **fields;
    int num_fields;
} CSVData;

// function to split a line into fields
char **split_line(char *line) {
    int num_fields = 0;
    char **fields = NULL;
    char *token = strtok(line, ",");

    while (token!= NULL) {
        num_fields++;
        fields = realloc(fields, sizeof(char *) * num_fields);
        fields[num_fields - 1] = strdup(token);
        token = strtok(NULL, ",");
    }

    fields = realloc(fields, sizeof(char *) * num_fields);
    fields[num_fields - 1] = NULL;

    return fields;
}

// function to read a CSV file
CSVData *read_csv_file(FILE *file) {
    CSVData *data = NULL;
    char line[MAX_LINE_SIZE];
    char **fields;

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        fields = split_line(line);
        if (data == NULL) {
            data = malloc(sizeof(CSVData));
            data->fields = fields;
            data->num_fields = 0;
        } else {
            data->fields = realloc(data->fields, sizeof(char *) * (data->num_fields + 1));
            data->num_fields++;
            data->fields[data->num_fields - 1] = fields[0];
        }
    }

    return data;
}

// function to print CSV data
void print_csv_data(CSVData *data) {
    int i;

    for (i = 0; i < data->num_fields; i++) {
        printf("%s\t", data->fields[i]);
    }

    printf("\n");
}

// main function
int main(int argc, char *argv[]) {
    FILE *file;
    CSVData *data;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    data = read_csv_file(file);
    if (data == NULL) {
        printf("Error reading file.\n");
        return 1;
    }

    print_csv_data(data);

    free(data->fields);
    free(data);

    fclose(file);
    return 0;
}