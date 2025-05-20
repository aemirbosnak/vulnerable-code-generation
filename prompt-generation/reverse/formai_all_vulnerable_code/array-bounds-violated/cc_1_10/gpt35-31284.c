//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_COLUMNS 100

typedef struct CSVRow {
    char columns[MAX_NUM_COLUMNS][MAX_LINE_LENGTH];
    int num_columns;
} CSVRow;

typedef struct CSVReader {
    FILE* f;
    char delimiter;
} CSVReader;

CSVReader* new_CSVReader(const char* filename, char delimiter) {
    CSVReader* reader = malloc(sizeof(CSVReader));
    if (!reader) {
        fprintf(stderr, "Error: Failed to allocate memory for CSVReader\n");
        return NULL;
    }
    reader->f = fopen(filename, "r");
    if (!reader->f) {
        fprintf(stderr, "Error: Failed to open CSV file\n");
        free(reader);
        return NULL;
    }
    reader->delimiter = delimiter;
    return reader;
}

void close_CSVReader(CSVReader* reader) {
    fclose(reader->f);
    free(reader);
}

CSVRow* read_next_row(CSVReader* reader) {
    char line[MAX_LINE_LENGTH];
    if (!fgets(line, MAX_LINE_LENGTH, reader->f)) {
        // End of file reached
        return NULL;
    }
    if (line[strlen(line) - 1] == '\n') {
        line[strlen(line) - 1] = '\0';  // Remove newline character
    }
    
    CSVRow* row = malloc(sizeof(CSVRow));
    if (!row) {
        fprintf(stderr, "Error: Failed to allocate memory for CSVRow\n");
        return NULL;
    }
    row->num_columns = 0;
    char* p = strtok(line, &(reader->delimiter));
    while (p) {
        if (row->num_columns >= MAX_NUM_COLUMNS) {
            fprintf(stderr, "Error: Too many columns in CSV row\n");
            free(row);
            return NULL;
        }
        strcpy(row->columns[row->num_columns], p);
        row->num_columns++;
        p = strtok(NULL, &(reader->delimiter));
    }
    return row;
}

int main() {
    CSVReader* reader = new_CSVReader("example.csv", ',');
    if (!reader) {
        return 1;
    }
    CSVRow* row;
    while ((row = read_next_row(reader))) {
        for (int i = 0; i < row->num_columns; i++) {
            printf("%s ", row->columns[i]);
        }
        printf("\n");
        free(row);
    }
    close_CSVReader(reader);
    return 0;
}