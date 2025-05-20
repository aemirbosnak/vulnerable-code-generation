//Code Llama-13B DATASET v1.0 Category: Building a CSV Reader ; Style: optimized
// csv_reader.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_COLUMNS 100
#define MAX_ROWS 1000
#define CSV_DELIM ','

typedef struct {
    char** data;
    int num_rows;
    int num_cols;
} csv_table_t;

csv_table_t* csv_read(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    char line[MAX_ROWS];
    char* tok;
    csv_table_t* table = malloc(sizeof(csv_table_t));
    table->data = malloc(sizeof(char*) * MAX_ROWS);
    table->num_rows = 0;
    table->num_cols = 0;

    while (fgets(line, MAX_ROWS, file)) {
        tok = strtok(line, CSV_DELIM);
        while (tok != NULL) {
            table->data[table->num_rows][table->num_cols] = tok;
            tok = strtok(NULL, CSV_DELIM);
            table->num_cols++;
        }
        table->num_rows++;
    }

    return table;
}

void csv_print(csv_table_t* table) {
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            printf("%s ", table->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    csv_table_t* table = csv_read("example.csv");
    csv_print(table);
    return 0;
}