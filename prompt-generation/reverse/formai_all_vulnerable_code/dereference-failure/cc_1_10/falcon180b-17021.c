//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

typedef struct {
    char **fields;
    int num_fields;
} CSVRow;

CSVRow *read_csv(FILE *csv_file) {
    CSVRow *row = malloc(sizeof(CSVRow));
    row->fields = NULL;
    row->num_fields = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, csv_file)!= NULL) {
        char *token = strtok(line, ",");
        while (token!= NULL) {
            if (row->num_fields >= MAX_FIELDS) {
                printf("Error: CSV row has too many fields.\n");
                exit(1);
            }
            row->fields = realloc(row->fields, sizeof(char *) * ++row->num_fields);
            row->fields[row->num_fields - 1] = strdup(token);
            token = strtok(NULL, ",");
        }
    }
    return row;
}

void print_csv_row(CSVRow *row) {
    for (int i = 0; i < row->num_fields; i++) {
        printf("%s ", row->fields[i]);
    }
    printf("\n");
}

void free_csv_row(CSVRow *row) {
    for (int i = 0; i < row->num_fields; i++) {
        free(row->fields[i]);
    }
    free(row->fields);
    free(row);
}

int main() {
    FILE *csv_file;
    csv_file = fopen("example.csv", "r");
    if (csv_file == NULL) {
        printf("Error: Could not open CSV file.\n");
        exit(1);
    }

    CSVRow *row;
    while ((row = read_csv(csv_file))!= NULL) {
        print_csv_row(row);
        free_csv_row(row);
    }

    fclose(csv_file);
    return 0;
}