//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 2048
#define MAX_COLUMNS 100
#define MAX_ROWS 1000

typedef struct {
    char **data;
    int num_columns;
    int num_rows;
} CSV;

void print_csv(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_columns; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }
}

CSV *read_csv(FILE *file) {
    CSV *csv = (CSV *) malloc(sizeof(CSV));
    csv->num_columns = 0;
    csv->num_rows = 0;
    csv->data = (char **) malloc(sizeof(char *) * MAX_COLUMNS);

    char line[MAX_LINE_LENGTH];
    char *token = NULL;
    int column_count = 0;
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        column_count = 0;
        token = strtok(line, ",");
        while (token!= NULL) {
            csv->data[csv->num_columns] = (char *) malloc(sizeof(char) * strlen(token) + 1);
            strcpy(csv->data[csv->num_columns], token);
            csv->num_columns++;
            token = strtok(NULL, ",");
            column_count++;
        }
        csv->num_rows++;
    }

    return csv;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    CSV *csv = read_csv(file);
    print_csv(csv);

    fclose(file);
    return 0;
}