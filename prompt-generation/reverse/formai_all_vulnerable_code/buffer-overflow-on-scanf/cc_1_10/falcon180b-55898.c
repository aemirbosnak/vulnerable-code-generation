//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_DATA_SIZE 100

typedef struct {
    char *header;
    int num_rows;
    int num_cols;
    char **data;
} Table;

void create_table(Table *table, char *filename) {
    FILE *fp = fopen(filename, "r");
    char line[MAX_DATA_SIZE];
    int row = 0;
    int col = 0;

    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    table->header = malloc(MAX_DATA_SIZE);
    table->num_rows = 0;
    table->num_cols = 0;
    table->data = malloc(MAX_ROWS * sizeof(char*));

    while (fgets(line, MAX_DATA_SIZE, fp)!= NULL) {
        if (row == 0) {
            strcpy(table->header, line);
            col = strlen(line);
        } else {
            char **data_row = realloc(table->data, (row + 1) * sizeof(char*));
            if (data_row == NULL) {
                printf("Error: Memory allocation failed.\n");
                exit(1);
            }
            table->data = data_row;

            int i;
            for (i = 0; i < col; i++) {
                if (line[i] == ',') {
                    line[i] = '\0';
                }
            }
            table->data[row] = malloc((strlen(line) + 1) * sizeof(char));
            strcpy(table->data[row], line);
            row++;
        }
    }

    fclose(fp);
}

void print_table(Table *table) {
    printf("%s\n", table->header);
    printf("+----+");

    int i;
    for (i = 0; i < table->num_cols; i++) {
        printf("----+");
    }

    printf("\n");

    int j;
    for (j = 0; j < table->num_rows; j++) {
        printf("| ");
        int k;
        for (k = 0; k < table->num_cols; k++) {
            printf("%s |", table->data[j][k]);
        }
        printf("\n");
    }
}

void delete_table(Table *table) {
    free(table->header);

    int i;
    for (i = 0; i < table->num_rows; i++) {
        free(table->data[i]);
    }
    free(table->data);
}

int main() {
    Table table;
    char filename[MAX_DATA_SIZE];

    printf("Enter the filename: ");
    scanf("%s", filename);

    create_table(&table, filename);
    print_table(&table);

    delete_table(&table);

    return 0;
}