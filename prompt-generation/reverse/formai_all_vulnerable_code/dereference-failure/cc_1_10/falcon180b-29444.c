//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 1000
#define MAX_ROWS 1000
#define MAX_CELL_LENGTH 1000

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} csv_table;

csv_table *csv_read(FILE *fp) {
    csv_table *table = (csv_table *)malloc(sizeof(csv_table));
    table->num_rows = 0;
    table->num_cols = 0;
    table->data = (char **)malloc(sizeof(char *));

    char line[MAX_CELL_LENGTH];
    while (fgets(line, MAX_CELL_LENGTH, fp)!= NULL) {
        char *token = strtok(line, ",");
        int col_count = 0;
        while (token!= NULL) {
            if (col_count >= MAX_COLUMNS) {
                printf("Error: Maximum number of columns exceeded.\n");
                exit(1);
            }
            if (table->num_cols <= col_count) {
                table->num_cols = col_count + 1;
            }
            if (table->data[col_count] == NULL) {
                table->data[col_count] = (char *)malloc(sizeof(char));
            }
            strcat(table->data[col_count], token);
            strcat(table->data[col_count], ",");
            col_count++;
            token = strtok(NULL, ",");
        }
        table->num_rows++;
    }

    return table;
}

void csv_print(csv_table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            if (table->data[j]!= NULL) {
                printf("%s", table->data[j]);
            }
        }
        printf("\n");
    }
}

void csv_free(csv_table *table) {
    for (int i = 0; i < table->num_cols; i++) {
        if (table->data[i]!= NULL) {
            free(table->data[i]);
        }
    }
    free(table->data);
    free(table);
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    csv_table *table = csv_read(fp);
    csv_print(table);
    csv_free(table);
    fclose(fp);
    return 0;
}