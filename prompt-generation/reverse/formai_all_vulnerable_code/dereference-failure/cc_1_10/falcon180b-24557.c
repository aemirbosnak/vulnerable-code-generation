//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100
#define MAX_FIELD_LENGTH 1024

typedef struct {
    char *data;
    size_t length;
} String;

typedef struct {
    int num_fields;
    String fields[MAX_FIELDS];
} Row;

typedef struct {
    FILE *file;
    char *filename;
    int num_rows;
    Row rows[MAX_FIELDS];
} CSVFile;

// Function to read a line from a file
String read_line(CSVFile *csv) {
    String line = {0, 0};
    char buffer[MAX_LINE_LENGTH];
    char *ptr = fgets(buffer, MAX_LINE_LENGTH, csv->file);
    if (ptr == NULL) {
        return line;
    }
    line.data = strdup(buffer);
    line.length = strlen(buffer);
    return line;
}

// Function to parse a line into fields
void parse_line(CSVFile *csv, String line) {
    int i = 0;
    char *ptr = line.data;
    while (i < MAX_FIELDS) {
        if (isalpha(*ptr)) {
            csv->rows[csv->num_rows].fields[i].data = ptr;
            csv->rows[csv->num_rows].fields[i].length = 0;
            while (isalpha(*(ptr++))) {
                csv->rows[csv->num_rows].fields[i].length++;
            }
            i++;
        } else {
            ptr++;
        }
    }
    csv->num_rows++;
}

// Function to open a CSV file
CSVFile *open_csv_file(const char *filename) {
    CSVFile *csv = malloc(sizeof(CSVFile));
    csv->filename = strdup(filename);
    csv->file = fopen(filename, "r");
    if (csv->file == NULL) {
        free(csv->filename);
        free(csv);
        return NULL;
    }
    csv->num_rows = 0;
    return csv;
}

// Function to close a CSV file
void close_csv_file(CSVFile *csv) {
    fclose(csv->file);
    free(csv->filename);
    free(csv);
}

// Function to print a CSV row
void print_row(Row row) {
    for (int i = 0; i < row.num_fields; i++) {
        printf("%s\t", row.fields[i].data);
    }
    printf("\n");
}

// Function to print all rows in a CSV file
void print_csv_file(CSVFile *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        print_row(csv->rows[i]);
    }
}

int main() {
    CSVFile *csv = open_csv_file("example.csv");
    if (csv == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    String line = read_line(csv);
    while (line.data!= NULL) {
        parse_line(csv, line);
        line = read_line(csv);
    }
    print_csv_file(csv);
    close_csv_file(csv);
    return 0;
}